// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("嫩炒肝尖", ({"gan jian", "ganjian", "gan", "jian"}));
  set_weight(600);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一刚刚炒出来的热菜。\n");
    set("unit", "盘");
    set("value", 400);
    set("food_remaining", 8);
    set("food_supply", 25);
  }
}

