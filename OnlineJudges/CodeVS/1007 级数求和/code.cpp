/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
double s,k;
int n;
int main()
{
	scanf("%lf",&k);
	s=0;
	n=0;
	while(s<=k)
	{
		n++;
		s+=(double)1./n;
	}
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

