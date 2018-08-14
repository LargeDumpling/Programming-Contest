/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10000050;
int dis[MAXN],dn=0,N=0;
char str[10];
bool check(int x)
{
	for(int i=0;i<x;i++)
		if(dis[i]!=dis[i+x])
			return false;
	for(int i=0;i<x;i++)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c') dis[i+dn]=-1;
		else if(str[0]=='f') dis[i+dn]=1;
		else if(str[0]=='s') dis[i+dn]=0;
		if(dis[i+dn]!=dis[i])
			return false;
	}
	return true;
}
int main()
{
	//determine the N
	bool flag1,flag2;
	dn=0;
	flag1=flag2=false;
	while(true)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c')
		{
			dis[dn++]=-1;
			flag1=true;
		}
		else if(str[0]=='f')
		{
			dis[dn++]=1;
			flag2=true;
		}
		else if(str[0]=='s')
			dis[dn++]=0;
		//cerr<<dn<<endl;
		if(flag1&&flag2&&dn%2==0&&check(dn/2))
		{
			//cerr<<"0"<<endl;
			N=max(N,dn/2);
			break;
		}
	}
	//cerr<<"1111"<<endl;
	puts("left");
	dn=0;
	flag1=flag2=false;
	while(true)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c')
		{
			dis[dn++]=-1;
			flag1=true;
		}
		else if(str[0]=='f')
		{
			dis[dn++]=1;
			flag2=true;
		}
		else if(str[0]=='s')
			dis[dn++]=0;
		//cerr<<dn<<endl;
		if(flag1&&flag2&&dn%2==0&&check(dn/2))
		{
			//cerr<<"0"<<endl;
			N=max(N,dn/2);
			break;
		}
	}
	//cerr<<"222 "<<N<<endl;
	N/=4;
	int mind=0,d=0;
	for(int i=0;i<4*N;i++)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c') d--;
		else if(str[0]=='f') d++;
		mind=min(mind,d);
	}
	d=0;
	while(d!=mind)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c') d--;
		else if(str[0]=='f') d++;
		mind=min(mind,d);
	}
	puts("left");
	fflush(stdout);
	mind=0,d=0;
	for(int i=0;i<4*N;i++)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c') d--;
		else if(str[0]=='f') d++;
		mind=min(mind,d);
	}
	d=0;
	while(d!=mind)
	{
		puts("forward");
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='c') d--;
		else if(str[0]=='f') d++;
		mind=min(mind,d);
	}
	puts("dig");
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

