// cracked by vikee 2/09/2002   vikee@263.net
//qiezidi.c

inherit ROOM;

void create ()
{
	set ("short", "茄子地");
	set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是茄子地。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"huangguadi",
		"north" : __DIR__"baicaidi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//"/d/obj/food/dbc" : 2,
		//"/d/obj/food/xbc" : 2,
	]));

	//create_door("south", "梨花门", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
