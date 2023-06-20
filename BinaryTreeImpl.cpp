#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    
};

Node* buildTree(Node* root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
        
    }
    cout<<"enter data for inserting left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for inserting right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void preOrder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
    cout<<endl;
}
void postOrder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<"  ";
    postOrder(root->left);
    postOrder(root->right);
    cout<<endl;
}

void inOrder(Node* root){
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
    cout<<endl;
}
int main()
{
    Node * root=NULL;
    root=buildTree(root);
    cout<<"Inorder traversal"<<endl;
    inOrder(root);
    cout<<"preorder traversal"<<endl;
    preOrder(root);
    cout<<"postorder traversal"<<endl;
    postOrder(root);
    return 0;
}
