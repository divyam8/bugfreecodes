#include<iostream>
#include<cstring>
using namespace std;
bool hasuniquechs(string s)
{
   bool chs[256]; //ascii string
   memset(chs,false,sizeof chs);
  
   for(int i=0;i<s.size();i++)
   {
      if(chs[s[i]])
        return false;
      chs[s[i]]=true; 
   }
    return true;
}
int main()
{
char s[]="DivyamKhandelwal";
if(hasuniquechs(s))
cout<<"Unique Characters";
else 
cout<<"String does not contain unique characters";
return 0;
}
