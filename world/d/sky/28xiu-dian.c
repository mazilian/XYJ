// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

// by snowcat 1998.9.1 reminder:
//    �������ޡ��Ϸ����ޡ��������ޡ���������
//
//    ����(��)������(��)������(��)������(��)
//    ����(��)������(¹)������(��)��Σ��(��)
//    ����(��)������(��)��¦��(��)��ţ��(ţ)
//    ��ľ(��)����ľ(��)����ľ(��)����ľ(�)
//    β��(��)����ˮ(�)����ˮ(Գ)����ˮ(��)
//    ��ˮ(��)������(��)������(��)���һ�(��)
//    ص��(��)������(�)��θ��(��)��Ů��(��)
    

void create ()
{
  set ("short", "��ʮ���޵�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
������֮����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanmenting.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"stars/foxer" : 1,
  __DIR__"stars/acer" : 1,
  __DIR__"stars/smallfox" : 1,
  __DIR__"stars/cygnus" : 1,
  __DIR__"stars/ljty" : 1,
]));

  setup();
}