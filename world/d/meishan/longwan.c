// cracked by vikee 2/09/2002   vikee@263.net

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�཭ˮ����������ң��ˮ��һƬ��ã������С����������ֻҰ
Ѽ����ˮ�����������������м�ʮ����ľ׮�Ӵ�ɵĶɿڣ���
�ѷ������á�
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/kang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"sengquan",
]));

  setup();
}
