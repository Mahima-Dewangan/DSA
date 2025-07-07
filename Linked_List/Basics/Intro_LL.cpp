#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
class Node
{

    public:
    int data;
    Node* next;

    public:
    Node(int d, Node* n1)
    {
        data = d;
        next = n1;
    }
};

int main()
{
    vector <int> arr = {2,5,8,7};
    Node* y = new Node(arr[0], nullptr);
    cout<<y->data;
    return 0;
}