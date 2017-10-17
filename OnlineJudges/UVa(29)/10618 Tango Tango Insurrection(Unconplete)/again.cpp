/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct jp { int a,b,c,d; };
char str[100];
//上0 左1 右2 下3
const int UP=0;
const int LEFT=1;
const int RIGHT=2;
const int DOWN=3;
int f[100][4][4][4],lenth;
char pre[100][4][4][4];
bool exist[100][4][4][4];
bool moveable(int ls,int rs,int ln,int rn)
{
	if(ls!=ln&&rs!=rn) return false; //双脚不可同时移动
	if(ln!=0&&ln!=3&&rn==1) return false; //在左脚不在0,3时,右脚不可为1
	if(rn!=0&&rn!=3&&ln==2) return false; //在右脚不在0,3时,左脚不可为2
	return true;
}
void JP()
{
	jp u,v;
	int cur,ls,rs,sta,nsta,cost;//0无任何动作,1无移动,2移动到相邻,3移动到相对
	queue<jp> q;
	memset(f,127,sizeof(f));
	memset(exist,false,sizeof(exist));
	f[0][1][2][0]=0;
	q.push((jp) { 0,1,2,0 });
	while(q.size())
	{
		u=q.front(); q.pop();
		cur=u.a; ls=u.b; rs=u.c; sta=u.d;
		if(cur==lenth) continue;
		exist[cur][ls][rs][sta]=false;
		for(int ln=0;ln<4;ln++) for(int rn=0;rn<4;rn++) if(moveable(ls,rs,ln,rn))
		{
			if(str[cur+1]=='L'&&ln!=1&&rn!=1) continue; //未踩到
			if(str[cur+1]=='R'&&ln!=2&&rn!=2) continue; //未踩到
			if(ls==ln&&rs==rn)
			{
				if(str[cur+1]=='.') nsta=0;
			}
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin)
	freopen("code.out","w",stdout);
	while(true)
	{
		scanf("%s",str);
		if(str[0]=='#') continue;
		lenth=strlen(str);
		DP();
		print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

