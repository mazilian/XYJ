// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "Σ�¹�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
������֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"xianwudian",
  "north"     : __DIR__"niujingong",
  "northeast" : __DIR__"shihuogong",
  "northwest" : __DIR__"bishuigong",

]));
set("no_fight", 1);
set("no_magic", 1);


  set("objects", 
      ([
	__DIR__"stars/6": 1,
      ]));


  setup();
}
 