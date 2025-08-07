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
// BRUTE FORCE
// TC : O(2n)
// SC : O(n)
// bool is_palindrome(Node * head)
// {
//       stack<int>st;
//       Node * temp = head;
//       while(temp)-----------------------------O(n)
//       {
//         st.push(temp->data);
//         temp= temp->next;
//       }

//       temp = head;
//       while(temp)------------------------------O(n)
//       {
//         if(temp->data!=st.top())
//         {
//             return false;
//         }
//         st.pop();
//         temp=temp->next;

//       }

//       return true;
// }


// OPTIMAL SOLUTION

Node * reverse(Node * head)
{
    Node * temp = head;
    Node * prev = NULL;

    while(temp)
    {
        Node*front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}
bool is_palindrome(Node * head)
{
    // Step 1 : find the middle of the linked list
    Node *slow = head ; 
    Node * fast = head;
    while(fast->next !=NULL && fast->next->next !=NULL)
    {
        slow= slow->next;
        fast = fast->next->next;
    }

    // Step 2 : reverse the second half of the linked list
    Node * newHead = reverse(slow->next);


    // Step 3 : compare the elements
    Node * first = head;
    Node * second = newHead;
    while(second)
    {
        if(first->data!=second->data)
        {
            reverse(newHead);
            return false;
        }

        first = first->next;
        second=second->next;
    }


    reverse(newHead);
    return true;
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
    vector<int> arr ={1,2,1};
    Node * head=convertToLL(arr);
    int ans = is_palindrome(head);
    cout<<"\n is the LL Palindrome ?"<<ans;
    // print(head);
}