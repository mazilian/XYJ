// cracked by vikee 2/09/2002   vikee@263.net
// gate.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

��������������ڸ����ţ�һƬһƬ��ũ�����������С��С��
�ܲ����У�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"road4",
"south" : __DIR__"tulu",
]));
set("objects", ([
                __DIR__"npc/farmer": 1 ]) );


        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

