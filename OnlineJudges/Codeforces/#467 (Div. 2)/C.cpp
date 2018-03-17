/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long k,d,t;
double ans=0;
int main()
{
	unsigned long long sing,len;
	cin>>k>>d>>t;
	if(k%d==0) ans=t;
	else
	{
		t*=2ULL;
		len=d*(k/d+1ULL);
		sing=k*2ULL+(len-k);
		double tm=t/sing;
		ans=tm*len;
		t%=sing;
		if(t<=k*2.)
			ans+=(double)t/2.;
		else
			ans+=(t-k);
	}
	printf("%.1lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

