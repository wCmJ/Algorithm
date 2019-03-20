
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









