// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;
void create()
{
  set_name("破铁笼", ({"tie long", "long"}));
  set_weight(2800000);
  set("long", "一个破铁笼。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_get", 1);
    set("unit", "把");
    set("material", "stone");
    set("value", 2000);
    set("no_sell", 1);
  }
  setup();
}

