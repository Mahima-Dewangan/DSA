#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data ;
    Node * next;

    Node(int d)
    {
        data = d;
        next =nullptr;
    }
    Node(int d , Node * n1)
    {
        data = d;
        next =n1;
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

// BRUTE FORCE SOLUTION  
// TC = O(n) + O(n)
// SC = O(n)

// Node * rev_ll(Node * head)
// {
//     Node * temp = head;
//     stack<int>st;
//     while(temp)----------------------------------------------o(n)
//     {
//         st.push(temp->data);
//         temp=temp->next;
//     }

//     temp = head;
//     while(temp)---------------------------------------------------o(n)
//     {
//         temp->data = st.top();
//         st.pop();
//         temp=temp->next;
//     }

//     return head;
// }
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


// OPTIMAL SOLUTION
Node * rev_ll(Node * head)
{
    Node * temp = head;
    Node * prev = NULL;
    while(temp)
    {
        Node * front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}
int main()
{
    vector<int> arr ={5,2,8,7};
    Node * head=convertToLL(arr);
    head = rev_ll(head);
    print(head);
}