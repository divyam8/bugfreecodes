#include <bits/stdc++.h>
#define ll long long int
using namespace std;   
 
void reverse(char* ,char *);

void  reversewords(char *s)
{
     char *word_begin=s;
     char *temp=s;

     //reverse the individual words in the string 
     while( *temp )
     {
        temp++;
        if (*temp == '\0')
        {
             reverse(word_begin, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
     } 
 
   //reverse the whole string 
  reverse(s, temp-1);
}

void reverse(char *begin,char *end)
{
     char temp;
     while(begin<end)
     {
     	temp=*begin;
     	*begin++=*end;
     	*end--=temp;
     }
}


int main()
{
    //ios_base::sync_with_stdio(false); 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t,i,j,k,r,n,m,q,x;
    ll sum,finalsum;
    scanf("%lld",&t);
    ll ans=0;
    string s;
    while(t--)
    {
        char s[]={"I like my Mumma very much"};
        char *temp=s;
        reversewords(s);
        cout<<s;

    }
    
    return 0;
}
