// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���Ӽ�");
        set ("long", @LONG

�����ǹ��Ӽ�����ã�Ҳ���������ƽʱ�Ͽεĵط����߸ߵ͵͵���
������������ߵ�һ�Ŵ��Ӷ����ţ��������յ�ͨ��������һ��һ
�Σ������ķ��ı���һλ����������Ŀ����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"guozijian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/zhangsunwuji" : 1,
                __DIR__"npc/xiucai4" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

