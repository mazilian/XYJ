// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "寺殿");
  set ("long", @LONG

寺殿里云霞迷漫仙气非凡，殿檐上金铃银铃串串随煦风微晃叮
当脆响，殿内一片光明紫气缭绕。殿侧回廊里不时从附近传来
阵阵诵经的声音。

LONG);

  set("exits", ([
        "west"   : __DIR__"sidian61",
        "east"   : __DIR__"sidian63",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 1,
     ]));

  setup();
}

