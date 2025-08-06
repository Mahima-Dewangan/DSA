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
        data =d;
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

Node * insert_at_k(int value ,Node * head , int k)
{
    // if you want to insert at the first position
   if(k==1)
   {
    Node * temp = new Node(value , head);
    return temp;
   }

//    when we want to insert at any other position
   Node * pos = new Node(value);
   Node * prev = NULL;
   Node * temp = head;
   int cnt =0;
   while(temp)
   {
        cnt ++;
       if(cnt ==k)
       {
        pos->next = temp;
        prev->next = pos;
        break;
       }
       prev = temp;
       temp=temp->next;
   }

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
    vector<int> arr = {5,2,8,7}; int k;
    cout<<"\nnter the val at which you wanna insert";
    cin>>k;
    Node *head = converToLL(arr);
    head = insert_at_k(100 , head , k);
    print(head);
    return 0;
}

