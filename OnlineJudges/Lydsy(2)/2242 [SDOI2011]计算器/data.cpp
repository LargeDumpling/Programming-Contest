/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pri[100050];
bool exist[100050];
void pre_calc()
{
	pri[0]=0;
	memset(exist,true,sizeof(exist));
	for(int i=2;i<=100000;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=100000;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0) break;
		}
	}
	return;
}
int Rand() { return 1LL*rand()*rand()*rand()%2147483648LL; }
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	pre_calc();
	int T_T=rand()%10,type=rand()%3+1;
	printf("%d %d\n",T_T,type);
	while(T_T--)
		printf("%d %d %d\n"
				,Rand()%1000000000+1,rand()%1000000000+1,pri[rand()%pri[0]+1]);
	fclose(stdout);
	return 0;
}

