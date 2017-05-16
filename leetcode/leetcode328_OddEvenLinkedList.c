#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

ListNode *creatList( ListNode *l)
{
    ListNode *p1;
    ListNode *p2;
    p1 = p2 = ( ListNode* ) malloc( sizeof(ListNode) );
    printf("输入结点的数据(q:退出)\n");
    while(scanf("%d", &(p1->val)) != 0)
    {
        p1->next = NULL;
        if( l == NULL )
            l = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = ( ListNode* ) malloc ( sizeof( ListNode ) );
    }
    while(getchar() != '\n')
        continue;
    printf("creatList函数执行，单链表创建成功\n");
    return l;
}

void printList( ListNode *l )
{
    printf("printList函数执行，链表的值依次为：\n");
    while(l != NULL)
    {
        printf("%d\n", l->val);
        l = l->next;
    }
}

struct ListNode* oddEvenList(struct ListNode* head) {
    if( head == NULL )
        return head;
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;
    while( even != NULL && even->next != NULL )
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(void)
{
    ListNode *l1 = NULL;
    l1 = creatList(l1);
    printList(l1);
    ListNode* res = oddEvenList( l1 );
    printList( res );

    return 0;
}

