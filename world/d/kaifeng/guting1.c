// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "古亭道");
  set ("long", @LONG

古亭道宽丈许，地上铺满碎大大小小的石子，飘满红黄落叶。道路的
两边是成排的树，风吹过沙沙作响。道路的南边通向开封市区，北面
可见一宫殿。

LONG);

  set("exits", ([
        "northup" : __DIR__"wanshou",
        "west" : __DIR__"xihu4",
        "east" : __DIR__"donghu3",
        "south" : __DIR__"guting2",
      ]));

  set("outdoors", __DIR__);

  setup();
}


