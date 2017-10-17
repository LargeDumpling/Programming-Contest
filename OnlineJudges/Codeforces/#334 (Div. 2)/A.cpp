/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-04	File created.
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
	double m[6],w[6],s[6]={0,500,1000,1500,2000,2500},hs,hw,ans=0,now;
	cin>>m[1]>>m[2]>>m[3]>>m[4]>>m[5]>>w[1]>>w[2]>>w[3]>>w[4]>>w[5]>>hs>>hw;
	for(int i=1;i<=5;i++)
	{
		now=0;
		now=max(0.3*s[i],s[i]*(250-m[i])/250-50.*w[i]);
		ans+=now;
	}
	ans=ans+100.*hs-50.*hw;
	printf("%.0f",ans);
	return 0;
}

