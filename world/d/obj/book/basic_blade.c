// cracked by vikee 2/09/2002   vikee@263.net
// literate.c

inherit ITEM;

void create()
{
        set_name("〖刀法入门〗", ({"blade book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "blade",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 20,
]) );
        }
}

