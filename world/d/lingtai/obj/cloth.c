// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit CLOTH;

void create()
{
       set_name("̫������", ({"cloth", "pao"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",
"һ����ʿ���ĳ��ۣ�����̫�����ԣ�������������Ǭ����\n");
                set("unit", "��");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("armor_prop/spells", 5);
             }
	setup();
}
