#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int Pri[10050],en[10050];
int p,q,r,s;
void pre_prime()
{
	bool exist[10050];
	memset(exist,true,sizeof exist);
	for(int i=2;i<=10000;i++)
	{
		if(exist[i])Pri[++Pri[0]]=i;
		for(int j=1;j<=Pri[0]&&i*Pri[j]<=10000;j++)
		{
			exist[i*Pri[j]]=false;
			if(!(i%Pri[j]))break;
		}
	}
	return;
}
void add(int n,int d)
{
	int x;
	for(int i=2,j;i<=n;i++)
	{
		x=i;
		j=1;
		while(x>1)
		{
			while(!(x%Pri[j]))x/=Pri[j],en[j]+=d;
			j++;
		}
	}
	return;
}
double pOw(int x,int n)
{
	if(!n)return 1;
	double a=n<0?(double)1/x:x,ans=1;
	if(n<0)n=-n;
	for(;n;n>>=1,a*=a)if(n&1)ans*=a;
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double ans;
	pre_prime();
	while(scanf("%d%d%d%d",&p,&q,&r,&s)!=-1)
	{
		memset(en,0,sizeof(en));
		add(p,1);
		add(s,1);
		add(r-s,1);
		add(q,-1);
		add(p-q,-1);
		add(r,-1);
		ans=1;
		for(int i=1;i<=Pri[0];i++)ans*=pOw(Pri[i],en[i]);
		printf("%.5lf\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

