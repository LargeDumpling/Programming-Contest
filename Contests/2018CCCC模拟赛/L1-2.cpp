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
int hh,mm;
int main()
{
	scanf("%d:%d",&hh,&mm);
	if(hh<12||(hh==12&&mm==0))
		printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
	else
	{
		hh-=12;
		if(mm) hh++;
		for(int i=1;i<=hh;i++) printf("Dang");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

