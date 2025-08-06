#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;

    Node(int d)
    {
         data = d;
        next = nullptr;
    }
    Node(int d , Node * n1)
    {
        data = d;
        next = n1;
    }
};

// CONVERTING THE ARRAY TO LL
Node * convertToLL(vector<int> arr)
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

void print(Node * head)
{
    Node * temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}


// INSERTING THE NEW NODE AT THE HEAD OF THE LINKED LIST
Node * insert_head(int val , Node * head)
{
    Node * temp = new Node(val , head);
    return temp;
}


int main()
{
    vector<int>arr = {5,2,8,7};
    Node * head = convertToLL(arr);
    head = insert_head(100 , head);
    print(head);
    return 0;
}