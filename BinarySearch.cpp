
template<class T>
int BinarySearch(T const *p, size_t lo, size_t hi, T e)
{
    while(lo < hi)
    {
        size_t mi = (lo + hi) >> 1;
        e < p[mi] ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

int BinarySearchClosed(int *p, size_t start, size_t end, int val)
{
    if(p == NULL)
        return -1;
    while(start < end)
    {
        int mid = (start+end)>>1;   
        if(p[mid] == val)
            return mid;
        else if(p[mid] < val)
            start = mid+1;
        else
            end = mid;
    }
    return -1;   
}







