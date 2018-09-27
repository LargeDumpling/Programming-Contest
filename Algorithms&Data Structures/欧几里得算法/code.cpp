/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*
 * ax+by=gcd(a,b)=d
 */
void gcd(int a,int b,int &d,int &x,int &y)
{
	if(!b)
	{
		d=a;
		x=1;
		y=0;
	}
	else
	{
		gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

