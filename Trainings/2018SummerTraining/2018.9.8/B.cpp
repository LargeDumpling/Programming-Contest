/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int L[MAXN],R[MAXN],ch[MAXN][2],typ[MAXN],sz=0;
//0 +
//1 *
//2 d
int len;
long long data[MAXN][2];
char str[105];
int read1n(int l,int r)
{
	int x=0;
	for(int i=l;i<=r;i++)
		x=x*10+str[i]-'0';
	return x;
}
int build(int l,int r)
{
	int Ro=sz++;
	L[Ro]=l;
	R[Ro]=r;
	int cnt=0,fm=-1,fp=-1,fd=-1,fj=-1;
	for(int i=l;i<=r;i++)
	{
		if(str[i]=='(') cnt++;
		else if(str[i]==')') cnt--;
		else if(cnt!=0) continue;
		else if(str[i]=='+') fp=i;
		else if(str[i]=='-') fj=i;
		else if(str[i]=='*') fm=i;
		else if(str[i]=='d') fd=i;
	}
#define lson ch[Ro][0]
#define rson ch[Ro][1]
	if(fp!=-1)
	{
		typ[Ro]=0;
		lson=build(l,fp-1);
		rson=build(fp+1,r);
		data[Ro][0]=data[lson][0]+data[rson][0];
		data[Ro][1]=data[lson][1]+data[rson][1];
	}
	else if(fj!=-1)
	{
		typ[Ro]=0;
		lson=build(l,fj-1);
		rson=build(fj+1,r);
		data[Ro][0]=data[lson][0]-data[rson][1];
		data[Ro][1]=data[lson][1]-data[rson][0];
	}
	else if(fm!=-1)
	{
		typ[Ro]=1;
		ch[Ro][0]=build(l,fm-1);
		ch[Ro][1]=build(fm+1,r);
		data[Ro][0]=min(min(data[lson][0]*data[rson][0],data[lson][0]*data[rson][1])
				,min(data[lson][1]*data[rson][0],data[lson][1]*data[rson][1]));
		data[Ro][1]=max(max(data[lson][0]*data[rson][0],data[lson][0]*data[rson][1])
				,max(data[lson][1]*data[rson][0],data[lson][1]*data[rson][1]));
	}
	else if(fd!=-1)
	{
		typ[Ro]=2;
		ch[Ro][0]=build(l,fd-1);
		ch[Ro][1]=build(fd+1,r);
		data[Ro][0]=data[lson][0];
		data[Ro][1]=data[lson][1]*data[rson][1];
	}
#undef lson
#undef rson
	else if(str[l]=='(') Ro=build(l+1,r-1);
	else data[Ro][0]=data[Ro][1]=read1n(l,r);
	return Ro;
}
int main()
{
	int root;
	while(scanf("%s",str)!=EOF)
	{
		sz=0;
		len=strlen(str);
		root=build(0,len-1);
		printf("%lld %lld\n",data[root][0],data[root][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

