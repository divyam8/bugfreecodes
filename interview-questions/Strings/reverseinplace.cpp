#include<iostream>

using namespace std;

string reverse(string s)
{
   int len=s.size();
   for(int i=0;i<len/2;i++)
   {
     swap(s[i],s[len-i-1]);
   }
   return s; 
}
int main()
{
char s[]="DivyamKhandelwal";
string rev_string=reverse(s);
cout<<rev_string;
return 0;
}
