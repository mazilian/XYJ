// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("八宝铜锤", ({ "hammer" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把沈重的铜锤，打造的相当坚实。没有千斤力气是拿不起的。\n");
                set("value", 1200);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(40);
        setup();
}

