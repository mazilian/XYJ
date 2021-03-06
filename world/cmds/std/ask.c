// cracked by vikee 2/09/2002   vikee@263.net
// ask.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n疑惑地看着$N，摇了摇头。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯．．．这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;
	int dt_ask_valid;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语．．．\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic 
			+ "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}

	// by snowcat jan 23 1998
	if ( msg = QUEST->quest_ask (me, ob, topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	}

	if( userp(ob) ) return 1;

	dt_ask_valid = me->query("ask_ex/"+ob->query("id")+"/"+topic);
	if(dt_ask_valid && time() < dt_ask_valid)
	{
		message_vision( HIW+"有话慢慢说，心急吃不了热豆腐\n"+NOR, me);
		return 1;
	}
	if(me->query("ask_ex"))
		me->delete("ask_ex");
	me->set_temp("ask_ex/"+ob->query("id")+"/"+topic, time()+3);
	
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
