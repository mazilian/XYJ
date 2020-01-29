// cracked by vikee 2/09/2002   vikee@263.net
// unwield.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, *inv,weapon,sweapon;
	string str;
	int i;

	if( !arg ) return notify_fail("你要脱掉什么？\n");

	if (arg=="all")
	{
		if(weapon=me->query_temp("weapon"))
		{
            
			if(sweapon=me->query_temp("secondary_weapon"))
			{
			 sweapon->unequip();
			 if( !stringp(str = sweapon->query("unwield_msg")) )
             str = "$N放下手中的$n。\n";
		     message_vision(str, me, sweapon);
			}

	         weapon->unequip();	
			 if( !stringp(str = weapon->query("unwield_msg")) )
             str = "$N放下手中的$n。\n";
		     message_vision(str, me, weapon);
			
			return 1;
	    }
		else
		{
               return notify_fail("你并没有装备任何武器。\n");
		}





	}
	else
	{
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

//	if( (string)ob->query("equipped")!="wielded"&&(string)ob->query("equipped")!="second_wield" )
	if( (string)ob->query("equipped")!="wielded")
		return notify_fail("你并没有装备这样东西作为武器。\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
	}
}

int help(object me)
{
  write(@HELP
指令格式 : unwield|fangxia <物品名>
 
这个指令让你放下手中的武器。
 
HELP
    );
    return 1;
}
 
