/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
	int d[3];
	bool ans=true;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&d[0],&d[1],&d[2]);
		for(int j=0;j<3;j++)
			if(d[(j+1)%3]+d[(j+2)%3]<=d[j])
				ans=false;
	}
	if(ans) puts("YES");
	else puts("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

