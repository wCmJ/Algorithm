#include<iostream>
#include<stack>
#include<vector>

struct ListNode{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x):val(x),left(NULL),right(NULL){}
}

void preOrder(ListNode *root){
    std::stack<ListNode<int> *> s;
    while(true){
        visitLeftChild(root, s);
        if(s.empty())
            break;
        root = s.top();
        s.pop();
}
void visitLeftChild(ListNode *root, std::stack<ListNode<int> *> &s){
    while(root){
        std::cout<<root->val<<" ";
        if(root->right)
            s.push(root->right);
        root = root->left;
    }
}


void inOrder(ListNode *root){
    std::stack<ListNode*> s;
    while(true){
        goLeftChild(root, s);
        if(s.empty())
            break;
        ListNode* tmp = s.top();
        s.pop();
        std::cout<< tmp->val<<" ";
        root = tmp->rchild;
}
void goLeftChild(ListNode *root, std::stack<ListNode*> &s){
    while(root){
        s.push(root);
        root = root->left;
   }
}

void postOrder(ListNode *root){
    std::stack<ListNode*> s;
    std::vector<int> v;
    while(true){
        overLeftChild(root, s, v);
        if(s.empty())
            break;
        root = s.top();
        s.pop();
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        std::cout<<v[i]<<" ";           
}
void overLeftChild(ListNode *root, std::stack<ListNode*> &s, std::vector<int> &v){
    while(root){
        v.push_back(root->val);
        if(root->left)
            s.push(root->left);
        root = root->right;
}
