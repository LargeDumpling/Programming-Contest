/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	long long n,k,A,B,ans=0;
	cin>>n>>k>>A>>B;
	if(k==1) ans=(n-1LL)*A;
	else while(n!=1)
	{
		if(n<k)
		{
			ans+=(n-1LL)*A;
			n=1;
		}
		else if(n%k)
		{
			ans+=n%k*A;
			n-=n%k;
		}
		else
		{ //n%k==0
			long long tem=n/k;
			ans+=min(B,(n-tem)*A);
			n=tem;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

