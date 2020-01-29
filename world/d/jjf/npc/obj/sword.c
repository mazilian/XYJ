// cracked by vikee 2/09/2002   vikee@263.net
// changjian.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("长剑", ({"chang jian", "changjian", "jian", "sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的精钢剑，一般的剑客都配带此剑。\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(25);
	setup();
}
