#include<iostream>
using namespace std;
unsigned long long n,m;
int main()
{
	while(true)
	{
		cin>>n>>m;
		if(!n&&!m)
			break;
		if(n>m)
		{
			n+=m;
			m=n-m;
			n-=m;
		}
		cout<<n*m*(n+m-2)+(2*n*(n-1)*(3*m-n-1))/3<<"\n";
	}
	return 0;
}

