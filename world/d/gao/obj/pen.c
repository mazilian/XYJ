// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;

void create()
{
        set_name("��ϴ����", ({"pen"}));
	set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ����ϴ���裬���涼�����·���\n"),
	set("no_get", 1);
	}
	setup();
}

//int is_container()
//{
//set("objects", (["/u/bula/gao/obj/kaoji"]) );
//}