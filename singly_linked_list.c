#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct link_node  //定义单链表的结点类型
{
  ElemType data;
  struct link_node * next;
}link_node;

// 1.初始化单链表
void init_list(link_node **p_node)
{
  *p_node = NULL;
  printf("init_list函数执行，初始化成功\n");
}

// 2.创建单链表
link_node *creat_link(link_node *p_head)
{
  // int flag = 0;
  link_node *p1;
  link_node *p2;
  p1 = p2 = (link_node *)malloc(sizeof(link_node));
  printf("输入结点的数据(q:退出)\n");
  while ((scanf("%d", &p1->data)) != 0)
  {
    p1->next = NULL;
    if (p_head == NULL)
    {
      p_head = p1;  //空表，接入表头
    }
    else
    {
      p2->next = p1;  //非空表，接入表尾
    }
    p2 = p1;
    p1 = (link_node *)malloc(sizeof(link_node));
  }
  printf("creat_link函数执行，单链表创建成功\n");
  return p_head;  //返回表头指针
}

//3.打印链表，链表的遍历
void print_list(link_node *p_head)
{
  if(p_head == NULL)
  {
    printf("print_list函数执行，链表为空\n");
  }
  else
  {
    printf("print_list函数执行，链表的值依次为：\n");
    while(p_head != NULL)
    {
      printf("%d\n", p_head->data);
      p_head = p_head->next;
    }
  }
}

//  4.清除链表数据，释放所有结点
void clear_list(link_node *p_head)
{
  link_node *p_next;
  if(p_head == NULL)
  {
    printf("clear_list函数执行，链表为空\n");
  }
  while (p_head->next != NULL)
  {
    p_next = p_head->next;  //保存下一结点
    free(p_head);
    p_head = p_next;  //表头下移
  }
  printf("clear_list函数执行，链表已清除\n");
}

//  5.链表长度
int size_list(link_node *p_head)
{
  int size = 0;
  while (p_head != NULL)
  {
    size++;
    p_head = p_head->next;
  }
  printf("size_list函数执行，链表长度为：%d\n", size);
  return size;
}

int main()
{
  link_node *p_list = NULL; //定义链表

  init_list(&p_list); //链表初始化，与上述定义时，
                      //*p_list = NULL作用相同
  print_list(p_list); //打印链表

  p_list = creat_link(p_list);  //创建链表
  print_list(p_list); //打印链表

  size_list(p_list);  //返回链表长度

  clear_list(p_list); //清除链表
  return 0;
}
