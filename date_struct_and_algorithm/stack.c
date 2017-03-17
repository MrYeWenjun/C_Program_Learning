#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

Stack CreatStack( void )
{
    Stack S;
    S = malloc( sizeof( struct Node ) );
    S->Next = NULL;
    StackMakeEmpty( S );
    return S;
}

void DisposeStack( Stack S )
{

}

void StackMakeEmpty( Stack S )
{
    while( !IsEmpty( S ) )
        Pop( S );
}

void Push( ElementType X, Stack S )
{
    PtrToNode TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Top( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Next->Element;
    else
        return 0;
}

void Pop( Stack S )
{
    PtrToNode TmpCell;
    TmpCell = S->Next;
    S = S->Next->Next;
    free( TmpCell );
}
