// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat

inherit NPC;

void create()
{
  set_name("宫妃", ({"gong fei","girl"}));
  set("gender", "女性");
  set("combat_exp", 10000);
  set("age", 15);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);

  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
}


