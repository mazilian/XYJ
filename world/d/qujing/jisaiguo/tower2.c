// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����������");
  set ("long", @LONG

����к���ͻأ��գ�������ɫ��������������������ƣ��г�
�޻𣬲�����ǰ����������ڸ�ɳ档����������ϣ����̾�����
�����⣬����ǰ������ǣ�ɡ�
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/kusu" : 1,
//]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower3",
  "down": __DIR__"tower1",
]));

  setup();
}
void init()
{
  add_action("do_shao", "shao");
}
int do_shao(string arg)
{
	object me=this_player();
	
	if(!arg && arg != "di" && arg!="floor")
		return notify_fail("��Ҫɨʲô��\n");

	if(!present("broom", me))
		return notify_fail("ûɨ�صļһ���ô�У�\n");

	if(query("clean"))
		return notify_fail("���¹��ɾ��ˣ�����ɨ�ˣ�\n");

	if((int)me->query("kee") <50)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	message_vision("$N�����Ŵ�ɨ��ɨ�������\n", me);
	write("����Ļҳ�Ǻ����ֱ�����硣\n");
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц��\n", me);
	me->receive_damage("kee", 30);
	me->add_temp("clean_floor", 1);
	
	if((int)me->query_temp("clean_floor") > 13){
		me->delete_temp("clean_floor");
	}
	set("clean", 1);
	call_out("regenerate", 800);
	set("long", @LONG

����к���ͻأ��գ�������ɫ����������ת�紩�ߣ��ſ��Ƴ�
������ƿӰ������£������������Ϸ硣���������ܹ���������
����������ʯ�������͸�����������Զ������ǧ���⣬�ߵ�
���ھ����С�
LONG);

	return 1;
}
int regenerate()
{
  set ("long", @LONG
                
����к���ͻأ��գ�������ɫ��������������������ƣ��г�
�޻𣬲�����ǰ����������ڸ�ɳ档����������ϣ����̾�����
�����⣬����ǰ������ǣ�ɡ�
LONG);  

        set("clean", 0);
        return 1;
}
