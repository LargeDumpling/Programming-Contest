#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long C[55][55],ans;
int l,k;
void pre_calc()
{
	C[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
				C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	return;
}
int main()
{
	pre_calc();
	scanf("%d%d",&l,&k);
	for(int t=1;2*t-1<=l;t++)
	{
		int rem=(l-2*t+1)/(k-1);
		for(int i=0;i<=rem&&i<=t;i++)
			ans+=C[t][i];
	}
	cout<<ans;
	return 0;
}

