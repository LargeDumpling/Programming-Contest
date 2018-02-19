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
int n,f[5050];
int main()
{
	bool ans=false;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
		ans|=(f[f[f[i]]]==i);
	if(ans) puts("YES");
	else puts("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

