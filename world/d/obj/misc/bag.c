// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;

void create()
{
        set_name("布袋", ({ "bag" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "这是一口寻常的布袋，可以用来装一些杂物。\n");
                set("value", 50);
        }
}

int is_container() { return 1; }

