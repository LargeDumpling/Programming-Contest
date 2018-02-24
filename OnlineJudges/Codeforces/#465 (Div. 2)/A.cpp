/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-19	File created.
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
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++) if(n%i==0)
	{
		if(i==1||i*i==n) cnt++;
		else cnt+=2;
	}
	printf("%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

