// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit MACE;

void create()
{
  set_name("刺槐锏", ({ "cihuai jian", "jian", "mace" }) );
  init_mace(25);
  set("unit", "根");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 240);
    set("material", "wood");
  }
  setup();
}

