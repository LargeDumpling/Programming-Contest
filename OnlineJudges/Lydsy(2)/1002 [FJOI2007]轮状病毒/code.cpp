#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int num[55],ws;
	jp()
	{
		memset(num,ws=0,sizeof(num));
	}
}f[101];
int n;
void mul(jp &a,int p)
{
	for(int i=0;i<a.ws;i++)
		a.num[i]*=p;
	for(int i=0;i<a.ws;i++)
		if(a.num[i]>=10)
		{
			a.num[i+1]+=a.num[i]/10;
			a.num[i]%=10;
		}
	if(a.num[a.ws])a.ws++;
	return;
}
void next(int x)
{
	f[x]=f[x-1];
	mul(f[x],3);
	for(int i=0;i<f[x].ws;i++)
	{
		f[x].num[i]-=f[x-2].num[i];
		if(f[x].num[i]<0)
		{
			f[x].num[i]+=10;
			f[x].num[i+1]--;
		}
	}
	if(!f[x].num[f[x].ws-1])f[x].ws--;
	f[x].num[0]+=2;
	for(int i=0;f[x].num[i]>=10;i++)
	{
		f[x].num[i+1]++;
		f[x].num[i]-=10;
	}
	if(f[x].num[f[x].ws])f[x].ws++;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	if(n==1)
		printf("1");
	else if(n==2)
		printf("5");
	else
	{
		f[1].ws=f[2].ws=1;
		f[1].num[0]=1;
		f[2].num[0]=5;
		for(int i=3;i<=n;i++)
			next(i);
		for(int i=f[n].ws-1;i>=0;i--)
			printf("%c",f[n].num[i]+'0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

