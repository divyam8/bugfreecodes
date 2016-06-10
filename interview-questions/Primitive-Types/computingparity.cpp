/*computing parity of very large nos of 64 bit integers */
#include<iostream>

using namespace std;


short parity(unsigned long x)
{
	short result=0;
	while(x)
	{
		result^=1;
		x&=(x-1); //drops the lsb of x
	}
	return result;
}
int main()
{
     long a=0111111111111111111111111111111111111111111111111111111111111111; 
     short b=parity(a); 
     cout<<endl;
     cout<<b;
	return 0;
}
