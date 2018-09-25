/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
const int MAXS=8000050;
int num[MAXN],last[MAXN];
int sum[MAXS],ch[MAXS][2],sz,ans;
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void change(int &now,int pre,int L,int R,int pos,int x)
{
	now=++sz;
	sum[now]=sum[pre]+x;
	memcpy(ch[now],ch[pre],sizeof(ch[pre]));
	if(L==R) return;
	int mid=(L+R)>>1;
	if(pos<=mid) change(ch[now][0],ch[pre][0],L,mid,pos,x);
	else change(ch[now][1],ch[pre][1],mid+1,R,pos,x);
	return;
}
void init()
{
	sz=ans=0;
}
int query(int L,int R)
{
}
int main()
{
	int T_T,L,R;
	for(int T=1;T<=T_T;T++)
	{
		init();
		read1n(n); read1n(m);
		for(int i=1;i<=n;i++)
			read1n(num[i]);
		root[n+1]=0;
		for(int i=n;i;i--)
		{
			change(root[i],root[i+1],1,n,i,1);
			if(last[num[i]])
				change(root[i],root[i],1,n,last[num[i]],-1);
		}
		printf("Case #%d:",T);
		for(int i=1;i<=m;i++)
		{
			read1n(l); l=(l+ans)%n+1;
			read1n(r); r=(r+ans)%n+1;
			printf(" %d",ans=query(l,r));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

