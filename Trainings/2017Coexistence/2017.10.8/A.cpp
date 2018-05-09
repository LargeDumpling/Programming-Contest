#include<iostream>
#include<cstdio>
using namespace std;
int T_T;
int main()
{
	int a,b;
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",min(a*2+b,a+b*2));
	}
	return 0;
}

