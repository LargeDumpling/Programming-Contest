#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int L[100050],R[100050],Ls[100050],Rs[100050],sum[100050],tag[100050],sz=1,n,m;
int num[100050];
int readln(int &x)
{
	bool a=false;char ch;
	x=0;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')a=true;
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	if(a)x=-x;
	return x;
}
void build_tree(int now,int l,int r)
{
	L[now]=l;
	R[now]=r;
	tag[now]=0;
	if(r>l)
	{
		Ls[now]=++sz;
		Rs[now]=++sz;
		build_tree(Ls[now],l,(l+r)>>1);
		build_tree(Rs[now],((l+r)>>1)+1,r);
		sum[now]=sum[Ls[now]]+sum[Rs[now]];
	}
	else
	{
		Ls[now]=0;
		Rs[now]=0;
		sum[now]=num[l];
	}
	return;
}
void down(int now)
{
	sum[Ls[now]]+=(R[Ls[now]]-L[Ls[now]]+1)*tag[now];
	sum[Rs[now]]+=(R[Rs[now]]-L[Rs[now]]+1)*tag[now];
	tag[Ls[now]]+=tag[now];
	tag[Rs[now]]+=tag[now];
	tag[now]=0;
	return;
}
void change(int now,int pos,int x)
{
	if(pos==L[now]&&pos==R[now])
	{
		sum[now]+=x;
		return;
	}
	down(now);
	if(pos<=R[Ls[now]])
		change(Ls[now],pos,x);
	else
		change(Rs[now],pos,x);
	sum[now]+=x;
	return;
}
void change(int now,int l,int r,int x)
{
	if(l<=L[now]&&R[now]<=r)
	{
		sum[now]+=(R[now]-L[now]+1)*x;
		tag[now]+=x;
		return;
	}
	down(now);
	if(l>R[Ls[now]])
		change(Rs[now],l,r,x);
	else if (r<=R[Ls[now]])
		change(Ls[now],l,r,x);
	else if(l<=R[Ls[now]]&&r>=R[Ls[now]])
		change(Ls[now],l,r,x),change(Rs[now],l,r,x);
	sum[now]=sum[Ls[now]]+sum[Rs[now]];
	return;
}
int query(int now,int pos)
{
	if(pos==L[now]&&pos==R[now])
		return sum[now];
	down(now);
	if(pos<=R[Ls[now]])
		return query(Ls[now],pos);
	return query(Rs[now],pos);
}
int query(int now,int l,int r)
{
	if(l<=L[now]&&R[now]<=r)
		return sum[now];
	down(now);
	if(l>R[Ls[now]])
		return query(Rs[now],l,r);
	else if(r<=R[Ls[now]])
		return query(Ls[now],l,r);
	return query(Ls[now],l,r)+query(Rs[now],l,r);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int opt,a,b,c;
	readln(n);
	readln(m);
	for(int i=1;i<=n;i++)
		readln(num[i]);
	build_tree(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&a,&b);	
			change(1,a,b);
		}
		else if(opt==2)
		{
			scanf("%d%d%d",&a,&b,&c);
			change(1,a,b,c);
		}
		else if(opt==3)
		{
			scanf("%d",&a);
			printf("%d\n",query(1,a));
		}
		else if(opt==4)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",query(1,a,b));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

