// cracked by vikee 2/09/2002   vikee@263.net

inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "床上");
        set("long", @LONG

LONG
        );
        
        set("exits", ([
                "out": "/d/moon/wroom",
            ]));
	set("no_fight", 1);
	set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}

