// zong guan 


#include <ansi.h>

inherit NPC;

void create()
{
        set_name(""HIC"框框"NOR"", ({"zong guan", "null"}));
        set("long", "他是发送装备的总管框框,你可以(list)查看想要的东西。\n");
	set("gender", "男性");
	set("age", 20);
	set("per", 40);
        set("title",""HIG"西游记装备总管"NOR);
	set_skill("literate", 141);
	set("chat_chance",5);
    set("chat_msg", ({
        "框框轻声告诉你：你可以用list指令列出想要的东西！\n",
        "框框轻声告诉你：你可以用yao指令向总管我索取装备。\n",
        "框框很神气的说：我就是总管，总管就是我！\n",               
        }));
	setup();
	carry_object("/d/obj/cloth/magua")->wear();
}

void init()
{
	::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
	message_vision("$N看样子想打架，但框框很有涵养,不和$N动粗。\n",who,me);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N看样子想杀死框框，但框框是文化人,没跟$N一般见识。\n",who,me);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N对着框框结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);

  return 1;
}


int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想偷东西，但总是有贼心没贼胆。\n",who,me);

  return 1;
}


int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想对框框祭法宝，前思后想，还是没敢。\n",who,me);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N掏出暗器，看了看框框，信心不足，又把暗器收了起来。\n",who,me);

  return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
  message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"盔甲："HIC"
          1.金甲(armor)      2. 披风(pifeng)    3.盾牌(shield)
          4.铁盔(kui)        5. 战袍(cloth)     6.踏云靴(shoes)
          7.天师法冠(bonnet)
          \n"HIY"兵器："HIC" 
           1.降魔棒(stick)    2.青虹剑(sword)    3.软龙筋(whip)
           4.金刀(blade)      5.短铁爪(zhua)     6.黄铜禅杖(staff)
           7.宣花斧(axe)      8.月牙铲(fork)     9.梅花锤(hammer)
          10.点金枪(spear)   11.凤凰琴(qin)     12 虎尾鞭 (mace)
          13.龙头拐杖(guai)  14.金丹沙(sha)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);

  return 1;
}

int do_yao(string arg)
{
	string type;
	object ob;
	object who=this_player();
	object me=this_object();
/*
	if (who->query("combat_exp")>500000)
		return notify_fail("凭您的功夫，还是自己去打装备吧! :P\n");
*/
    if (!arg)
		return notify_fail("你想要什么？兵器？还是盔甲？(比如:yao sword)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//盔甲
			case "armor":
				ob=new("/d/city/npc/obj_ex/armor.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "pifeng":
				ob=new("/d/city/npc/obj_ex/pifeng.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shield":
				ob=new("/d/city/npc/obj_ex/shield.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shoes":
				ob=new("/d/city/npc/obj_ex/shoes.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "cloth":
				ob=new("/d/city/npc/obj_ex/cloth.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "kui":
				ob=new("/d/city/npc/obj_ex/kui.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "bonnet":
				ob=new("/d/city/npc/obj_ex/faguan.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
				//兵器
			case "sword":
				ob=new("/d/city/npc/obj_ex/sword.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "whip":
				ob=new("/d/city/npc/obj_ex/whip.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "blade":
				ob=new("/d/city/npc/obj_ex/blade.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "stick":
				ob=new("/d/city/npc/obj_ex/stick.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
                        case "spear":
                                ob=new("/d/city/npc/obj_ex/spear.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "fork":
				ob=new("/d/city/npc/obj_ex/fork.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "hammer":
				ob=new("/d/city/npc/obj_ex/hammer.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
                          case "qin":
                                  ob=new("/d/city/npc/obj_ex/qin.c");
                                  ob->set("no_sell", 1);
                                  ob->set("no_drop", 1);
                                  ob->set("no_give", 1);
                                  ob->move(who);
tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                  break;
			case "axe":
				ob=new("/d/city/npc/obj_ex/axe.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "staff":
				ob=new("/d/city/npc/obj_ex/staff.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zhua":
				ob=new("/d/city/npc/obj_ex/zhua.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;           
            case "mace":
				ob=new("/d/city/npc/obj_ex/mace.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;           
            case "guai":
				ob=new("/d/city/npc/obj_ex/guai.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;           
            case "sha":
				ob=new("/d/city/npc/obj_ex/jindan.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"框框把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;           
			}
	}
return 1;

}
