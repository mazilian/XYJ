// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "ban niang","niang", "girl"}) );
        set("gender", "Ů��");
        set("age", 18);
	set("per", 20+random(5));
	set("title", "С����");
        set("long","һ��Ư����С���\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        setup();
        carry_object("/d/obj/cloth/xiuhuaxie")->wear();
	carry_object("/d/obj/cloth/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
		"�����Ღ���ã�����һ����ˮ��\n",
		"����������������������������\n",
		"���񿩿�һЦ��¶������С���ѡ�\n",
        }) );
}
