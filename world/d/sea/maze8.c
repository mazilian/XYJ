// cracked by vikee 2/09/2002   vikee@263.net
// under2.c

inherit ROOM;

void create ()
{
  set ("short", "����ç��");
  set ("long", @LONG

����ˮɫ��Ļ�����������Χ�ѿ���������ˡ�ż�а���Ϯ������
��������������Ĵ�����Щ�߸ߵĺ��ݣ����������ͷ���ڵ�һ˿
��âҲû���ˡ�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/beast3" : 4,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"maze"+sprintf("%d",random(10)),
  "north" : __DIR__"maze"+sprintf("%d",random(10)),
  "south" : __DIR__"maze"+sprintf("%d",random(10)),
  "west" : __DIR__"maze"+sprintf("%d",random(10)),
]));
//      
        set("water", 1);
//  
        setup();
}
