// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("索哈娜", ({"suo hana", "hana", "boss"}));
  set("gender", "女性");
  set("combat_exp", 4000);
  set("age", 30);
  set("per", 19);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 20);
  set_skill("dodge", 60);

  setup();
  carry_object("/d/obj/cloth/p_cloth")->wear();
}

