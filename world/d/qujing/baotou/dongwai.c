// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ����һƬ�㳡�����������������������һ���ڣ���ɭɭ��
֪��ʲôȥ���������ɽ���ϳ�����̦�£��Ĵ����ͣ�����
����·�ļ���

LONG);

  set("exits", ([
        "northwest"   : __DIR__"hukou",
      ]));
set("no_mieyao",1);
  set("outdoors", __DIR__);

  setup();
}


