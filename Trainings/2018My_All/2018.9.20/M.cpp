/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
const double eps=1e-12;
int dcmp(const double &X)
{
	if(fabs(X)<eps) return 0;
	return X<0?-1:1;
}
struct jz
{
	int id;
	double x,y,dis;
	jz() { }
	bool operator<(const jz &X)const { return dis<X.dis; }
}P[MAXN];
int T_T,n,ans[MAXN];
double R,r;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans[0]=0;
		scanf("%d%lf%lf",&n,&R,&r);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&P[i].x,&P[i].y);
			P[i].dis=sqrt(P[i].x*P[i].x+P[i].y*P[i].y);
			P[i].id=i;
		}
		sort(P+1,P+n+1);
		if(0<=dcmp(R-r-r-P[1].dis))
		{
			for(int i=1;i<=n;i++) if(0<=dcmp(R-r-r-P[i].dis))
				ans[++ans[0]]=P[i].id;
		}
		else
		{
			for(int i=1;i<=n;i++) if(!dcmp(P[i].dis-P[1].dis))
				ans[++ans[0]]=P[i].id;
		}
		sort(ans+1,ans+ans[0]+1);
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];i++)
		{
			printf("%d",ans[i]);
			if(i!=ans[0]) putchar(' ');
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

