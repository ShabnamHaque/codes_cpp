#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL; // constructor
    }

};

Node *buildTree(Node *root)
{
    cout << "Enter the data  :" << endl;
   
    int data;
    cin >> data;
   
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
  
    cout << "Enter the data for left :" << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right :" << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrder(Node *root)
{   //BFS
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        
        //separator
        if(temp==NULL)
        {
         cout<<endl;
         if(!q.empty())
         {
             q.push(NULL);
         }
        }
        else{
            
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}
void inorder(Node *root)
{
    if(root==NULL) return ;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
    
}

void preorder(Node *root){
    
    if(root==NULL) return ;
    
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    
}
void postorder(Node *root){
    
    if(root==NULL) return ;
    
    postorder(root->left);
    postorder(root->right);
    
    cout<<root->data;
}

int main()
{
    Node* root=NULL;

    //creating a binary tree
    root=buildTree(root);
    levelOrder(root);
    inorder(root);
    

    return 0;
}
