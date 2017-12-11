/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-11-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,a,b[MAXN];
long long sum;
int main()
{
	sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum+=a;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	b[0]=0;
	if(sum<=b[n]+b[n-1])
		puts("YES");
	else
		puts("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

