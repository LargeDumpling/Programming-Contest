/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n;
double A[MAXN],B[MAXN],R[MAXN],f[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lf",&n,&f[0]);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&A[i],&B[i],&R[i]);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

