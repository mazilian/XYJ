// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("chechi_jiu_bao");
  set_name("酒保", ({"jiu bao", "jiubao", "bao"}));
  set("shop_id", ({"jiubao", "jiu bao", "bao"}));
  set("gender", "男性");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "roujiamo": "/d/qujing/chechi/obj/roujia",
        "niurou": "/d/qujing/chechi/obj/niurou",
        "niubaiye": "/d/qujing/chechi/obj/baiye",
        "jiuhu": "/d/qujing/chechi/obj/jiuhu",
      ]) );

  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", 10);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

