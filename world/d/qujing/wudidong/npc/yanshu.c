// cracked by vikee 2/09/2002   vikee@263.net
// cook.c, created by mes
// updated 9-5-97 pickle

/************************************************************/

#include <ansi.h>
inherit NPC;

#define SYNTAX "指令格式：tellme [player_id] sell <id>\n"

int check_ratio(object me, object ob);
int do_tellme(string arg);
int do_giveme(string arg);
int manifest(string arg);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);
void give_baozi(object cook, object me, string OBNAME, int reward);

/************************************************************/

void create()
{
  set_name("鼹鼠精", ({"yan shu", "yanshu", "monster", "chu zi", "cook"}));
  set("long",
"他几经修练，终于成了人形。但因他天生眼睛就不好，洞里没人\n"
"喜欢他。若不是因为他蒸得好包子，早被玉鼠赶出去了。\n");
  set("title", "厨子");
  set("gender", "男性");
  set("per", 10);
  set("age", 25);
  set("str", 70);
  set("attitude", "peaceful");
  set("combat_exp", 2000);
  set("daoxing", 5000);

  set("inquiry", ([
		"name": "什么名字！我自己都不记得了！",
		"here": "这里是厨房，你看不出来？",
		"rumors" : "唉，那白毛老鼠又去抓了个和尚，还是得我来蒸！真烦！",
		"和尚": "找别人去问！",
		"人肉包子": "你不给我活人，我怎么蒸？！",
		]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

void init()
{
    add_action("do_sell", "sell");
    add_action("do_sell", "mai");
    if (wizardp(this_player()))
    {
	add_action("do_tellme", "tellme");
	add_action("do_giveme", "giveme");
	add_action("do_manifest", "manifest");
    }
}

/************************************************************/

int do_sell(string arg)
{
  object me=this_player(),ob;
  int baoziexp, pot, sell_delay;
  int myscore, ratio, base_reward, reward, pot_reward;
  object cook=this_object(), baozi;
  int no_pk;
  

  if (!arg) return notify_fail("你要卖什么？\n");
  if(me->is_busy()) return notify_fail("你正忙着呢。\n");
  if(is_busy()) return notify_fail("对方正忙着呢。\n");
  if(query_temp("processing"))
    return notify_fail(CYN"鼹鼠精怒道：没看我正忙着蒸包子呢嘛！？\n"NOR);
  if(environment(cook)!=find_object("/d/qujing/wudidong/kitchen.c"))
    return notify_fail(CYN"鼹鼠精摇头道：这里不是我的厨房，你就算把原料给了我我也没法做成包子。\n"NOR);
  if (me->query("family/family_name") != "陷空山无底洞")
      return notify_fail(CYN"鼹鼠精仔细打量了你几眼，道：你是哪儿来的？我怎么不认得你？\n" NOR);
  ob=present(arg, me);
  if (!ob || !objectp(ob))
      return notify_fail("你没有这样 "+arg+"。\n");
  if (!ob->is_character())
      return notify_fail(CYN "鼹鼠精摇了摇头，说道：这儿是厨房，不是废品回收站。\n" NOR);
  if (me->query("wudidong/sell_allowed")> time())
      return notify_fail(CYN"鼹鼠怒道：你怎么刚去就又来了！？肯定是路边捡的！我老远就闻到一股恶臭！\n"NOR);
  if (ob->query("race") != "人类")
      return notify_fail(CYN"鼹鼠精骂道：浑帐！叫你去弄人肉来，这是人吗！？\n"NOR);
  baoziexp=ob->query("combat_exp")+ob->query("daoxing");// baoziexp 是被卖者的强度。
  no_pk=me->query_condition("no_pk_time");
  if (userp(ob) && (baoziexp<5000 || no_pk>480) )
      return notify_fail(CYN "鼹鼠精摇了摇头，说道：这肉不新鲜，我不要。\n" NOR);
  if (ob->query_temp("last_fainted_from") &&
	  ob->query_temp("last_fainted_from")!=me->query("id"))
      return notify_fail(CYN"鼹鼠精皱了皱眉，道：这是你哪里捡来的？怎么都臭了？\n");
  message_vision("$N将晕倒了的$n交给厨子。\n", me, ob);
  message_vision(CYN "$N笑眯眯地凑到$n身边，道：我一看就知道你肯定有货。\n"NOR, cook,me);
  message_vision(CYN"$N：以后再有就赶紧送来，肯定不会亏了你的！\n"NOR, cook);
  ratio=check_ratio(me, ob);
  base_reward=check_base_reward(ob, ratio);
  reward = base_reward * ratio/100+1;

	if( reward>1000 ) reward=800+random(200);

//  if(ratio>10 || userp(ob))
//   pot_reward = 20+random(60);

  pot_reward = (10+random(10))*ratio/50 +random(2);
    //mon reduced pots per gain. 11/24/97
    //ratio is from 0 to 100.

  set("pot_monitor/"+me->query("name")+"("+me->query("id")+")/"+time(),
	me->query("potential"));
  if (userp(ob)) pot_reward*=2;
// the rewarding is now done with the actual baozi to make the
// story make sense, and also put further time guard on the
// player, so that he cannot always eat baozi. :P check with pickle
// if you have any questions.
//  me->add("wudidong/sell_reward", reward);
//  me->add("combat_exp", reward);
  pot=me->query("potential")-me->query("learned_points");

  log_file("npc_kill","["+ctime(time())+"] "+me->query("id")
   +" got "+pot_reward+" pots by selling.("+
   me->query("combat_exp")+" sell "+ob->query("combat_exp")+")\n");
  CHANNEL_D->do_channel(this_object(), "sys",me->query("id")
   +" got "+pot_reward+" pots by selling.("+
   me->query("combat_exp")+" sell "+ob->query("combat_exp")+")");

  if(pot+pot_reward<=200)
    me->add("potential", pot_reward);
  else if (pot<200) me->set("potential", 200+me->query("learned_points"));
  me->set("wudidong/last_sold", ob->query("id"));
  me->add("wudidong/sell_count", 1);
  me->set("wudidong/sell_time", time());
	// will not be allowed to sell again until the time indicated in the
	// following variable. for the meaning of random(reward*36/15) please
	// talk to pickle, don't get upset yet. this basically allows the top
	// selling speed to be 3 yrs / hour, and then the rest the player can
	// gain from fighting. 36 is the number of seconds in an hour, 3600/100
	// where as 15 is the daoxing. the average of the above formula is
	// reward * 3600 / 3000, so for each 3 yrs daoxing a player gains from
	// selling he has to wait an hour to sell the next victim.
  sell_delay=random(reward*36/15);
  if(sell_delay<60) sell_delay=60;
  if (!wizardp(me) || !me->query("env/override"))
    me->set("wudidong/sell_allowed", time()+sell_delay);
  ob->set("wudidong/last_sold_by", me->query("id"));
  ob->add("wudidong/sold_count", 1);
  me->add_temp("wudidong/received_renroubao", 1);
  message_vision(CYN"$N对$n道：稍等一会，我马上就蒸。\n"NOR, cook, me);
  call_out("give_baozi", 15+random(20), cook, me, ob->query("name"), reward);
  set_temp("processing", 1);
  if (userp(ob))
  {
      // since sell a player will also result in victim's
      // force, mana and daoxing lose, so apply the same
      // no_pk condition as PK.
      me->apply_condition("no_pk_time",no_pk+240);

      remove_call_out("revive");
      message_vision(CYN"$N高兴地说道：嘿，这个特新鲜，直接蒸了吧！\n"NOR, cook);
      message_vision("$N将$n扔进了蒸笼。\n", cook,ob);
      CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s