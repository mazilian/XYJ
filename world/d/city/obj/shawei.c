// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("杀威大棒", ({"shawei bang", "bang"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 200);
                set("material", "wood");
             }
        init_stick(25);
        setup();
}

