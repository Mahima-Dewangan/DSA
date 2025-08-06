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

// BRUTE FORCE TECHNIQE :
// USING HASHMAP 
// TC = O (n * 2 * logn or 1 ) 
// SC = O (n) : hashmap  storing all the nodes

// bool detect_cycle(Node * head)
// {
//     Node * temp = head;
//     unordered_map<Node* , int>hash;
//     while(temp) -------------------------------------------------------- O(n)
//     {
//         if(hash.find(temp)!=hash.end()) ----------------------------------------------o(log n)
//         {
//             return true;
//         }
        
//         hash[temp]=1;----------------------------------------------------------------o(log n)
//         temp = temp->next;
//     }

//     return false ;
// }


// OPTIMAL SOLUTION ----------------TC=0(n) (somewhat o(n)) as it depends on where the slow and fast collide , might be earlier , 
//might be later , might be at the middle



// Important question ----- Why the slow and fast pointer will collide?
/*  ANSWER :  as we are moving the fast pointer by 2 
and the slow pointer by 1 
so when they move inside the loop the fast is moving towards the slow by distance 2 and 
the slow is moving away from the fast by the distance 1 
so the net distance between the fast and slow will be 1
and hence with every movement the distance between them will
decrease by one and so it will droop down to zero at some point;
*/
bool detect_cycle(Node * head)
{
    
    Node * slow = head;
    Node * fast = head;

    while(fast!=NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> arr ={5,2,8,7};
    Node * head=convertToLL(arr);
    cout<<"\n Is there a cycle ? "<<detect_cycle(head);
    return 0;

}

