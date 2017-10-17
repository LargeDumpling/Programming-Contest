#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
long long num[100050],n,q;
long long f[2][100050];
void add(int now,int pos,int x)
{
	for(;pos<200050;pos+=low(pos))
		f[now][pos]+=x;
	return;
}
long long query(int now,int pos)
{
	long long sum=0;
	for(;pos;pos-=low(pos))sum+=f[now][pos];
	return sum;
}
long long calc(int x)
{
	return (x+1)*query(0,x)-query(1,x);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BIT.out","w",stdout);
	int a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=n;i;i--)
	{
		num[i]-=num[i-1];
		add(0,i,num[i]);
		add(1,i,i*num[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(0,a,c);
			add(0,b+1,-c);
			add(1,a,a*c);
			add(1,b+1,(b+1)*(-c));
		}
		else
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",calc(b)-calc(a-1));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

