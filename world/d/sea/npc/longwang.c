// cracked by vikee 2/09/2002   vikee@263.net
//modified by sgzl for dntg/donghai quest
#include <skill.h>

inherit NPC;
inherit F_MASTER;

string expell_me(object me);
int donghai_quest(object who);

void create()
{
       	set_name("敖广", ({"ao guang", "ao","guang","longwang","wang"}));

	set("long","敖广是东海的龙王，其兄弟分别掌管东，西，南，北四海。
由余其水族众多，声势浩大，俨然独霸一方。\n");
       	set("gender", "男性");
       	set("age", 66);
	set("title", "东海龙王");
	set("class","dragon");
       	set("attitude", "peaceful");
       	set("shen_type", 1);
        set("combat_exp", 1260000);
        set("daoxing", 1500000);

        set("rank_info/respect", "陛下");
       	set("per", 20);
       	set("str", 30);
       	set("max_kee", 3000);
       	set("max_gin", 400);
       	set("max_sen", 1500);
       	set("force", 3000);
       	set("max_force", 1500);
       	set("force_factor", 120);
       	set("max_mana", 800);
       	set("mana", 1600);
       	set("mana_factor", 40);
       	set("combat_exp", 1200000);
        set("daoxing", 1500000);

	set_skill("huntian-hammer", 180);
	set_skill("hammer", 180);
	set_skill("literate", 100);
       	set_skill("unarmed", 200);
       	set_skill("dodge", 180);
       	set_skill("force", 180);
       	set_skill("parry", 180);
       	set_skill("fork", 180);
       	set_skill("spells", 170);
	set_skill("seashentong", 170);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 180);
	set_skill("fengbo-cha", 180);
	set_skill("dragonstep", 180);
	map_skill("hammer", "huntian-hammer");
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "fengbo-cha");
	map_skill("parry", "fengbo-cha");
	map_skill("dodge", "dragonstep");

        set("inquiry", ([ 
           "离宫": (: expell_me :),
	   "leave": (: expell_me :), 
           "兵器": (: donghai_quest :),
           "weapon": (: donghai_quest :), 
        ]) );

        create_family("东海龙宫", 1, "水族");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

        carry_object("/d/sea/obj/longpao")->wear();
}
void init()
{
	::init();
	add_action("do_agree", "agree");
	add_action("do_learn", "xuexi");
}


void destroy(object ob)
{
        destruct(ob);
        return;
}

void unsetlearn(object ob)
{
	if (find_player(ob->query("id"))) {
		ob->set_temp("temp/learn", 0);
		ob->save();
		}
}


string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

int do_learn(string arg)
{
	string skill, teacher, master;
	object me= this_player(), ob;
	int master_skill, my_skill, sen_cost;

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("指令格式：xuexi <技能> from <某人>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯．．．你得先把" + ob->name() + "弄醒再说。\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if (skill != "unarmed" || !me->query_temp("temp/learn") ) 
		return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

	notify_fail(ob->name() + "不愿意教你这项技能。\n");
	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	sen_cost = 250 / (int)me->query_int();

	if( !my_skill ) {
		sen_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	printf("你向%s虢逃泄亍