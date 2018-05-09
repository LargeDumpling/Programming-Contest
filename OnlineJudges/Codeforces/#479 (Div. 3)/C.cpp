/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,k;
int num[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	if(k<n&&num[k]==num[k+1]) num[k]=-1;
	if(k==0)
	{
		num[0]=num[1]-1;
		if(num[0]<=0) num[0]=-1;
	}
	printf("%d",num[k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

