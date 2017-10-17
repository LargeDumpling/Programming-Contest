/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
char tex[10];
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int T=rand()%10+1;
	while(T--)
	{
		int lenth=rand()%5+1,k=0;
		while(k<lenth) tex[k++]=rand()%5+'a';
		lenth=rand()%10+1;
		for(int i=0;i<lenth;i++) printf("%s",tex);
		putchar('\n');
	}
	fclose(stdout);
	return 0;
}

