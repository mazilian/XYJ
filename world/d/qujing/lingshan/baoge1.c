// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������㰸������ÿ���㰸���н�����¯��ֻ��������������
�����ƣ�����һ������ؽ����ơ�������һ����ͨ����۱�
�¥��Ϊ����ؾ�����

LONG);

  set("exits", ([
        "up"   : __DIR__"baoge2",
        "west"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/randeng" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}
