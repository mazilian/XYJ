// cracked by vikee 2/09/2002   vikee@263.net
// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("紫色小褂", ({"purple cloth", "cloth"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 100);
		set("armor_prop/armor", 5);

        }
        setup();
}

