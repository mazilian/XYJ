// cracked by vikee 2/09/2002   vikee@263.net
// shoupi.c

#include <armor.h>

inherit HEAD;

void create()
{
        set_name("头盔", ({"head"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "个");
		set("armor_prop/armor", 1);
        }
        setup();
}

