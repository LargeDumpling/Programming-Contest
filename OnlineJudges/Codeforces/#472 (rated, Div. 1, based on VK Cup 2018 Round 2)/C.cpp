/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n;
int m[MAXN],s[MAXN],mn=0,hn=0;
double hei[MAXN];
bool cre[MAXN];
map<int,int> f;
int main()
{
	long long ans;
	memset(cre,false,sizeof(cre));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		s[i]=max(s[i-1],m[i]+1);
	}
	for(int i=n-1;i;i--)
		s[i]=max(s[i],s[i+1]-1);
	for(int i=1;i<=n;i++)
			ans+=(s[i]-m[i]-1);
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

