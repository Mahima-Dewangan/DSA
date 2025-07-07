#include<iostream>
#include<queue>
using namespace std;

// create a node
class node
{
    public:
    int data;
    node* left;
    node* right;
    // making a constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

// build a tree
node* buildTree(node* root)
{
    int data;
    cout<<"/nnter the data";
    cin>>data;
    root = new node(data);

    if(data==-1)
    return NULL;

    cout<<"\nnter the left data";
    root->left = buildTree(root->left);
    cout<<"\nnter the right data";
    root->right = buildTree(root->right);
    return 0;

}


int main()
{
    node* root = NULL;
     
}