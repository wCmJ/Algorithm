#include<iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

void reverseList(ListNode *&root){
    if(root == NULL || root->next == NULL)
    {
        return;
    }
    ListNode *cur = root->next;
    root->next = NULL;
    ListNode *tmp;
    while(cur)
    {
        tmp = cur->next;
        cur->next = root;
        root = cur;
        cur = tmp;
    }
}






