// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat 11/22/1997

#include <armor.h>

inherit FINGER;

void create()
{
  set_name("紫金戒指", ({ "zijin jiezhi", "jiezhi", "ring" }));
  set("weight", 100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("value", 1000);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}
