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
Node * convertToLL(vector<int> arr)
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

// BRUTE FORCE METHOD
// int del_mid(Node * head)
// {
//     Node * temp = head;
//     int cnt =0;
//     while(temp)     --------------------------------------O(n)
//     {
//         cnt++;
//         temp=temp->next;
//     }

//     int mid = (cnt/2)+ 1;
//     temp = head;

//     while(temp)----------------------------------------------O(n/2)
//     {
//        mid = mid-1;
//        if(mid ==0)
//        {
//         break;
//        }
//     temp = temp->next; 
//     }

//     return temp->data;
// }------------------------------------------------------------------------------- TC = O(n) +O(n/2) = O(n)    SC = O(1)


// OPTIMAL SOLUTION  TC = O(n/2)

int find_mid(Node * head)
{
    Node * slow = head;
    Node * fast = head;
    while(fast !=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
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
    vector<int> arr ={5,2,8,7};
    Node * head=convertToLL(arr);
    // // int mid = del_mid(head);
    // cout<<"\nthe mid element is "<<del_mid(head);
    cout<<"\n the middle element is "<<find_mid(head);


    return 0;

}