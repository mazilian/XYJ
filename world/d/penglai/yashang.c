// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

�������Ϸ�������������Ǻ�ȥ������������Ұ������Զ�����ܣ�
��������ɫ�������������Զ������������ƽ����ɽ���ϳ���
������ݣ�Ʈ�ŵ���������
LONG);
  set("exits", ([ /* sizeof() == 3 */
//  "south" : __DIR__"road1",
]));
	set("outdoors", 1);
  setup();
}

void grass_grow()
{
	object grass;
	seteuid(getuid());
	if(grass=new("/d/obj/drug/qiongcao")){
		grass->move(this_object());
		grass->invocation();
	}
	return;
}