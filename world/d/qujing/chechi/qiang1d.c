// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang1d.c

inherit ROOM;

void create ()
{
  set ("short", "��ǽ");
  set ("long", @LONG

�ߴ�ĳ�ǽ�������ɶ�ߣ��ɻ��Ҽл������ɡ���ǽ�ϰ߲߰�����
�������Ѿ���Щ����ˣ����ų�����ǽ����һ����ʵ����ʯ·��
���������߳���

LONG);

  set("exits", ([
        "west"         : __DIR__"qiang1c",
        "east"         : __DIR__"qiang1e",
        "southup"      : __DIR__"shanlu1",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}
