// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

������λ�ڳ�����֮���ϣ�ס�������Щƶ���˼ҡ����ڹٸ����ٹ�
��������ΰ�����ʮ�ֺá���Χ������䣬·���Ӳݴ�����������
���ƵĻ�ɫ������һ˿�������������˴�����������ڣ������ɫ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"beiyin2",
                "east" : __DIR__"beiyin4",
		"west" : __DIR__"minju2",
		"south" : __DIR__"minju3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

