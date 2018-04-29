/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jz
{
	int fir;
	long long sec;
	jz(const int &F=0,const long long &S=0):fir(F),sec(S) { }
	bool operator<(const jz &X)const { return fir<X.fir; }
}A;
set<jz> s;
int N,S,V;
long long time=0;
int main()
{
	set<jz>::iterator it;
	V=0;
	scanf("%d%d",&N,&S);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%lld",&A.fir,&A.sec);
		if(A.fir<=S) V-=A.sec;
		else if(S<A.fir) V+=A.sec;
		s.insert(A);
	}
	A=jz(S,0);
	for(int i=1;i<=N;i++)
	{
		it=s.upper_bound(A);
		if(V<=0) it--;
		time+=abs(S-(it->fir));
		S=it->fir;
		if(V<=0) V+=it->sec;
		else V-=it->sec;
	}
	printf("%lld",time);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

