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
    data=d;
    next=n1;
   }
};

Node * arrToLL( vector<int> arr)
{
    Node * head = new Node(arr[0]);
    Node * mover = head;

    for(int i=1;i<arr.size();i++)
    {
        Node *temp = new Node(arr[i]);
       mover->next = temp;
        mover = temp;
    }
    return head;
}


Node * del_k_position(Node * head , int k)
{

    // if the linked list is empty
    if(head == NULL)
    {
        return head;
    }
    // if the linked list has single element
    if(k==1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
                
    }

    // if the linked list has more than one element 
    Node * prev = NULL;
    int cnt=0;
    Node * temp = head;
    while(temp)
     {
        cnt ++;
        if(cnt == k)
        { 
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
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


int main()
{
    vector<int> arr = {2,5,8,7};
    int k;
    cout<<"\enter the position which you want to delete";
    cin>>k;
    Node * head = arrToLL(arr);
    head = del_k_position(head , k);
    print(head);
    return 0;
}


