/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
long long n,m,k,a,b,c,ans;
long long calc(long long x)
{
	long long sum=1e18;
	for(int i=0;i*3<=x+2;i++)
		sum=min(sum,i*b+(max(0LL,x-i*3LL)+1)/2LL*a);
	return sum;
}
int main()
{
	cin>>T_T;
	while(T_T--)
	{
		ans=1e18;
		cin>>n>>m>>k>>a>>b>>c;
		for(int i=0;i<=k;i++)
			ans=min(ans,c*i+calc(n+k-i)+calc(m+k-i));
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

