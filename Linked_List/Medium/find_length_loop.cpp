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

// BRUTE FORCE SOLUTION
// int find_length_loop(Node * head)
// {
//     unordered_map<Node*,int>hash;
//     Node * temp = head;
//     int timer=0;
//     while(temp)
//     {
       
//         if(hash.find(temp)!=hash.end())
//         {
//            int value = hash[temp];

//            return (timer-value);
//         }

        
//         hash[temp]=timer;
//          timer++;
//         temp =temp->next;
//     }

//     return 0;
// }

// OPTIMAL SOLUTION
int find_length(Node * head)
{
    
    Node * slow = head;
    Node * fast = head;

    while(fast!=NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            int cnt =1;
            slow=slow->next;
            while(slow!=fast)
            {
                cnt++;
                slow=slow->next;
            }

            return cnt;
        }
    }

    return 0;
}
int main()
{
    vector<int> arr ={5,2,8,7};
    Node * head=convertToLL(arr);
    cout<<"\n The length of the cycle is  "<<find_length(head);
    return 0;

}