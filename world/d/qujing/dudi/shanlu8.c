// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

一条山路蜿蜿蜒蜒盘山而上，山路边杂草丛生野花生艳。杂草
后面露出奇石岩，爬着青藤绿蔓。远山蒙笼，云雾在远谷里起
伏飘散。

LONG);

  set("exits", ([
        "east"   : __DIR__"shanlu9",
        "southwest"   : __DIR__"shanlu10",
      ]));
  set("outdoors", __DIR__);

  setup();
}



