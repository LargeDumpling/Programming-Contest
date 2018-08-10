/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int id,sum;
	bool operator<(const jp &X)const
	{ return sum==X.sum?id<X.id:sum>X.sum; }
}stu[1050];
int n;
int main()
{
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		stu[i].sum=0;
		stu[i].id=i;
		for(int j=1;j<=4;j++)
		{
			scanf("%d",&x);
			stu[i].sum+=x;
		}
	}
	sort(stu+1,stu+n+1);
	for(int i=1;i<=n;i++) if(stu[i].id==1)
		printf("%d",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

