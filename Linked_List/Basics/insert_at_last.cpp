#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        data =d;
        next = nullptr;
    }
    Node(int d , Node * n1)
    {
        data = d;
        next = n1;
    }
};

Node * converToLL(vector<int> arr)
{
    Node * head = new Node(arr[0]);
    Node * mover = head;

    for(int i=1;i<arr.size();i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;

    }

    return head;
}

// INSERT AT THE LAST 
Node * insert_at_last(int val, Node * head)
{
    // if the LL is empty
    if(head ==0)
    {
        Node * temp=new Node(val);
        return temp;
    }

    Node * temp = head;
    Node * tail = new Node(val);
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    
    temp->next = tail;
    return head;

}


void print(Node * head)
{
    Node * temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
} 

int main()
{
    vector<int> arr = {5,2,8,7};
    Node *head = converToLL(arr);
    head = insert_at_last(100 , head);
    print(head);
    return 0;
}