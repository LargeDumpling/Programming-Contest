/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,m;
int d[MAXN*30],ch[MAXN*30][2],root[MAXN],sz=0;
int h[MAXN],num[MAXN];
void read1n(int &x)
{
	char ch;
	bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
		else if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
void add(int &now,int pre,int L,int R,int p,int x)
{
	now=++sz;
	memcpy(ch[now],ch[pre],sizeof(ch[pre]));
	d[now]=d[pre]+x;
	if(L==R) return;
	int mid=(L+R)>>1;
	if(p<=mid) add(ch[now][0],ch[pre][0],L,mid,p,x);
	else if(mid<p) add(ch[now][1],ch[pre][1],mid+1,R,p,x);
	return;
}
int query(int pre,int now,int L,int R,int k)
{
	if(L==R) return h[L];
	int mid=(L+R)>>1;
	if(k<=d[ch[now][0]]-d[ch[pre][0]]) return query(ch[pre][0],ch[now][0],L,mid,k);
	k-=(d[ch[now][0]]-d[ch[pre][0]]);
	return query(ch[pre][1],ch[now][1],mid+1,R,k);
}
int main()
{
	int l,r,k;
	read1n(n); read1n(m);
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		h[++h[0]]=num[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		num[i]=lower_bound(h+1,h+h[0]+1,num[i])-h;
		add(root[i],root[i-1],1,n,num[i],1);
	}
	for(int i=1;i<=m;i++)
	{
		read1n(l); read1n(r);
		read1n(k);
		printf("%d\n",query(root[l-1],root[r],1,n,k));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

