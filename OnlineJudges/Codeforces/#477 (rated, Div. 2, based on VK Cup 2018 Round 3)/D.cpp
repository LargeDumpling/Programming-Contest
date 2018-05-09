/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=300050;
int n,num[MAXN];
long long x1,x2;
struct jz
{
	int id;
	long long c,n1,n2;
	bool operator<(const jz &X)const
	{
		if(n1==X.n1) return n2<X.n2;
		return n1<X.n1;
	}
}s[MAXN];
int main()
{
	int ans;
	scanf("%d%lld%lld",&n,&x1,&x2);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i].c);
		s[i].id=i;
		s[i].n1=x1/s[i].c+(bool)(x1%s[i].c);
		s[i].n2=x2/s[i].c+(bool)(x2%s[i].c);
	}
	sort(s+1,s+n+1);
	ans=-1;
	for(int i=1;i<=n;i++)
		if(0<i-s[i].n1&&s[i-s[i].n1].n2<=i-s[i].n1)
		{
			ans=i;
			break;
		}
	if(ans!=-1)
	{
		puts("Yes");
		printf("%lld %lld\n",s[ans].n1,ans-s[ans].n1);
		for(int i=ans-s[ans].n1+1;i<=ans;i++)
			printf("%d ",s[i].id);
		putchar('\n');
		for(int i=1;i<=ans-s[ans].n1;i++)
			printf("%d ",s[i].id);
	}
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

