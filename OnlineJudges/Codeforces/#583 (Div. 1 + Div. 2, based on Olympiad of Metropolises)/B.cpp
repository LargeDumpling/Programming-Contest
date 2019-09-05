/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int b,g,n;
int main()
{
	scanf("%d%d%d",&b,&g,&n);
	if(n<=b&&n<=g) printf("%d",n+1);
	else if(b<n&&g<n) printf("%d",b-n+g+1);
	else printf("%d",min(b,g)+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

