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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *sum = NULL;
    struct ListNode *p1;
    struct ListNode *p2;
    p1 = p2 = ( struct ListNode* ) malloc( sizeof(struct ListNode) );
    int thisSum, temp = 0;
    while( l1 != NULL || l2 != NULL || temp != 0)
    {
        thisSum = ((l1 != NULL) ? l1->val:0) + ((l2 != NULL) ? l2->val:0) + temp;
        temp = thisSum / 10;
        p1->val = thisSum % 10;
        p1->next = NULL;
        if(sum == NULL)
            sum = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = ( struct ListNode* ) malloc( sizeof(struct ListNode) );
        l1 = (l1 != NULL) ? l1->next:l1;
        l2 = (l2 != NULL) ? l2->next:l2;
    }
    return sum;
}

int main(void)
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    l1 = creatList(l1);
    printList(l1);
    l2 = creatList(l2);
    printList(l2);
    ListNode *sum = addTwoNumbers( l1, l2 );
    printList(sum);
    return 0;
}
