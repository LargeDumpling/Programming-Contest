/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
unsigned long long ans=0,n,k,m;
int main()
{
	freopen("chess.in","r",stdin);
	scanf("%d",&T_T);
	while(T_T--)
	{
		cin>>n>>k;
		m=(n-1)/(k+1);
		ans=2ULL*m*n-m*(m+1ULL)*(k+1ULL)+n;
		ans=n*n-ans;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

