// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

inherit ROOM;

void create()
{
set("short", "�칬��ǽ");
set("long", @LONG
    
�ߴ���ΰ���칬��ǽ���������������ߣ�����
��ǽ��ȥ������һ�ڣ��岽һ�ڡ��䱸ɭ�ϡ�
LONG );


set("exits", ([
"south"   : __DIR__"tgqw1",
"north"   : __DIR__"tgqw3",
]));


set("objects", ([
]));



set("outdoors", 1);
setup();
}