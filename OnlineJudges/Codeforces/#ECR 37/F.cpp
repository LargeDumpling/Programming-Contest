/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
const int MAXM=1000050;
int n,m,num[MAXN];
int nExt[MAXM],pri[1050];
int d[MAXN<<2];
bool exist[1050],tag[MAXN<<2];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<1050;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&pri[j]*i<1050;j++)
		{
			exist[pri[j]*i]=false;
			if(!(i%pri[j]))
				break;
		}
	}
	for(int i=1;i<MAXM;i++)
	{
		int x=i,cnt,ans=1;
		for(int j=1;pri[j]*pri[j]<=x;j++)
		{
			cnt=0;
			while(!(x%pri[j]))
			{
				x/=pri[j];
				cnt++;
			}
			ans*=(cnt+1);
		}
		if(x!=1)
			ans*=2;
		nExt[i]=ans;
	}
	return;
}
void build(int root,int L,int R)
{
	if(L==R)
	{
		d[root]=num[L];
		return;
	}
	int mid=(L+R)>>1;
	build(root<<1,L,mid);
	build(root<<1|1,mid+1,R);
	d[root]=d[root<<1]+d[root<<1|1];
	return;
}
void change(int root,int L,int R,int l,int r)
{
	if(tag[root]) return;
	if(L==R)
	{
		d[root]=nExt[d[root]];
		if(d[root]==nExt[d[root]])
			tag[root]=true;
		return;
	}
	int mid=(L+R)>>1;
	if(l<=mid) change(root<<1,L,mid,l,r);
	if(mid<r) change(root<<1|1,mid+1,R,l,r);
	d[root]=d[root<<1]+d[root<<1|1];
	tag[root]=tag[root<<1]&tag[root<<1|1];
	return;
}
int query(int root,int L,int R,int l,int r)
{
	if(l<=L&&R<=r) return d[root];
	int mid=(L+R)>>1,ans=0;
	if(l<=mid) ans+=query(root<<1,L,mid,l,r);
	if(mid<r) ans+=query(root<<1|1,mid+1,R,l,r);
	return ans;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int t,l,r;
	pre_calc();
	read1n(n);
	read1n(m);
	for(int i=1;i<=n;i++)
		read1n(num[i]);
	build(1,1,n);
	while(m--)
	{
		read1n(t);
		read1n(l);
		read1n(r);
		if(t==1) change(1,1,n,l,r);
		else printf("%d\n",query(1,1,n,l,r));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

