#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 131072
using namespace std;
int data[M<<1];
int n,Q;
void add(int pos,int x)
{
	data[pos+=M]+=x;
	for(pos>>=1;pos;pos>>=1)data[pos]=data[pos<<1]+data[pos<<1|1];
	return;
}
int query(int x)
{
	int sum=0;
	for(x+=M+1;x;x>>=1)if(x&1)sum+=data[x^1];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&data[M+i]);
	for(int i=n;i;i--)data[M+i]-=data[M+i-1];
	for(int i=M-1;i;i--)data[i]=data[i<<1]+data[i<<1|1];
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

