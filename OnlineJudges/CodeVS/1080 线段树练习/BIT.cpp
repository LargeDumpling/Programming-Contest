#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
long long f[100050];
void add(int pos,int x)
{
	for(;pos<100050;pos+=low(pos))
		f[pos]+=x;
	return;
}
int query(int x)
{
	int sum=0;
	for(;x;x-=low(x))
		sum+=f[x];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BIT.out","w",stdout);
	int n,m,a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		add(i,b);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
			add(b,c);
		else
			printf("%d\n",query(c)-query(b-1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

