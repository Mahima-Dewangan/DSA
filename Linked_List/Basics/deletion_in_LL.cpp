#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int d1 , Node* n1)
    {
        data = d1;
        next = n1;
    }
    Node(int d1)
    {
        data = d1;
        next = nullptr;
    }
};


Node* deletek(int k , Node* head)
{
    //when linked list is empty
    if(head == NULL) 
    {
        return head;
    }
    //when linked list has only one elements
    if(k==1)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    //when the linked list has more than one elemnet 
    int cnt=0;
    Node *temp = head;
    Node *prev = NULL;
    while(temp)
    {
        cnt++;
        if(k== cnt )
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp ;
        temp = temp->next;
        

    }

    return head;
}

int main()
{
    vector<int> arr = {2,5,8,7};
    Node * head = convertarrToLL(arr);
    head = 


}