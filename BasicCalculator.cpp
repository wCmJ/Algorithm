class Solution{
public:
    int calculator(string &s){
        s += '\0';
        int flag[7][7] = {
            //1: pop 0:push -1:pair -2:wrong
	    //cur +  -  *  /  \0  (  )
	/*+*/    {1, 1, 0, 0, 1,  0, 1},
	/*-*/    {1, 1, 0, 0, 1,  0, 1},
	/***/    {1, 1, 1, 1, 1,  0, 1},
	/*/*/    {1, 1, 1, 1, 1,  0, 1},
	/*\0*/   {0, 0, 0, 0, -1, 0, -2},
	/*(*/    {0, 0, 0, 0, -2, 0, -1},
	/*)*/    {-2, -2, -2, -2, -2, -2, -2}
        };
        vector<char> vc{'+','-','*','/','\0','(',')'};
        vector<int> vi{0,1,2,3,4,5,6,7,8,9};
        stack<char> opeS;
        stack<int> numS;
        opeS.push('\0');
        int n = 0;
        while(!opeS.empty())
        {
            if(n<s.size()){
                if(find(vc.begin(),vc.end(),s[n]) != vc.end())// + - * / \0 ( )
                {
                    cal(s,n);
                    ++n;                                
                }
                else if(find(vi.begin(),vi.end(),s[n]-'0') != vi.end())// 0 - 9
                {
                    int sum = s[n] - '0';
                    while(n+1<s.size())
                    {
                        if(find(vi.begin(),vi.end(),s[n+1]-'0') != vi.end())
                        {
                            ++n;
                            sum = 10 * sum + (s[n]-'0');
                        }
                        else if(s[n+1] == ' '){
                            ++n;
                        }
                        else if(find(vc.begin(),vc.end(),s[n + 1]) != vc.end())  
                        {
                            ++n;
                            break;
                        }
                    }
                    numS.push(sum);
                }
                else if(s[n] == ' ')// ' '
                {
                    ++n;                                
                }                                   
            }        
        }
        return numS.top();
    }
    
    void cal(string &s, int n){
        int col = find(vc.begin(),vc.end(),s[n]) - vc.begin();
        while(!opeS.empty()){
            int row = find(vc.begin(),vc.end(),opeS.top()) - vc.begin();
            if(flag[row][col] == 1)
            {
                opeS.pop();
                int sum;
                int n2 = numS.top();
                numS.pop();
                int n1 = numS.top();
                numS.pop();
                switch(row){
                    case 0://+
                        sum = n1 + n2;
                        break;
                    case 1://-
                        sum = n1 - n2;
                        break;
                    case 2://*
                        sum = n1 * n2;
                        break;
                    case 3:///
                        sum = n1 / n2;
                        break;                
                }
                numS.push(sum);
            }
            else if(flag[row][col] == 0)
            {
                opeS.push(s[n]);
                break;
            }
            else if(flag[row][col] == -1)
            {
                opeS.pop();
                break;
            }
            else// -2:wrong
            {
                //
                break;
            }
        }            
    }















};
