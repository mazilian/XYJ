// cracked by vikee 2/09/2002   vikee@263.net

inherit NPC;
void create()
{

  set_name("姚公麟", ({ "yao gonglin", "yao", "taiwei" }) );
  set("gender", "男性" );
  set("long", "姚公麟是梅山七兄弟中的老六。\n");
  set("title", "梅山太尉");
  set("age", 35);
  set("attitude", "peaceful");
  set("str", 25);
  set("int", 25);
  set("combat_exp",540000);
  set("force",800);
  set("max_force",800);
  set("force_factor", 20);
  set("max_kee", 900);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",109);
  set_skill("dodge",90);
  set_skill("parry", 90);
  set_skill("mace",90);
  set_skill("force",90);
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/mace/copperjian")->wield();
}

