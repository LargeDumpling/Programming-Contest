/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[25],n,k;
void gen_prime();
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	gen_prime();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

