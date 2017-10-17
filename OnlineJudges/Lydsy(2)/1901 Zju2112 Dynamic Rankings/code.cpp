/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=4500000;
int n,m,num[10050];
int hash[20050],tot=0,s[20050];
int A[10050],B[10050],C[10050];
int sum[N],son[N][2],root[10050],sz=0;
int L[10050],R[10050],Ln,Rn;
int lowbit(int x) { return x&(-x); }
int find(int x) { return lower_bound(hash+1,hash+tot+1,x)-hash; }
void change(int pre,int &now,int l,int r,int pos,int x)
{
	now=++sz;
	sum[now]=sum[pre]+x;
	son[now][0]=son[pre][0];
	son[now][1]=son[pre][1];
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) change(son[pre][0],son[now][0],l,mid,pos,x);
	else change(son[pre][1],son[now][1],mid+1,r,pos,x);
	return;
}
int query(int l,int r,int K)
{
	if(l==r) return l;
	int cnt=0,mid=(l+r)>>1;
	for(int i=1;i<=Rn;i++) cnt+=sum[son[R[i]][0]];
	for(int i=1;i<=Ln;i++) cnt-=sum[son[L[i]][0]];
	if(K<=cnt)
	{
		for(int i=1;i<=Rn;i++) R[i]=son[R[i]][0];
		for(int i=1;i<=Ln;i++) L[i]=son[L[i]][0];
		return query(l,mid,K);
	}
	else
	{
		for(int i=1;i<=Rn;i++) R[i]=son[R[i]][1];
		for(int i=1;i<=Ln;i++) L[i]=son[L[i]][1];
		return query(mid+1,r,K-cnt);
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int t;
	char ord[3];
	scanf("%d%d",&n,&m);
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		s[++s[0]]=num[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d%d",ord,&A[i],&B[i]);
		if(ord[0]=='Q') scanf("%d",&C[i]);
		else s[++s[0]]=B[i],C[i]=-1;
	}
	sort(s+1,s+s[0]+1);
	tot=0;
	hash[++tot]=s[1];
	for(int i=2;i<=s[0];i++)
		if(s[i]!=s[i-1])
			hash[++tot]=s[i];
	for(int i=1;i<=n;i++)
	{
		t=find(num[i]);
		for(int j=i;j<=n;j+=lowbit(j))
			change(root[j],root[j],1,tot,t,1);
	}
	for(int i=1;i<=m;i++)
	{
		if(C[i]==-1)
		{
			t=find(num[A[i]]);
			for(int j=A[i];j<=n;j+=lowbit(j))
				change(root[j],root[j],1,tot,t,-1);
			t=find(num[A[i]]=B[i]);
			for(int j=A[i];j<=n;j+=lowbit(j))
				change(root[j],root[j],1,tot,t,1);
		}
		else
		{
			Ln=0; Rn=0; A[i]--;
			for(int j=A[i];j;j-=lowbit(j))
				L[++Ln]=root[j];
			for(int j=B[i];j;j-=lowbit(j))
				R[++Rn]=root[j];
			printf("%d\n",hash[query(1,tot,C[i])]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

