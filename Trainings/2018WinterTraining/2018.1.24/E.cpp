/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=131072;
const int MAXN=1000050;
struct jp
{
	int num,f,c;
	bool operator<(const jp &X)const { return num<X.num; }
}a[MAXN];
int n,m,num[MAXN],cnt[MAXN];
int d[M<<1];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int query1(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans=max(ans,d[L^1]);
		if(R&1) ans=max(ans,d[R^1]);
	}
	return ans;
}
void change1(int P,int x)
{
	d[P+=M]=x;
	for(P>>=1;P;P>>=1)
		d[P]=max(d[P<<1],d[P<<1|1]);
	return;
}
void calc(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1,i,j;
	calc(l,mid);
	calc(mid+1,r);
	sort(a+l,a+mid+1);
	sort(a+mid+1,a+r+1);
	i=l;
	for(j=mid+1;j<=r;j++)
	{
		while(i<=mid&&a[i].num<a[j].num)
		{
			cnt[a[i].f]+=a[i].c;
			i++;
		}
		a[j].c+=cnt[a[j].f-1];
	}
	for(i=l;i<=mid;i++)
		cnt[a[i].f]-=a[i].c;
	return;
}
int main()
{
	int mAx=0,ans=0;
	read1n(n);
	read1n(m);
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		a[i].num=num[i];
		a[i].f=query1(1,num[i]-1)+1;
		a[i].c=(int)(a[i].f==1);
		change1(num[i],a[i].f);
	}
	calc(1,n);
	for(int i=1;i<=n;i++)
	{
		if(mAx<a[i].f)
		{
			mAx=a[i].f;
			ans=0;
		}
		if(mAx==a[i].f)
			ans=(ans+a[i].c)%m;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

