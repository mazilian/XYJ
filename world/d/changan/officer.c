// cracked by vikee 2/09/2002   vikee@263.net

inherit NPC;

int get_short(string rep, string arg, string *householder);
int get_long(string arg, string *householder,string short,string rep);
int save_file(string short, string llong, string *householder);

void create()
{
        set_name("老头", ({"officer","oldman"}));
        set("gender", "男性");
        set("age", 100);
        set("long",
"泾水河边的居民逐渐增多，因此特别在此设立房管所，临时由一个不知名的老头负责。