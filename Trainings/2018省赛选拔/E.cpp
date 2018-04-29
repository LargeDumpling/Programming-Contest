/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-26	File created.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const double Pi=acos(-1.);
const int MAXN=360050;
double R,r;
int N,Q;
int to[MAXN<<1],tp[MAXN];
multiset<int> pos;
multiset<double> dis;
vector<int> from[MAXN];
double calc_dis(int i,int j)
{
	double t1=Pi*min((i-j+360000)%360000,(j-i+360000)%360000)/180000;
	double d=R*cos(t1/2);
	if(r<d) return R*sin(t1/2)*2;
	double t2=acos(r/R),d1,d2;
	d1=(t1-2*t2)*r;
	d2=2*sqrt(R*R-r*r);
	return d1+d2;
}
int find_pre(int x)
{
	multiset<int>::iterator it;
	it=upper_bound(pos.begin(),pos.end(),x);
	if(it==pos.begin()) it=pos.end();
	return *(--it);
}
int find_next(int x)
{
	multiset<int>::iterator it;
	it=lower_bound(pos.begin(),pos.end(),x);
	if(it==pos.end()) return *pos.begin();
	return *it;
}
int calc_to(int x)
{
	int pre=find_pre((x+180000)%360000),next=find_next((x+180000)%360000);
	return calc_dis(x,pre)<calc_dis(x,next)?next:pre;
}
void print()
{
	for(multiset<int>::iterator it=pos.begin();it!=pos.end();it++)
		printf("%d ",*it);
	putchar('\n');
	for(multiset<double>::iterator it=dis.begin();it!=dis.end();it++)
		printf("%lf ",*it);
	putchar('\n');
	return;
}
void get_size()
{
	printf("\n%d\n%d\n",(int)pos.size(),(int)dis.size());
	return;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int op[100050],x[100050];
double ans[100050];
int main()
{
	//freopen("E.in","r",stdin);
	int y;
	multiset<double>::iterator it;
	//set<int>::iterator it2;
	int it2;
	memset(to,-1,sizeof(to));
	read1n(y); R=y;
	read1n(y); r=y;
	//scanf("%lf%lf",&R,&r);
	//scanf("%d",&N);
	read1n(N);
	for(int i=1;i<=N;i++)
	{
		//scanf("%d",&tp[i]);
		read1n(tp[i]);
		pos.insert(tp[i]);
	}
	for(int i=1;i<=N;i++)
	{
		to[tp[i]]=calc_to(tp[i]);
		from[to[tp[i]]].push_back(tp[i]);
		dis.insert(calc_dis(tp[i],to[tp[i]]));
	}
	printf("%.10lf\n",*(--(it=dis.end())));
	//scanf("%d",&Q);
	read1n(Q);
	//print();
	for(int i=1;i<=Q;i++)
	{
		//scanf("%d%d",&op,&x);
		read1n(op[i]);
		read1n(x[i]);
		if(2<i&&op[i]==op[i-2]&&op[i]!=op[i-1]&&x[i]==x[i-1]&&x[i]==x[i-2])
			ans[i]=ans[i-2];
		else
		{
			switch(op[i])
			{
				case 1:
					pos.insert(x[i]);
					to[x[i]]=calc_to(x[i]);
					from[to[x[i]]].push_back(x[i]);
					dis.insert(calc_dis(x[i],to[x[i]]));

					it=dis.find(calc_dis(to[x[i]],to[to[x[i]]]));
					//from[to[to[x[i]]]].erase(to[x[i]]);
					dis.erase(it);
					to[to[x[i]]]=calc_to(to[x[i]]);
					from[to[to[x[i]]]].push_back(to[x[i]]);
					dis.insert(calc_dis(to[x[i]],to[to[x[i]]]));
					break;
				case 2:
					pos.erase(x[i]);
					it=dis.find(calc_dis(x[i],to[x[i]]));
					//from[to[x[i]]].erase(x[i]);
					dis.erase(it);
					for(it2=0;it2<from[x[i]].size();it2++) if(to[from[x[i]][it2]]==x[i])
					{
						it=dis.find(calc_dis(x[i],from[x[i]][it2]));
						dis.erase(it);
						to[from[x[i]][it2]]=calc_to(from[x[i]][it2]);
						from[to[from[x[i]][it2]]].push_back(from[x[i]][it2]);
						dis.insert(calc_dis(from[x[i]][it2],to[from[x[i]][it2]]));
					}
					from[x[i]].clear();
					break;
				default:
					break;
			}
			//print();
			ans[i]=*(--(it=dis.end()));
		}
		printf("%.10lf\n",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

