// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "祭赛国西门");
  set ("long", @LONG

这里就到了祭赛国的西门，道路非常的宽广，足可容得下十马并
驰。笔直的土路直通向城中，乘马和徒步赶路的人来往不绝，可
见城中之繁华。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guard" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pingxi",
  "east" : __DIR__"crosswest",
]));

  setup();
}

