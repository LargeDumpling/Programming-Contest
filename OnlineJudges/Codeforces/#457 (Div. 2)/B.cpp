/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long n;
int k,num[130],zero=65;
int main()
{
	int cnt=0;
	cin>>n>>k;
	for(int i=60;0<=i;i--)
		if((n>>i)&1)
			num[i+zero]++,cnt++;
	k-=cnt;
	if(k<0) puts("NO");
	else
	{
		puts("YES");
		for(int i=60;-60<=i&&k;i--) if(num[i+zero])
		{
			if(k<=num[i+zero])
			{
				num[i+zero-1]+=(k<<1);
				num[i+zero]-=k;
				k=0;
			}
			else if(num[i+zero]<k)
			{
				num[i+zero-1]+=(num[i+zero]<<1);
				k-=num[i+zero];
				num[i+zero]=0;
			}
		}
		for(int i=60;-60<=i;i--)
			while(num[i+zero]--)
				printf("%d ",i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

