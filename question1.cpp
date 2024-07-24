#include <iostream>
using namespace std;
class Node
{       // user definde data type and Here, Node is being defined as a type that
public: // represents a single node in a linked list.
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val; // this is a pointer that points to the object itself.
        this->next = NULL;
    }
};

Node *reverseList(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        q = r;
        r = p;
        p = p->next;
        r->next = q;
    }
    return r;
}

// we  can  also  use  a function for  print   value of  node .
int main()
{
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    Node e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    Node temp = a;
    cout<<"Before Reverse :";
    while (1)
    {
        cout << temp.val << " ";
        if (temp.next == NULL)
            break;
        temp = *(temp.next);
    }
    Node *newNode = reverseList(&a);
    cout << endl;
    cout<<"After Reverse :";
    while (1)
    {
        cout << newNode->val << " ";
        if (newNode->next == NULL)
            break;
        newNode = (newNode->next);
    }
    cout<<endl;
}
