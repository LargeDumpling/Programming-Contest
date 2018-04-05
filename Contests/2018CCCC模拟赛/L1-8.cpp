/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,d,h,m;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d %d:%d",&d,&h,&m);
		if((d--)==0) printf("%d %02d:%02d\n",0,h,m);
		else
		{
			if(d&1) h+=24;
			d>>=1;
			if(h&1) m+=60;
			h>>=1;
			m>>=1;
			printf("%d %02d:%02d\n",++d,h,m);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

