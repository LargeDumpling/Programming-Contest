/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int N,x[4],y[4];
bool in(int t)
{
	if(t==0) return x[2]<=x[0]&&x[1]<=x[3]&&y[2]<=y[0]&&y[1]<=y[3];
	return x[0]<=x[2]&&x[3]<=x[1]&&y[0]<=y[2]&&y[3]<=y[1];
}
bool sep()
{
	return x[1]<x[2]||x[3]<x[0]||y[1]<y[2]||y[3]<y[0];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]);
		if(in(0)) puts("A in B");
		else if(in(1)) puts("B in A");
		else if(sep()) puts("Separate");
		else puts("Intersect");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

