// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("上官曲岸", ({"shangguan quan", "quan"}));
  set("gender", "男性");
  set("age", 30);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 20000);
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",12);
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

