// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/nanhai/zhulin.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ӻ�ɽ�������֡�Ҳ�ǹ��������������������ڡ�����ϸ�裬
���΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"zhulin"+sprintf("%d", random(6)),
  "northwest" : __DIR__"zhulin"+sprintf("%d", random(6)),
  "northeast" : __DIR__"zhulin5",
  "southeast" : __DIR__"zhulin"+sprintf("%d", random(6)),
]));

  setup();
  replace_program(ROOM);
}