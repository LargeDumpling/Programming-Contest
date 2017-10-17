/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,A[MAXN],B[MAXN],pos[MAXN],s[MAXN];
struct jp
{
	int fir,sec;
	jp(const int &A=0,const int &B=0):fir(A),sec(B){}
	bool operator<(const jp &X)const { return fir<X.fir; }
}num[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		pos[A[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&B[i]);
		num[i]=jp(i,pos[B[i]]);
	}
	sort(num+1,num+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(!s[0]||s[s[0]]<num[i].sec) s[++s[0]]=num[i].sec;
		else *lower_bound(s+1,s+s[0]+1,num[i].sec)=num[i].sec;
	}
	printf("%d",s[0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

