/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define n1 st[st[0]-1]
#define n2 st[st[0]]
#define n3 st[mid]
#define n4 st[mid+1]
using namespace std;
const int MAXN=500050;
const double eps=1e-8;
int n,Q,st[MAXN];
double x[MAXN],y[MAXN],s[MAXN],ans;
int cmp(double x)
{
	if(fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
double calc(int i,int j)
{
	//return (y[j]-y[i])/(x[j]-x[i]);
	return (y[j]*(i+1)-y[i]*(j+1))/(x[j]*(i+1)-x[i]*(j+1));
}
int main()
{
	int op,l,mid,r;
	scanf("%d",&Q);
	n=st[0]=ans=0;
	while(Q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%lf",&s[++n]);
			s[n]+=s[n-1];
			/*x[n]=(double)n/(n+1);
			y[n]=(double)s[n]/(n+1);*/
			x[n]=n;
			y[n]=s[n];
			//st[++st[0]]=n;
			/*if(2<st[0]&&
					(y[st[st[0]]]-y[st[st[0]-1]])*(x[st[st[0]-1]]-x[st[st[0]-2]])
					<=(y[st[st[0]-1]]-y[st[st[0]-2]])*(x[st[st[0]]]-x[st[st[0]-1]]))
					st[0]--;*/
			/*if(2<st[0]&&calc(st[st[0]-1],st[st[0]])<=calc(st[st[0]-2],st[st[0]-1]))
				st[0]--;*/
			//while(2<=st[0]&&cmp(calc(st[st[0]],n)-calc(st[st[0]-1],st[st[0]]))<=0)
			while(2<=st[0]&&cmp(
						(y[n]*(n2+1)-y[n2]*(n+1))*(x[n2]*(n1+1)-x[n1]*(n2+1))
						-(y[n2]*(n1+1)-y[n1]*(n2+1))*(x[n]*(n2+1)-x[n2]*(n+1))
						)<=0)
				st[0]--;
			st[++st[0]]=n;
			l=1; r=st[0];
			double k=s[n]-s[n-1];
			while(l<r-1)
			{
				mid=(l+r)>>1;
				//if(cmp(calc(st[mid],st[mid+1])-k)<=0)
				if(cmp(
							y[st[mid]]*(st[mid]+2)-y[st[mid+1]]*(st[mid]+1)
							-k*(x[st[mid]]*(st[mid]+2)-x[st[mid+1]]*(st[mid]+1))
							)<=0)
					l=mid;
				else r=mid;
			}
			//if(l<st[0]&&cmp(calc(st[l],st[l+1])-k)<=0) l++;
			if(l<st[0]&&cmp(
							y[st[l]]*(st[l]+2)-y[st[l+1]]*(st[l]+1)
							-k*(x[st[l]]*(st[l]+2)-x[st[l+1]]*(st[l]+1))
							)<=0)
				l++;
			ans=max(ans,(k*x[l]-y[l])/(double)(l+1));
		}
		else if(op==2)
			printf("%.10lf\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

