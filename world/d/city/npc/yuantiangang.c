// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

string *list=({"yg-putuo","yg-moon","yg-wzg",
	"yg-fangcun","yg-hell","yg-jjf",
	"yg-dragon", "yg-xueshan",
	"yg-wudidong",
	});

int work_me();
int relocate_me();
 
void create()
{
        set_name("Ԭ���", ({"yuan tiangang", "yuan"}));
        set("gender", "����" );
        set("age", 33);
        set("long","Ԭ��������̨�ܹܣ���˵���������
��Ϊ����ֱ���壬��������һ���ǹ���������顣\n");
        set("int", 30);
	set("per", 25);
        set("combat_exp", 50000);
        set("daoxing", 800000);
	
	// discourage NK yuan.
	set("eff_dx",1000);
	set("nkgain",1);
	set("env/wimpy",100);

        set("attitude", "friendly");
	set("title", "���̨������");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 100);
	set_skill("baguazhou", 100);
        set_skill("literate", 50);
        set_skill("sword", 60);  
        set_skill("changquan", 50);  

        map_skill("spells", "baguazhou");
        map_skill("unarmed", "changquan");

        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 6000);
        set("max_mana", 3000);
        set("mana_factor", 100);

		set("chat_chance",5);
		set("chat_msg", ({
		    name()+"̾����������������ħ���а���\n",
		    name()+"�ʵ�������˭ԸȥΪ����������\n",
		    }));

        seteuid(getuid());

        set("inquiry", ([
			"mieyao": (: work_me :),
			"kill": (: work_me :),
			"����": (: work_me :),
			"��ħ": (: work_me :),
			"search": (: relocate_me :),
			"souyao": (: relocate_me :),
			"����": (: relocate_me :),
        ]));

        setup();
	add_money("silver", 5);
        carry_object("/d/obj/cloth/baguapao")->wear();
        carry_object("/d/obj/weapon/sword/taomujian")->wield();
}
int accept_fight(object me)
{
        write("Ԭ�����Ȼ����ѧ������Ϊ��ǿ�������Ǵ��ɱɱ��\n");
        return 0;
}
int recognize_apprentice(object me)
{
        if((int)me->query("yuan-learn"))
        return 1;
        return notify_fail("Ԭ���˵������̫�����ˣ�����ô�ҵ���\n");
}

int accept_object(object who,object ob)
{
        if (ob->query("id")=="fan he"){
		if (((string)who->query("family/family_name")=="������")){
			who->set("yuan-learn", 1);
			write("Ԭ���Ц��������������һ���˲ţ��Ժ�����ǰ��ͷ֮����
Ԭ�����Ϊ��˼���ֵ����������к����⣬����ʱ�������֣��������֪��������𸴣�\n");
			call_out("destroy", 1, ob);
			return 1;
		}
		if (((string)who->query("family/family_name")!="������")){
			command("say ��л��л�����������ģ�");
			command("give 1 silver to " + who->query("id"));			
			call_out("destroy", 1, ob);
                        return 1;
		}
	}
	else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

int work_me()
{
	object ghost, me;
	int t, lvl, dx;
	int fac, base;
	me=this_player();
	
	dx=(me->query("daoxing")+me->query("combat_exp"))/2;
	if(dx>50000) {
	  message_vision("$N��$nһ���֣���λ"+
	    RANK_D->query_respect(me)+
	    "����ȥ��͢Э��������\n",this_object(),me);
	  return 1;
	}
	    
	//for first time.
	if(!me->query("mieyao")) {
	        me->set_temp("mieyao/level1",0);
		call_out("start_job", 1, me);
		return 1;
	}
	if( (t=(int)me->query("mieyao/time_start1")) &&
		!me->query("mieyao/done1")) {

	    if(t<=time() &&
		    time()<t+1800) {
		command("heng");
		command(
 		  "say ���²�������ȥ�շ�"+me->query("mieyao/name1")
		  +"��\n");
		return 1;
	    }
	    // failed, decrease lvl.
	    if(!me->query_temp("mieyao/level_changed1")) {
		lvl=me->query_temp("mieyao/level1");
		if(lvl>0) lvl--;
		me->set_temp("mieyao/level1",lvl);
		me->set_temp("mieyao/level_changed1",1);
	    }

	    // allow ask again.
	} else { // job done
	    if(t<=time() &&
                    time()<t+20) {
		message_vision("$N��������ľ���������£�˵"+
			"����л"+RANK_D->query_respect(me)
			+",��ħ�Ѿ������ˡ�\n",
			this_object(), me);

		return 1;
	    }
	    // succeed, increase lvl.
	    if(!me->query_temp("mieyao/level_changed1")) {
		lvl=me->query_temp("mieyao/level1");
		if(lvl<9) lvl++; // total 10 levels: 0, ..., 9
		else
		    lvl=5; // reach the top level, reduce difficulty.
		me->set_temp("mieyao/level1",lvl);
		me->set_temp("mieyao/level_changed1",1);
	    }
	}
	me->delete("mieyao/time_start1");
	call_out("start_job", 1, me);
	return 1;
}

int start_job(object me)
{	string where;
	object ghost;
	int lvl;

	if(environment(me)!=environment()) return 1;
	if(me->query("mieyao/time_start1")) return 1;
	me->delete("mieyao/done1");
	me->set_temp("mieyao/level_changed1",0);

	// determine levels.
	// use temp mark, if quit, then start over.
	lvl=me->query_temp("mieyao/level1");
	
        ghost = new(__DIR__+"yg/"+list[random(sizeof(list))]);
        where=ghost->invocation(me, lvl);
	
	message_vision("$N��������ľ�����ķ�һ������$n˵����\n",
	  this_object(),me);
	message_vision("��������"+where+"��û��Ϊ����С��"
		+"����ȥ�շ���\n"
		,this_object(),me);
	me->set("mieyao/time_start1", time());
	me->set("mieyao/name1",ghost->query("name"));
	me->set("mieyao/ygid1",ghost->query("id"));
	me->set("mieyao/npcid1","/d/city/npc/yuantiangang");
	return 1;
}

int relocate_me()
{
	object ghost, me;
	int t, lvl, dx;
	string where;

	me=this_player();
	
	dx=(me->query("daoxing")+me->query("combat_exp"))/2;
	if(dx>50000) {
		message_vision("$N��$nһ���֣���λ"+
			RANK_D->query_respect(me)+
			"����ȥ��͢Э��������\n",this_object(),me);
		return 1;
	}
	if(!me->query("mieyao")) {
		command("say ���²�û������������\n");
		return 1;
	}

	if( (t=(int)me->query("mieyao/time_start1")) &&
		!me->query("mieyao/done1")) {
		if( !me->query("mieyao/search") || me->query("mieyao/search") <= 0)
		{
			command("notell "+this_object()->query("id"));
			return 1;
		}

		if(t<=time() && time()<t+180) {
			command("hmm");
			command("say �콫��������"+RANK_D->query_respect(me)+"Ҳ����ȥ���ң�\n");
			return 1;
		}
		ghost = find_living(me->query("mieyao/ygid1"));

		if( !ghost || (t<=time() && time()>=t+1800)) {
			message_vision("$N��ָһ�㣬��$n˵����\n",
				this_object(),me);
			message_vision("����"+me->query("mieyao/name1")+"��֪���٣�"+RANK_D->query_respect(me)+"������Ϣһ���\n"
				,this_object(),me);
			return 1;
		}

		me->add("mieyao/search", -1);
		lvl=me->query_temp("mieyao/level1");
		where = ghost->_invocation(me, lvl);
		message_vision("$N��ָһ�㣬��$n˵����\n",
			this_object(),me);
		message_vision("����"+where+"��"+RANK_D->query_respect(me)+"��ȥ׷��\n"
			,this_object(),me);
		if(me->query("mieyao/search") > 0)
		{
			command("whisper "+me->query("id")+" �㻹��"+me->query("mieyao/search")+"�����Ի���");
		}
		return 1;

	} else { // job done
		if(t<=time() &&
		time()<t+300+(dx>20000?300:0)) {
			message_vision("$N��������ľ���������£�˵"+
			"����л"+RANK_D->query_respect(me)
			+",��ħ�Ѿ������ˡ�\n",
			this_object(), me);
			return 1;
		}
	}
}