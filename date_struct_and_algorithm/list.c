#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList( L );
    L = NULL;
    printf("MakeEmpty success.\n");
    return L;
}

int IsEmpty( List L )
{
    return L == NULL;
}

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

Position Find( ElementType X, List L )
{
    Position P;
    P = L->Next;
    while( P != NULL && P->Element != X )
        P = P->Next;
    return P;
}

void Delete( ElementType X, List L )
{
    Position P, TmpCell;
    P = FindPrevious( X, L );
    if( !IsLast( P, L ) )
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell );
    }
}

Position FindPrevious( ElementType X, List L )
{
    Position P;
    P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;
    return P;
}


//在P节点后面插入
void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;
    TmpCell = ( Position ) malloc( sizeof( Position ) );
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList( List L )
{
    Position P, TmpCell;
    P = L->Next;
    L->Next = NULL;
    while( P != NULL )
    {
        TmpCell = P->Next;
        free( P );
        P = TmpCell;
    }

}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}

Position Advance( Position P )
{
    return P->Next;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}

List InitList( ElementType X, List L )
{
    if( IsEmpty( L ) )
    {
        L = ( Position )malloc( sizeof( Position ) );
        L->Element = X;
        L->Next = NULL;
        printf("Initialize list success\n");
    }
    else
        printf("List is not empty, Initialize false\n");
    return L;
}

void ShowList( List L )
{
    if( IsEmpty( L ) )
        printf("List is empty\n");
    Position TmpCell = L;
    while( TmpCell != NULL)
    {
        printf("%d", TmpCell->Element);
        if( !IsLast( TmpCell, L ) )
            printf("->");
        TmpCell = TmpCell->Next;
    }
    printf("\n");
}

void AddElement( ElementType X, List L )
{
    Position LastNode = L;
    while( LastNode->Next != NULL )
        LastNode = LastNode->Next;
    Position TmpCell = ( Position )malloc( sizeof( Position ) );
    TmpCell->Element = X;
    TmpCell->Next = NULL;
    LastNode->Next = TmpCell;
}

List Inverse( List L )
{
    List P1 = Header( L );
    List P2 = P1->Next;
    List P3 = NULL;
    while( P2 != NULL )
    {
        P3 = P2->Next;
        P2->Next = P1;
        P1 = P2;
        P2 = P3;
    }
    Header( L )->Next = NULL;
    return P1;
}

int main( void )
{
    List L = NULL;
    L = MakeEmpty( L );

    int Is = IsEmpty( L );
    printf("List is %s\n", Is?"Empty":"NoEmpty");

    L = InitList( 10, L );

    Insert( 20, L, Header( L ) );
    Insert( 30, L, Find( 20, L ) );
    Insert( 40, L, Header( L ) );
    AddElement( 50, L);
    AddElement( 20, L );
    ShowList( L );

    Position FindElement = Find( 20, L );
    printf("查找元素:20\n");
    ShowList( FindElement );

    Delete( 20, L );
    printf("删除元素：20\n");
    ShowList( L );

    printf("翻转链表\n");
    List InverseL = Inverse( L );
    ShowList( InverseL );

    L = MakeEmpty( L );
    printf("删除链表\n");
    ShowList( L );
    return 0;
}
