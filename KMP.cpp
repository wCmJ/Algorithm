class Solution{
public:
    int kmp(const string &s1, const string &s2){
        vector<int> v(s2.size(), 0);
        v = getArrayList(s2);
        for(int i=0,j=0;i<s1.size();i++)
        {
            while(j>0 && s1[i] != s2[j])
                j = v[j-1];
            if(s1[i] == s2[j])
                j++;
            if(j == s2.size())
                return i - j + 1;
        }
        return -1;
    }
    vector<int> getArrayList(const string &s){
        vector<int> v(s.size(),0);
        for(int i = 1;i< s.size();i++)
        {
            int j = v[i-1];
            if(s[i] == s[j])
                v[i] = j+1;
            else
            {
                while(j>0 && s[i] != s[j])
                    j = v[j-1];
                v[i] = j;
            }                
        }
        return v;
    }
};
