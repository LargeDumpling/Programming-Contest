/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
char name[30][20]={"Slime","Abdullah","Owl","Megistias","Alchemy","cdsmdy","znnfrom","kzzw","KUMA","AgentOrtize","DaiDaidetulong","Li","NMBGWBDZ","GCD","XJP","BXL","HLS","HJT","XXHH","JZM","JT"/*,"@@@@@@"*/,"Hugegun","Lesphere","Showson","2333"};
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int T=rand()%10+1,n,m,a,b;
	while(T--)
	{
		n=rand()%20+2;
		m=rand()%10+n;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++)
		{
			do
			{
				a=rand()%n+1;
			}while(i==a);
			printf("%s %s\n",name[i],name[a]);
		}
		for(int i=n+1;i<=m;i++)
		{
			do
			{
				a=rand()%n+1;
				b=rand()%n+1;
			}while(a==b);
			printf("%s %s\n",name[a],name[b]);
		}
	}
	printf("0 0");
	fclose(stdout);
	return 0;
}

