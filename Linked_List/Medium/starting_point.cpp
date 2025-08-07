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
// // BRUTE FORCE TECHNIQUE
// Node * find_starting_point(Node * head)
// {
//     unordered_map<Node* , int>hash;
//     Node * temp = head;
//     while(temp)
//     {

//         if(hash.find(temp)!=hash.end())
//         {
//                 return temp;
//         }
//         hash[temp]=1;
//         temp = temp->next;
//     }

//     return NULL;

// }



// OPTIMAL SOLUTUON ---------
Node * find_starting_point(Node * head)
{
    Node * slow= head;
    Node * fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast = fast->next->next;

        if(slow==fast)
        {
            slow = head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
     return NULL;


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
    head = find_starting_point(head);
    print(head);
}