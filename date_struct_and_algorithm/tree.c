#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position Find( ElementType X, SearchTree T )
{
    if( T == NULL )
        return NULL;
    if( X < T->Element )
        return Find( X, T->Left );
    else if ( X > T->Element )
        return Find( X, T->Right );
    else
        return T;
}

//递归调用
Position FindMax( SearchTree T )
{
    if( T == NULL )
        return NULL;
    else if( T->Right == NULL )
        return T;
    else
        return FindMax( T->Right );
}

//非递归调用
Position FindMin( SearchTree T )
{
    if( T != NULL )
        while( T->Left != NULL )
            T = T->Left;
    return T;
}

SearchTree Insert( ElementType X, SearchTree T )
{
    if( T == NULL )
    {
        T = malloc( sizeof( struct TreeNode ) );
        T->Element = X;
        T->Left = T->Right = NULL;
    }
    else if( X < T->Element )
        T->Left = Insert( X, T->Left );
    else if( X > T->Element )
        T->Right = Insert( X, T->Right );
    //else X = T->Element, do nothing
    return T;
}

SearchTree Delete( ElementType X, SearchTree T )
{
    Position TmpCell;

    if( T == NULL )
        printf(" ELement not found");
    else if( X < T->Element )
        T->Left = Delete( X, T->Left );
    else if( X > T->Element )
        T->Right = Delete( X, T->Right );
    else if( T->Left && T->Right ) //Found element and has two child
    {
        TmpCell = FindMax( T->Right ); //Replace T with the min node in the right child tree
        T->Element = TmpCell->Element;
        T->Right = Delete( T->Element, T->Right ); //Delete the min node in the right child tree
    }
    else //has one or zero child
    {
        TmpCell = T;
        if( T->Left == NULL )
            T = T->Right;
        else if( T->Right == NULL )
            T = T->Left;
        free( TmpCell );
    }
    return T;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}
//递归遍历
void ShowTree( SearchTree T )
{
    if( T != NULL)
    {
        //改变顺序，可以改为前中后序遍历
        ShowTree( T->Left );

        ShowTree( T->Right );
printf("%-2d", T->Element);
    }
}


