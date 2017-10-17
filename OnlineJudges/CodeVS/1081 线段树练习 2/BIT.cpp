#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
int n,Q,f[100050];
void add(int pos,int x)
{
	for(;pos<100050;pos+=low(pos))f[pos]+=x;
	return;
}
int query(int x)
{
	int sum=0;
	for(;x;x-=low(x))sum+=f[x];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BIT.out","w",stdout);
	int a,b,c;
	scanf("%d",&n);
	a=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		add(i,b-a);
		a=b;
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,c);
			add(b+1,-c);
		}
		else
		{
			scanf("%d",&a);
			printf("%d\n",query(a));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

