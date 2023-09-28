#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int flag = 0;
        int xd4 = 0;
        int kaza = 0;
        int zaza = 0;
        string str;
        cin>>str;
        
        for(int i=str.length()-1; i>=0; i--)
        {
            if(str[i]=='0' && xd4==0)
            {
                xd4 = 1;
                flag = 1;
                continue;
            }
            else if(str[i]=='0' && xd4==1)
            {
                xd4= 0;
                flag = 0;
                continue;
            }
            
            else if(str[i]=='1')
            {
                if(flag == 0)
                {
                    while(str[i]!='0' && i>= 0)
                    {
                        kaza++;
                        
                        if(str[i]=='0')
                        {
                            flag = 1;
                            break;
                        }
                        i--;
                    }
                }
                else
                {
                    while(str[i]!='0' && i>=0)
                    {
                        zaza++;
                        
                        if(str[i]=='0')
                        {
                            flag = 0;
                            break;
                        }
                        
                        i--;
                    }
                }
                
            }
        }
        cout<<kaza<<endl;
    }
    
}