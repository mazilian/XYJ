// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "罗汉塔");
  set ("long", @LONG


			佛


LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luohan4" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"luohane7",
  "northdown":__DIR__"luohane5",
]));
  setup();
}
int valid_leave(object me, string dir)
{

        if( (string)me->query("family/family_name")=="南海普陀山" ) return 1;
        if( wizardp(me)) return 1;


        if (dir == "eastup") {
        if (objectp(present("luo han", environment(me))))

        return notify_fail("罗汉伸手挡住了你的去路。\n");
        }   
        return ::valid_leave(me, dir);
}


