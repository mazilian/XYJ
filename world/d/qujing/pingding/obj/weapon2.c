// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("花竺剑", ({ "huazhu jian", "jian", "sword" }) );
  init_sword(35);
  set("unit", "把");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "iron");
  }
  setup();
}

