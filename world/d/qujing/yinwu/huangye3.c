// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "荒野");
  set ("long", @LONG

荒野四处辽阔，远方可见群山峻岭峭壁，近处有小路进出大小
森林树木。风吹过洒洒之声不断，流水潺潺，时闻苍狼嗥叫，
时闻饿虎咆哮。

LONG);

  set("exits", ([
        "west"    : __DIR__"huangye2",
        "east"    : __DIR__"huangye4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

