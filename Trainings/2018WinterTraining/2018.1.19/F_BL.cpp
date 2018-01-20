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
int idx[3];
int main()
{
	int x,cnt=0;
	for(int i=1;i<=123;i++)
	{
		x=i;
		idx[0]=x%10;
		x/=10;
		idx[1]=x%10;
		x/=10;
		idx[2]=x;
		if(idx[0]>=idx[1]&&idx[1]>=idx[2])
		{
			printf("%d\n",i);
			cnt++;
		}
	}
	printf("\n%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

