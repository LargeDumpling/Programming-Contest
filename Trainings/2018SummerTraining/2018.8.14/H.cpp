/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXS=4000000;
const int MAXN=128050;
int size[MAXS],son[MAXS][2],root[MAXN],X[MAXN],h[MAXN],A[MAXN],B[MAXN],n,m,sz;
long long sum[MAXS],S[2][MAXN];
template<typename Ty>
inline void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
inline void change(int last,int &now,int L,int R,int p)
{
	now=++sz;
	size[now]=size[last]+1;
	sum[now]=sum[last]+h[p];
	if(L==R) return;
	memcpy(son[now],son[last],sizeof(son[last]));
	int mid=(L+R)>>1;
	if(p<=mid) change(son[last][0],son[now][0],L,mid,p);
	else change(son[last][1],son[now][1],mid+1,R,p);
	return;
}
inline long long rquery(int last,int now,int L,int R,int k)
{
	if(k<=0) return 0;
	if(size[now]-size[last]<=k) return sum[now]-sum[last];
	if(L==R) return h[L]*k;
	int mid=(L+R)>>1;
	long long ans=0;
	if(son[now][1]) ans=rquery(son[last][1],son[now][1],mid+1,R,min(k,size[son[now][1]]-size[son[last][1]]));
	if(size[son[now][1]]-size[son[last][1]]<=k)
	{
		k-=(size[son[now][1]]-size[son[last][1]]);
		if(son[now][0]) ans+=rquery(son[last][0],son[now][0],L,mid,k);
	}
	return ans;
}
inline long long lquery(int last,int now,int L,int R,int k)
{
	if(k<=0) return 0;
	if(size[now]-size[last]<=k) return sum[now]-sum[last];
	if(L==R) return h[L]*k;
	int mid=(L+R)>>1;
	long long ans=0;
	if(son[now][0]) ans+=lquery(son[last][0],son[now][0],L,mid,min(k,size[son[now][0]]-size[son[last][0]]));
	if(size[son[now][0]]-size[son[last][0]]<=k)
	{
		k-=(size[son[now][0]]-size[son[last][0]]);
		if(son[now][1]) ans+=lquery(son[last][1],son[now][1],mid+1,R,k);
	}
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int l,r;
	double ans;
	read1n(n);
	S[0][0]=S[1][0]=h[0]=sz=0;
	for(int i=1;i<=n;i++)
		read1n(A[i]);
	for(int i=1;i<=n;i++)
	{
		read1n(B[i]);
		S[0][i]=S[0][i-1]+A[i]-B[i];
		h[++h[0]]=A[i]-B[i];
		S[1][i]=S[1][i-1]+B[i]*2LL;
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		X[i]=lower_bound(h+1,h+h[0]+1,A[i]-B[i])-h;
		change(root[i-1],root[i],1,h[0],X[i]);
	}
	read1n(m);
	while(m--)
	{
		read1n(l); read1n(r);
		long long ans1=lquery(root[l-1],root[r],1,h[0],(r-l+1)/3),ans2=rquery(root[l-1],root[r],1,h[0],(r-l+1)/3);
		ans=S[1][r]-S[1][l-1]+S[0][r]-S[0][l-1]+ans2-ans1;
		printf("%lf\n",ans/2.);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

