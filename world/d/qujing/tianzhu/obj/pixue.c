// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "水牛皮靴", ({ "shuiniu pixue", "pixue", "xue" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "一双长筒水牛皮靴。\n");
    set("value", 650);
    set("material", "boots");
    set("armor_prop/dodge", 5);
  }
  setup();
}

