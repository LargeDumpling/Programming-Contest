/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int num[10][5];
bool read1n()
{
	char tex[3];
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(scanf("%s",tex)==-1)return false;
			num[i][j]=tex[0];
		}
	}
	return true;
}
map<vector<int>,double>f;
double dp(vector<int>& stas,int rem)
{
	if(rem==0)return 1;
	if(f.count(stas)!=0)return f[stas];
	int tot=0;
	double sum=0;
	for(int i=1;i<=9;i++)if(stas[i]>0)
		for(int j=i+1;j<=9;j++)if(stas[j]>0)
			if(num[i][stas[i]]==num[j][stas[j]])
			{
				tot++;
				stas[i]--;stas[j]--;
				sum+=dp(stas,rem-2);
				stas[i]++;stas[j]++;
			}
	if(tot==0)return f[stas]=0;
	return f[stas]=sum/tot;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(read1n())
	{
		vector<int>stas(10,4);
		f.clear();
		printf("%.6lf\n",dp(stas,36));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

