// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����ˮ��ܿ���һ����ȥ��ԶԶ���Լ�����Լ�Ķ԰�����
���ǰ��ϵ����֣������Ǻ��棬�ѽ��˺��ı��㣬������
�ش��ţ�����żȻ�ɼ����˻����ߡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"hexi1",
        "south"   : __DIR__"hexi3",
        "northwest" : __DIR__"xiaolu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}


