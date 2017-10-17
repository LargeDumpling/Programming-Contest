/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int fir,sec;
	jp(int a=0,int b=0):fir(a),sec(b){}
	bool operator<(const jp &X)const{return sec==X.sec?fir>X.fir:sec>X.sec;}
}sol[10050];
int ans,now,n;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
	{
		for(int i=1;i<=n;i++)scanf("%d%d",&sol[i].fir,&sol[i].sec);
		sort(sol+1,sol+n+1);
		ans=now=0;
		for(int i=1;i<=n;i++)
		{
			now+=sol[i].fir;
			ans=max(ans,now+sol[i].sec);
		}
		printf("Case %d: %d\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

