// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������һƬ��ڣ�ͷ�������������������ס�˹��ߣ������ѱ�
�����ϱ�����紵������������������ȴ�������˷�����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"songlin1",
  "northwest" : __DIR__"songlin4",
  "southwest" : __DIR__"songlin1",
  "southeast" : __DIR__"songlin4",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/shanyao" : 1,
]));



  setup();
}
