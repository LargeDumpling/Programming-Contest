/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-29	File created.
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
	freopen("K.out","r",stdin);
	int u,v,X=0;
	scanf("%d",&n);
	if(n==-1)
	{
		cerr<<"-1";
		return 0;
	}
	X=n;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		X^=u; X^=v;
	}
	if(X==0) cerr<<"Yes"<<endl;
	else
	{
		cerr<<"No"<<endl;
		return 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

