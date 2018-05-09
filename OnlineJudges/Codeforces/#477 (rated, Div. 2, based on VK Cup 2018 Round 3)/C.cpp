/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
long long n,m,v,l[MAXN],e[MAXN],x1,x2,Y1,y2;
int cl,ce,Q;
int main()
{
	int tn;
	long long t[10];
	scanf("%I64d%I64d%d%d%I64d",&n,&m,&cl,&ce,&v);
	for(int i=1;i<=cl;i++)
		scanf("%I64d",&l[i]);
	sort(l+1,l+cl+1);
	for(int i=1;i<=ce;i++)
		scanf("%I64d",&e[i]);
	sort(e+1,e+ce+1);
	scanf("%d",&Q);
	while(Q--)
	{
		int tt;
		scanf("%I64d%I64d%I64d%I64d",&x1,&Y1,&x2,&y2);
		tn=0;
		if(x1==x2) t[tn++]=abs(Y1-y2);
		tt=lower_bound(l+1,l+cl+1,Y1)-l;
		if(l[tt]==Y1&&tt<cl) t[tn++]=abs(x1-x2)+abs(y2-l[tt+1])+abs(Y1-l[tt+1]);
		if(tt<=cl) t[tn++]=abs(x1-x2)+abs(y2-l[tt])+abs(Y1-l[tt]);
		if(1<tt) t[tn++]=abs(x1-x2)+abs(y2-l[tt-1])+abs(Y1-l[tt-1]);

		tt=lower_bound(e+1,e+ce+1,Y1)-e;
		if(e[tt]==Y1&&tt<ce) t[tn++]=abs(x1-x2)/v+(bool)(abs(x1-x2)%v)+abs(y2-e[tt+1])+abs(Y1-e[tt+1]);
		if(tt<=ce) t[tn++]=abs(x1-x2)/v+(bool)(abs(x1-x2)%v)+abs(y2-e[tt])+abs(Y1-e[tt]);
		if(1<tt) t[tn++]=abs(x1-x2)/v+(bool)(abs(x1-x2)%v)+abs(y2-e[tt-1])+abs(Y1-e[tt-1]);

		sort(t,t+tn);
		printf("%I64d\n",t[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

