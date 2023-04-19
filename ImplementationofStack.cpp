
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

class Stack
{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    int pop();
    bool push(int x);
    bool isempty();
    int peek();
    int randomaccess(int a[], int x);
};

int Stack::randomaccess(int a[], int x)
{
    return a[x];
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "stack underflow\n";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

bool Stack::push(int x)
{
    if (top == MAX - 1)
    {
        cout << "stack overflow";
        return 0;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return 1;
    }
}

bool Stack::isempty()
{
    return (top == -1);
}

int Stack::peek()
{
    if (top == -1)
    {
        cout << "empty stack";
        return 0;
    }
    else
        return a[top];
}

// LINKED LIST

class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int dataval)
{
    StackNode *Node = new StackNode();
    Node->data = dataval;
    Node->next = NULL;
    return Node;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int val)
{
    StackNode *newstacknode = newNode(val);
    newstacknode->next = *root;
    *root = newstacknode;
    cout << val << " pushed into stack by LL\n";
}

int pop(StackNode **root)
{
    if (isEmpty(*root))
    {
        return INT_MIN;
    }
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    else
        return root->data;
}

int main()
{

    class Stack stk1;
    stk1.push(40);
    stk1.push(900);
    stk1.push(89);
    cout << stk1.pop();
    cout << endl
         << stk1.peek() << endl;
    cout << stk1.isempty() << endl
         << endl;

    cout << stk1.randomaccess(stk1.a, 2) << endl;

    cout << endl
         << endl;

    StackNode *root = NULL;
    push(&root, 3);
    push(&root, 58);
    push(&root, 5);
    push(&root, 5);
    pop(&root);
    cout << peek(root) << endl;
    cout << isEmpty(root) << endl;

    while (isEmpty(root) == 0)
    {
        cout << peek(root) << " / ";
        pop(&root);
    }
    return 0;
}
/*
Advantages of array implementation:
Easy to implement.
Memory is saved as pointers are not involved.

Disadvantages of array implementation:
It is not dynamic
The total size of the stack must be defined beforehand.


40 pushed into stack
900 pushed into stack
89 pushed into stack
89
900
0

89


Advantages of Linked List implementation:
The linked list implementation of a stack can grow and shrink according to the needs at runtime.
It is used in many virtual machines like JVM.

Disadvantages of Linked List implementation:
Requires extra memory due to the involvement of pointers.
Random accessing is not possible in stack.


3 pushed into stack by LL
58 pushed into stack by LL
5 pushed into stack by LL
5 pushed into stack by LL
5
0
5 / 58 / 3 /
*/
