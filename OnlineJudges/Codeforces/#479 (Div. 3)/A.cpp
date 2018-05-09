/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	while(k--)
	{
		if(n%10) n--;
		else n/=10;
	}
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

