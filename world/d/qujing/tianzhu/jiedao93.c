// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ������������������Ǹ�ʽ�������̵�����ƹ�ҩ���ȵȣ�
Ӧ�о��С��廨���ŵ���������ٽ����𣬲�ʱ������������
��ߺ�����ӽ��ϴ�����

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao94",
        "west"   : __DIR__"jiedao92",
        "south"   : __DIR__"shoushi",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


