#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node* createNode(int value)
{
    Node* newNode=new Node();
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left!=NULL)
            q.push(temp->left);

        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node* root=NULL;
    int n,value;

    cout<<"Enter number of nodes: ";
    cin>>n;

    if(n<=0)
    {
        cout<<"Tree is empty";
        return 0;
    }

    cout<<"Enter root value: ";
    cin>>value;
    root=createNode(value);

    queue<Node*> q;
    q.push(root);

    for(int i=1;i<n;i++)
    {
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left child of "<<temp->data<<" (enter -1 for no child): ";
        cin>>value;

        if(value!=-1)
        {
            temp->left=createNode(value);
            q.push(temp->left);
        }

        if(i<n-1)
        {
            cout<<"Enter right child of "<<temp->data<<" (enter -1 for no child): ";
            cin>>value;

            if(value!=-1)
            {
                temp->right=createNode(value);
                q.push(temp->right);
            }
        }
    }

    cout<<"\nInorder Traversal: ";
    inorder(root);

    cout<<"\nPreorder Traversal: ";
    preorder(root);

    cout<<"\nPostorder Traversal: ";
    postorder(root);

    cout<<"\nLevel Order Traversal: ";
    levelOrder(root);

    return 0;
}
