/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp *null;
struct jp
{
	int key,size,r;
	jp *son[2];
	jp(const int &x)
	{
		key=x;
		size=1;
		r=rand();
		son[0]=son[1]=null;
	}
}root;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

