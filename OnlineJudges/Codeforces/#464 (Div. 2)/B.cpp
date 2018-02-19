/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int k;
long long n,a[100050],ans,ans_i;
int main()
{
	cin>>n>>k;
	ans=n+1;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		if(n%a[i]<ans)
		{
			ans=n%a[i];
			ans_i=i;
		}
	}
	cout<<ans_i<<" "<<n/a[ans_i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

