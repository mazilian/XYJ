// cracked by vikee 2/09/2002   vikee@263.net
// dhg.c ��ƹ�

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ƹ�", ({"dhg", "dahuanggua"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ���������̵Ĵ�ƹϡ�\n");
                set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}