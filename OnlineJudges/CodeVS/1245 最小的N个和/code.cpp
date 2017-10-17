/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-07-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,A[MAXN],B[MAXN];
int L[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) scanf("%d",&B[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

