#include "element.h"
#ifndef _STACK_H_
#define S_TACK_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty( Stack S );
Stack CreatStack( void );
void DisposeStack( Stack S );
void StackMakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );

#endif // _STACK_H_
