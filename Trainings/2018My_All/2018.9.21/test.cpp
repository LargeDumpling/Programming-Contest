/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAXN=10000050;
vector<int> a,b;
int main()
{
	double t0=(double)clock(),t1,t2;
	for(int i=0;i<10000000;i++) a.push_back(0);
	t1=(double)clock();
	b.reserve(MAXN);
	for(int i=0;i<10000000;i++) b.push_back(0);
	t2=(double)clock();
	cerr<<(t1-t0)/CLOCKS_PER_SEC<<endl<<(t2-t1)/CLOCKS_PER_SEC<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

