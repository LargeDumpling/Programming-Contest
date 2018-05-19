/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1e9;
const int MAXN=100050;
int get_rand() { return (long long)rand()*rand()%mod; }
int with_neg() { return rand()%2*2-1; }
int n,m,ans[MAXN];
int a[MAXN],b[MAXN],bs[MAXN];
bool reset[MAXN];
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	memset(reset,false,sizeof(reset));
	freopen("Pro1.in","w",stdout);
	int k;
	//n=90001+rand()%10000; //0~100000
	n=2+rand()%99999; //0~100000
	m=2+get_rand()%(n-1); //2~100000
	k=rand();
	for(int i=0;i<n;i++)
		a[i]=get_rand()*with_neg();
	for(int i=0;i<m;i++)
		b[i]=get_rand()*with_neg();
	for(int i=m-1;i;i--)
		bs[i]=b[i]-b[i-1];
	for(int i=0;i<k;i++)
		reset[get_rand()%n]=true;
	for(int i=0,j=m;i<n;i++)
		if(reset[i]) j=1;
		else if(j<m) a[i]+=bs[j++];
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++)
		printf("%d%c",a[i],i==n-1?'\n':' ');
	for(int i=0;i<m;i++)
		printf("%d%c",b[i],i==m-1?'\n':' ');
	fclose(stdin);
	fclose(stdout);
	return 0;
}

