/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d,e,ans;
int main()
{
	scanf("%d%d%d",&n,&d,&e);
	e*=5;
	ans=n;
	for(int i=0;i<=d&&e*i<=n;i++)
		ans=min(ans,(n-i*e)%d);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

