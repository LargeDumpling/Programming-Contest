/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
struct jz
{
	long long x,y;
	int typ;
	jz() { x=y=typ=0; }
}E[MAXN];
int n,h[MAXN],d[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
void maintain(int root) { d[root]=E[d[root<<1]].y<E[d[root<<1|1]].y?d[root<<1|1]:d[root<<1]; }
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	d[root]=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	return;
}
void change(int root,int p,int x)
{
	if(L[root]==R[root])
	{
		d[root]=x;
		return;
	}
	int mid=(L[root]+R[root])>>1;
	if(p<=mid) change(root<<1,p,x);
	else change(root<<1|1,p,x);
	maintain(root);
	return;
}
int lef_que(int root,int p,long long y)
{
	if(R[root]<=p)
	{
		if(L[root]==R[root]) return y<2LL*E[d[root]].y?d[root]:0;
		int ans=y<2LL*E[d[root<<1|1]].y?lef_que(root<<1|1,p,y):0;
		if(!ans) ans=y<2LL*E[d[root<<1]].y?lef_que(root<<1,p,y):0;
		return ans;
	}
	int mid=(L[root]+R[root])>>1,ans1=0;
	if(mid<p) ans1=lef_que(root<<1|1,p,y);
	if(!ans1) ans1=lef_que(root<<1,p,y);
	return ans1;
}
int rig_que(int root,int p,long long y)
{
	if(p<=L[root])
	{
		if(L[root]==R[root]) return y<2LL*E[d[root]].y?d[root]:0;
		int ans=y<2LL*E[d[root<<1]].y?rig_que(root<<1,p,y):0;
		if(!ans) ans=y<2LL*E[d[root<<1|1]].y?rig_que(root<<1|1,p,y):0;
		return ans;
	}
	int mid=(L[root]+R[root])>>1,ans1=0;
	if(p<=mid) ans1=rig_que(root<<1,p,y);
	if(!ans1) ans1=rig_que(root<<1|1,p,y);
	return ans1;
}
long long sqr(long long x) { return x*x; }
bool check(int a,int b,long long r) { return sqr(h[E[a].x]-h[E[b].x])+sqr(E[a].y-E[b].y)<sqr(r); }
template<typename Ty>
void read1n(Ty &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	h[0]=0;
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(E[i].typ);
		read1n(E[i].x);
		read1n(E[i].y);
		h[++h[0]]=E[i].x;
	}
	build(1,1,n);
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		E[i].x=lower_bound(h+1,h+h[0]+1,E[i].x)-h;
		if(E[i].typ==1) change(1,E[i].x,i);
		else
		{
			int l=lef_que(1,E[i].x,E[i].y),r=rig_que(1,E[i].x,E[i].y),ans=-1;
			if(ans==-1&&l!=0&&check(l,i,E[l].y))
			{
				ans=l;
				change(1,E[l].x,0);
			}
			if(ans==-1&&r!=0&&check(r,i,E[r].y))
			{
				ans=r;
				change(1,E[r].x,0);
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

