/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Data
{
	long long x,y;
	Data(const long long &a=0,const long long &b=0):x(a),y(b){}
}data[400050];
int dcmp(const Data &a,const Data &b)
{
	long long k=a.y*b.x-a.x*b.y;
	if(k==0) return 0;
	return k<0?-1:1;
}
int n,m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

