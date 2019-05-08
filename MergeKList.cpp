//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int n) :val(n), next(NULL) {}
//};

ListNode* mergeKList(ListNode *r, int k)
{
    if(k<= 1 || r == NULL || r->next == NULL)
        return NULL;
    ListNode **p = &r;
    ListNode *start = r;
    vector<ListNode*> v(k, NULL);
    while(start)
    {
        int n=0;
        while(n<k && start)
        {
            v[n] = start;
            start = start->next;   
            ++n;
        }
        if(n == k)
        {
            *p = v[k-1];
            v[0]->next = start;
            p = &(v[0]->next);
            int index = k-1;
            while(index>0)
            {
                v[index]->next = v[index - 1];
                --index;
            }                   
        }
        else
        {
            break;
        }   
    }
    return r;
}
