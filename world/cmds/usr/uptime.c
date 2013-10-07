// cracked by vikee 2/09/2002   vikee@263.net
// uptime.c

inherit F_CLEAN_UP;
string report_str();

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int report()
{
    write("���μ��Ѿ�������" + report_str()+"��\n");
    return 1;
}
string report_str()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	return(time);
}

int main()
{
	report();
	write("\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ����������μ��Ѿ������˶�á�
 
HELP
    );
    return 1;
}