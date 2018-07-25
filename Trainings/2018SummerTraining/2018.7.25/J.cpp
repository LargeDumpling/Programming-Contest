/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,x,y,h[MAXN],a[MAXN];
long long t[MAXN];
inline int low(int xx) { return xx&(-xx); }
bool read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return false;
		else if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return true;
}
void change(int p)
{
	for(;p;p-=low(p))
		t[p]++;
	return;
}
long long query(int p)
{
	long long ans=0;
	for(;p<MAXN;p+=low(p))
		ans+=t[p];
	return ans;
}
int main()
{
	long long cnt=0;
	while(read1n(n))
	{
		memset(t,0,sizeof(t));
		cnt=0;
		read1n(x); read1n(y);
		h[0]=0;
		for(int i=1;i<=n;i++)
		{
			//scanf("%d",&a[i]);
			read1n(a[i]);
			h[++h[0]]=a[i];
		}
		sort(h+1,h+h[0]+1);
		h[0]=unique(h+1,h+h[0]+1)-h-1;
		for(int i=1;i<=n;i++)
		{
			a[i]=lower_bound(h+1,h+h[0]+1,a[i])-h;
			cnt+=query(a[i]+1);
			change(a[i]);
		}
		printf("%lld\n",cnt*min(x,y));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

