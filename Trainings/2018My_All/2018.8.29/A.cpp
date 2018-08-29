/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
//const int M=16384;
const int M=8;
int T_T,n,Q,k,num[MAXN];
int d[M<<1][65];
void maintain(int *D,int *L,int *R)
{
	D[0]=L[0]+R[0];
	for(int i=1;i<=D[0];i++)
		D[i]=i<=L[0]?L[i]:R[i-L[0]];
	for(int i=1;i<=D[0];i++)
	{
		for(int j=i+1;j<=D[0];j++) if((D[j]>>i)&1)
		{
			swap(D[i+1],D[j]);
			break;
		}
		if(!((D[i+1]>>i)&1))
		{
			D[0]=i;
			break;
		}
		for(int j=1;j<=D[0];j++)
			if(j!=i+1&&((D[j]>>i)&1))
				D[j]^=D[i+1];
	}
	return;
}
void build()
{
	for(int i=1;i<=n;i++)
	{
		int *D=d[i+M];
		D[D[0]=1]=num[i];
	}
	for(int i=M-1;i;i--)
		maintain(d[i],d[i<<1],d[i<<1|1]);
	return;
}
int query(int L,int R)
{
	int ans[65],K=k;
	memset(ans,0,sizeof(ans));
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) maintain(ans,ans,d[L^1]);
		if(R&1) maintain(ans,ans,d[R^1]);
	}
	for(int i=0;i<30&&i<ans[0];i++) if(!((K>>i)&1))
		K^=ans[i+1];
	return K;
}
int main()
{
	freopen("in.txt","r",stdin);
	int L,R;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d%d",&n,&Q,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		build();
		while(Q--)
		{
			scanf("%d%d",&L,&R);
			printf("%d\n",query(L,R));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

