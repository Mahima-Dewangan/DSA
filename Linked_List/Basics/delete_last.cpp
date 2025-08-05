#include<bits/stdc++.h>
using namespace std;

//CREATING A CLASS
class Node
{
    public:
    int data;
    Node * next;

    public:

    Node(int d1 , Node * n1)
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

// CONVERT ARRAY TO LINKED LIST
Node * arrToLL(vector<int>arr)
{
    Node * head = new Node(arr[0]);
    Node * mover = head;

    for(int i=1;i<arr.size();i++)
    {
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
        
    }
    return head;
}

// DELETING THE LAST ELEMENT FROM THE LINKED LIST
Node * delete_last(Node * head)
{
    // base case : if the  linked list is null or has only one
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node * temp = head;
    // stopping at the 2nd last element
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }

    // free the last ele
    free(temp->next);
    
    // set the last pointer to NULL
    temp->next = NULL;

    return head;
}

void print(Node * head)
{
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
   cout<<endl;
}

int main()
{
    vector<int> arr = {5,2,8,7};
    Node * head = arrToLL(arr);
    head = delete_last(head);
    print(head);
    return 0;
}