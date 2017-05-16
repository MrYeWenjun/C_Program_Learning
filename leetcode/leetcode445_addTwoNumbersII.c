#include <stdio.h>
#include <stdlib.h>
//此题考验链表，递归
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //解法一，利用栈的思想重新构造链表，把l1，l2压入栈中，本质上是倒叙遍历链表
 /*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* s1 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    struct ListNode* s2 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    s1->next = NULL;
    s2->next = NULL;
    while( l1 != NULL )
    {
        struct ListNode* TmpCell = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
        TmpCell->val = l1->val;
        TmpCell->next = s1->next;
        s1->next = TmpCell;
        l1 = l1->next;
    }
    while( l2 != NULL )
    {
        struct ListNode* TmpCell = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
        TmpCell->val = l2->val;
        TmpCell->next = s2->next;
        s2->next = TmpCell;
        l2 = l2->next;
    }
    s1 = s1->next;
    s2 = s2->next;
    //printList( s1 );
    //printList( s2 );
    struct ListNode* sum = NULL;
    int thisSum, temp = 0;
    struct ListNode* p1;
    //ListNode* p2;
    p1 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    while( s1 != NULL || s2 != NULL || temp != 0)
    {
        thisSum = ( s1 != NULL ? s1->val : 0 ) + ( s2 != NULL ? s2->val : 0 ) + temp;
        temp = thisSum / 10;
        if( sum == NULL )
        {
            p1->val = thisSum % 10;
            p1->next = NULL;
            sum = p1;
            //printList( sum );
            p1 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
        }
        else
        {
            p1->val = thisSum % 10;
            p1->next = sum;
            sum = p1;
            //printList( sum );
            p1 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );

        }
        s1 = s1 != NULL ? s1->next : s1;
        s2 = s2 != NULL ? s2->next : s2;
    }
    p1 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    p1->val = temp;
    p1->next = sum;
    sum = p1;
    //printList( sum );
    return sum->val == 0 ? sum->next : sum;
}
*/

//解法二，利用递归，递归本质是调用栈，可以实现倒叙遍历链表
/*
int getLength ( struct ListNode* l )
{
    int cnt = 0;
    while( l != NULL )
    {
        ++cnt;
        l = l->next;
    }
    return cnt;
}
struct ListNode* getSum( struct ListNode* l1, struct ListNode* l2, int diff )
{
    if( l1 == NULL )
        return NULL;
    int thisSum;
    struct ListNode* p1 = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    if( diff != 0 )
    {
        p1->next = getSum( l1->next, l2, diff - 1 );
        thisSum = l1->val;
        if( p1->next != NULL && p1->next->val > 9)
        {
            p1->next->val %= 10;
            p1->val = thisSum + 1;
        }
        else
            p1->val = thisSum;
        //carry = thisSum / 10;
        return p1;
    }
    else
    {
        p1->next = getSum( l1->next, l2->next, 0 );
        thisSum = l1->val + l2->val;
        if( p1->next != NULL && p1->next->val > 9 )
        {
                p1->next->val %= 10;
                p1->val = thisSum + 1;
        }
        else
            p1->val = thisSum;
        //carry = thisSum / 10;
        return p1;
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int length1 = getLength( l1 );
    int length2 = getLength( l2 );
    struct ListNode* sum = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    sum->val = 1;
    //int carry = 0;
    sum->next = ( length1 >= length2 ) ? getSum( l1, l2, length1 - length2 ) : \
        getSum( l2, l1, length2 - length1 );
    if( sum->next->val > 9 )
    {
        sum->next->val %= 10;
        return sum;
    }
    else
        return sum->next;
}
*/

//解法三，
int getLength ( struct ListNode* l )
{
    int cnt = 0;
    while( l != NULL )
    {
        ++cnt;
        l = l->next;
    }
    return cnt;
}
struct ListNode* getSum( struct ListNode* l1, struct ListNode* l2, int diff )
{
    int thisSum;
    struct ListNode* current = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    struct ListNode* head = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    head->val = 0;
    head->next = current;
    struct ListNode* previous = head;
    while( diff )
    {
        thisSum = l1->val;
        current->val = thisSum;
        struct ListNode* tmpCell = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
        current->next = tmpCell;
        previous = current;
        current = tmpCell;
        l1 = l1->next;
        --diff;
    }
    while( l1 != NULL )
    {
        thisSum = l1->val + l2->val;
        if( thisSum > 9 )
        {
            current->val = thisSum % 10;
            previous->val += 1;
        }
        else
            current->val = thisSum;
        struct ListNode* tmpCell = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
        current->next = tmpCell;
        previous = current;
        current = tmpCell;
        l1 = l1->next;
        l2 = l2->next;
    }
    previous->next = NULL;
    if( head->next->val > 9 )
    {
        head->next->val %= 10;
        head->val += 1;
    }
    if( head->val == 0 )
        return head->next;
    return head;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int length1 = getLength( l1 );
    int length2 = getLength( l2 );
    struct ListNode* sum = ( struct ListNode* ) malloc( sizeof( struct ListNode ) );
    //sum->val = 1;
    sum = ( length1 >= length2 ) ? getSum( l1, l2, length1 - length2 ) : \
        getSum( l2, l1, length2 - length1 );
    return sum;
}
int main(void)
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    l1 = creatList(l1);
    printf("The first number is :\n");
    printList(l1);
    l2 = creatList(l2);
    printf("The second number is :\n");
    printList(l2);
    ListNode *sum = addTwoNumbers( l1, l2 );
    printf("Sum of the two numbers is :\n");
    printList(sum);
    return 0;
}

