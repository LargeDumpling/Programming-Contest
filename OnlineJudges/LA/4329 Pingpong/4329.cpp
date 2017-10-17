#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
int n,a[20050],h1[100050],h2[100050];
int readln(int &x)
{
	bool a=false;
	char ch=getchar();
	x=0;
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')
			a^=1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(a)
		x=-x;
	return x;
}
void add(int x,int pos,int f[])
{
	while(pos<=100050)
	{
		f[pos]+=x;
		pos+=low(pos);
	}
	return;
}
int query(int pos,int f[])
{
	int ans=0;
	while(pos)
	{
		ans+=f[pos];
		pos-=low(pos);
	}
	return ans;
}
int main()
{
	int T,left,right;
	long long ans;
	readln(T);
	while(T--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(h1,0,sizeof(h1));
		memset(h1,0,sizeof(h2));
		readln(n);
		for(int i=1;i<=n;i++)
		{
			readln(a[i]);
			add(1,a[i],h2);
		}
		for(int i=1;i<=n;i++)
		{
			add(-1,a[i],h2);
			right=query(a[i],h2);
			left=query(a[i],h1);
			add(1,a[i],h1);
			ans+=left*(n-i-right)+(i-left-1)*right;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

