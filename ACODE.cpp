#include<iostream>
#include<string>

using namespace std;

int main()
{
    long a[5005];
    string s;
    int i,j;
    a[0]=1;
    a[1]=1;
    
    cin>>s;
    while(s!="0")
    {
        for(i=2;i<=s.size();i++)
        a[i]=0;
        
        for(i=1;i<s.size();i++)
        {
            if(s[i]!='0'&&s[i-1]!='0'&&s[i+1]!='0'&&(s[i]-'0'+(s[i-1]-'0')*10)<=26)
              a[i+1]=a[i]+a[i-1];
            else
              a[i+1]=a[i];
        }
        cout<<a[s.size()]<<endl;
        cin>>s;
    }
    

return 0;    
}
