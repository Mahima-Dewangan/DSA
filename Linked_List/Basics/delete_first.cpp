#include<bits/stdc++.h>
using namespace std;

// CREATING A CLASS LINKED LIST

class Node
{
    public:
    int data;
    Node * next;

    public:
    Node(int d1 , Node* n1)
    {
        data = d1;
        next = n1;
    }
    Node(int d1)
    {
        data = d1;
        next = nullptr;
    }
};

//  CONVERTING THE ARRAY TO LINKED LIST
Node *convertArrToLL(vector<int>arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i=1;i<arr.size();i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;

    }

    return head;
}

//    DELETING THE NODE FROM FIRST OF THE LINKED LIST

Node *delete_from_first(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);

    return head;

}

// TO PRINT THE LINKED LIST

void print(Node * head)
{
    //traversing the linked list
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    vector<int>arr={2,5,8,7};
    Node * head = convertArrToLL(arr);
    head = delete_from_first(head);
    print(head);
    return 0;
}
