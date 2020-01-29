// cracked by vikee 2/09/2002   vikee@263.net
// yingwu-guai.c...weiqi, 97.09.15.
// drooler parts added by pickle 9-18-97

#include <ansi.h>
inherit NPC;

// from drooler file, some global variables

string *rnd_say = ({
	"我雪山派弟子各个神勇无比，天下无敌！",
	"「嘎～～嘎～～」",
	"杀入大雷音寺，抢了他的莲花宝座！",
	"你们都要好好练功！不要辜负了明王的一片苦心！",
	"大家好！",
});

varargs void drool(string msg, string who);

/************************************************************/
void create()
{
	set_name("鹦鹉将军", ({"yingwu jiangjun", "yingwu", "jiangjun"}));
	set("gender", "男性" );
	set("age", 23);
	set("per", 112);//no rongmao description.

	set("long", "雪山门下有名的高手之一鹦鹉将军。\n他远看还不错，走近了才发现他长着长长的一张鸟嘴。\n");
	set("class", "yaomo");
	set("combat_exp", 100000);
  set("daoxing", 50000);

	set("attitude", "peaceful");
	create_family("大雪山", 3, "弟子");
	set_skill("unarmed", 50);
	set_skill("yingzhaogong", 50);
	set_skill("cuixin-zhang", 60);
	set_skill("dodge", 50);
	set_skill("xiaoyaoyou", 80);
	set_skill("parry", 80);
	set_skill("blade", 60);
	set_skill("bingpo-blade", 80);
        set_skill("sword", 60);
        set_skill("bainiao-jian", 80);
	set_skill("force", 60);   
	set_skill("ningxie-force", 70);
	set_skill("literate", 80);
	set_skill("spells", 50);
	set_skill("dengxian-dafa", 50);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 700);
	set("max_sen", 600);
	set("force", 700);
	set("max_force", 700);
	set("mana", 700);
	set("max_mana", 700);	
	set("force_factor", 10);
	set("mana_factor", 15);

	// the following are from the drooler
	set("chat_chance", 30);
	set("chat_msg", ({
		(: drool :),
	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");

	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

/************************************************************/

// things involving the menpai: apprentice, ......

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="大雪山" ){
		if( (int)ob->query("family/generation") < 3  ){
			command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣大爷我了！\n");
		}
		else {
			command(":D");
			command("say 你这个" + RANK_D->query_rude(ob) + "早就该来拜我为师！你那个破师父什么都不懂...\n");
			command("recruit " + ob->query("id") );
                        ob->set("title", "大雪山护山小妖");
	                ob->set("class", "yaomo");
	}
	}

	else{
		command(":D ");
		command("say 好，到我们大雪山来学艺，又找了个好师父。" + RANK_D->query_respect(ob) + "可以说是前途无量啊！\n");
		command("recruit " + ob->query("id") );
                ob->set("title", "大雪山护山小妖");
                ob->set("class", "yaomo");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

/************************************************************/

// the following copies some functions of the drooler
// from /obj/example/drooler to allow the yingwu to
// repeat what a human says, as a 鹦鹉's nature is.

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "？", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "！", "");
	msg = replace_string(msg, "啊", "");
	msg = replace_string(msg, "吗", "");
	msg = replace_string(msg, "耶", "");
	msg = replace_string(msg, "吧", "");

	if( msg!="" ) {
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who, phrase;

	if( !userp(ob) ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
	case "kick":
		if( random(10)<5 ) {
			command("say 狗腿又发痒了...\n");
		}
		break;
	case "pat":
		if( random(10)<5 ) {
			command("say 不许拍！再拍你爷爷我把你的爪子剁下来！\n");
		}
		break;
	default:
		if( random(10)<5 )
			command(verb + " " + ob->query("id"));
		else
			drool();
	}
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) return;

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

	if( (strsrch(msg, "为什么") >= 0) ) {
		if( sscanf(msg, "%*s裁