// cracked by vikee 2/09/2002   vikee@263.net
// xiao  ����֮��   qin  ����֮��
#include <ansi.h>

inherit SKILL;

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "�������" NOR,     
		HIB "��ͨ����" NOR,
		HIB "��ͨ����" NOR,     
		CYN "��������" NOR,
		HIC "����ͨ��" NOR,     
		HIW "�＼��˫" NOR,
	});

	grade = level / 30;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
