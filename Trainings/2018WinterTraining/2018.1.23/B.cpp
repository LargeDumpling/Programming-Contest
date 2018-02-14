/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[1050],n;
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int x,y;
	bool exist[10];
	while(scanf("%d",&n)!=-1)
	{
		num[0]=0;
		for(int i=1;i<=n;i++)
		{
			memset(exist,false,sizeof(exist));
			scanf("%d",&x);
			y=0;
			for(;x;x/=10)
				y|=(1<<(x%10-1));
			num[++num[0]]=y;
		}
		sort(num+1,num+num[0]+1);
		num[0]=unique(num+1,num+num[0]+1)-num-1;
		printf("%d\n",num[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

