// cracked by vikee 2/09/2002   vikee@263.net
// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("兵服", ({"bingfu", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
		set("value", 300);
                set("unit", "件");
                set("armor_prop/armor", 15);
        }
        setup();
}

