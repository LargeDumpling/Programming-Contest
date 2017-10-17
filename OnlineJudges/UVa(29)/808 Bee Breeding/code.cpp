/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pos[10050][2];
int rank(int x)
{
	int sum=0;
	x-=2;
	x=(x/6)+1;
	for(int i=1;sum<x;i++)
	{
		sum+=i;
		if(x<=sum)return i;
	}
	return 0;
}
int num(int x){return 3*x*(x+1)+1;}
int move[6][2]={{-1,-1},{-1,1},{0,2},{1,1},{1,-1},{0,-2}};
void pre_calc_pos()
{
	int x;
	pos[1][0]=pos[1][1]=pos[2][0]=0;
	pos[2][1]=-2;
	for(int i=2;i<10000;i++)
	{
		x=rank(i);//i位于第几层
		x=(i-num(x-1))/x;//x应以哪种方式移动
		if(x==6)x=5;
		pos[i+1][0]=pos[i][0]+move[x][0];
		pos[i+1][1]=pos[i][1]+move[x][1];
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,ans,x,y;
	pre_calc_pos();
	/*for(int i=1;i<=1000;i++)
		printf("%d:(%d,%d)\n",i,pos[i][0],pos[i][1]);*/
	while(scanf("%d%d",&a,&b)!=-1&&a&&b)
	{
		x=abs(pos[a][0]-pos[b][0]);
		y=abs(pos[a][1]-pos[b][1]);
		ans=x;
		y-=x;
		if(y>0)ans+=y/2;
		printf("The distance between cells %d and %d is %d.\n",a,b,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

