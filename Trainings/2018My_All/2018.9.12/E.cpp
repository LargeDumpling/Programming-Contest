/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,m,p[MAXN];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
bool check(int x)
{
	int cnt=0,last=-1000000;
	for(int i=1;i<=n;i++) if(x<=(p[i]-last))
	{
		last=p[i];
		cnt++;
	}
	return m<=cnt;
}
int main()
{
	int l,mid,r;
	while(true)
	{
		read1n(n);
		read1n(m);
		if(!n&&!m) break;
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		sort(p+1,p+n+1);
		l=0; r=1000001;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%d\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

