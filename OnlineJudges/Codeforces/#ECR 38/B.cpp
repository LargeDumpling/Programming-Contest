/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long INF=(1LL<<62)-1LL+(1LL<<62);
int n;
long long s[MAXN],ans=INF;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	ans=min(s[n]-1,1000000-s[1]);
	for(int i=1;i<n;i++)
		ans=min(ans,max(s[i]-1,1000000-s[i+1]));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

