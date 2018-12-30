#include<string>
int LongestCommanSubsequence(const std::string &s1, const std::string &s2)
{
    int len = 0;
    int len1 = s1.size();
    int len2 = s2.size();
    
    //initialize
    int **p = new int*[len1+1];
    for(int i=0;i<len1+1;i++)
    {
        p[i] = new int[len2+1];
        if(i == 0)
        {
            for(int j = 0;j<len2+1;j++)    
                p[i][j] = 0;
        }
        p[i][0] = 0;                
    }

    //compute
    for(int i=1;i<len1+1;i++)
        for(int j=1;j<len2+1;j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                p[i][j] = p[i-1][j-1];            
            }
            else
            {
                p[i][j] = p[i][j-1]>p[i-1][j]?p[i][j-1]:p[i-1][j];
            }        
        }
    //delete
    len = p[len1][len2];
    for(int i=0;i<len1+1;i++)
    {
        delete[] p[i];    
    }
    delete[] p;
    return len;
}
