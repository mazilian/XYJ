// cracked by vikee 2/09/2002   vikee@263.net
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "˾��");
  set ("long", @LONG

���ڹ��߰����������Ũ������ʱ�شӰ뿪�ŵ��ŷ�Ʈ����������
��ɢ��һЩ�ƾɵ���Ʒ�������������Ѿ��޷��ֱ������Щʲô
�����ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"new-yinsi1",
]));
  set("hell", 1);
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);

  setup();
}

