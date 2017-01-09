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
    L = ( List ) malloc( sizeof( List ) );
    L->Next = NULL;
    printf("MakeEmpty success.\n");
    return L;
}

int IsEmpty( List L )
{
    return L->Next == NULL;
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

void InitList( ElementType X, List L )
{
    if( IsEmpty( L ) )
    {
        L->Element = X;
        printf("Initialize list success\n");
    }
    else
        printf("List is not empty, Initialize false\n");
}

void ShowList( List L )
{
    if( IsEmpty( L ) )
        printf("List is empty\n");
    Position TmpCell = L;
    while( TmpCell != NULL)
    {
        printf("%d\n", TmpCell->Element);
        TmpCell = TmpCell->Next;
    }
}

int main( void )
{
    List L = NULL;
    L = MakeEmpty( L );
    printf("%d\n", L->Element);

    int Is = IsEmpty( L );
    printf("%d( 1:Empty, 0:NoEmpty)\n", Is);

    InitList( 10, L );
    Insert( 20, L, Header( L ) );
    Insert( 30, L, Find( 20, L ) );
    Insert( 40, L, Header( L ) );
    ShowList( L );
    return 0;
}
