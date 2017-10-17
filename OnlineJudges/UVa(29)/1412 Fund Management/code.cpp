/*
 author: Largedumpling
 email: largedumpling@qq.com
 edit history:
	2015-12-02	file created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<limits>
#include<algorithm>
using namespace std;
struct jp
{
	char name[10];
	int s,k;
}st[10];
/*struct yp
{
	int num[10];
	yp()
	{
		memset(num,0,sizeof(num));
	}
	void clear()
	{
		memset(num,0,sizeof(num));
		return;
	}
	bool operator<(const yp X)const
	{
		for(int i=0;i<10;i++)
			if(num[i]!=X.num[i])
				return num[i]<X.num[i];
		return false;
	}
}tem;*/
int N,M,K;
double C,pri[10][105];
map<vector<int>,int >ID;
vector<vector<int> >state;
int buy[15000][10],sell[15000][10],pre[105][15000],opt[105][15000];
double d[105][15000];
int clo=0;
void DFS(int cur,vector<int> &tem,int curn)
{
	if(cur>=N)
	{
		ID[tem]=state.size();
		state.push_back(tem);
		/*for(int i=1;i<=N;i++)cout<<tem[i]<<" ";
		cout<<"\n";*/
		return;
	}
	for(int i=0;i<=st[cur+1].k&&curn+i<=K;i++)
	{
		tem[cur+1]=i;
		DFS(cur+1,tem,curn+i);
	}
	return;
}
void init()
{
	int curn;
	//tem.resize(N+1);
	vector<int> tem(N+1);
	state.clear();
	ID.clear();
	DFS(0,tem,0);
	vector<int>newstate;
	for(unsigned i=0;i<state.size();i++)
	{
		curn=0;//curn表示i这个状态持有的股票总手数
		for(int j=1;j<=N;j++)curn+=state[i][j]/*,newstate[j]=state[i][j]*/;
		newstate=state[i];
		for(int j=1;j<=N;j++)
		{
			if(K-curn>=1)
			{//再买一手
				newstate[j]=state[i][j]+1;
				buy[i][j]=ID[newstate];
			}
			else buy[i][j]=-1;
			if(state[i][j]>=1)
			{//卖一手
				newstate[j]=state[i][j]-1;
				sell[i][j]=ID[newstate];
			}
			else sell[i][j]=-1;
			newstate[j]=state[i][j];
		}
	}
	return;
}
double INF=1e9;
void updata(int day,int s,int s2,double v,int o)
{
	//(day,s)利用(day+1,s2)的v来更新
	if(v>d[day+1][s2])
	{
		d[day+1][s2]=v;
		opt[day+1][s2]=o;
		pre[day+1][s2]=s;
	}
	return;
}
void calc()
{
	int curn=0;
	for(int i=0;i<=M;i++)for(unsigned j=0;j<state.size();j++)d[i][j]=-INF;
	d[0][0]=C;
	for(int i=0;i<M;i++)
	{
		for(unsigned j=0;j<state.size();j++)
		{
			if(d[i][j]==-INF)continue;
			updata(i,j,j,d[i][j],0);//不动
			curn=0;
			for(int k=1;k<=N;k++)curn+=state[j][k];
			for(int k=1;k<=N;k++)
			{
				if(buy[j][k]!=-1&&state[j][k]<st[k].k&&curn<K&&d[i][j]>=st[k].s*pri[k][i+1])
					updata(i,j,buy[j][k],d[i][j]-st[k].s*pri[k][i+1],k);
				if(sell[j][k]!=-1&&state[j][k]>=1)
					updata(i,j,sell[j][k],d[i][j]+st[k].s*pri[k][i+1],-k);
			}
		}
	}
	return;
}
void print(int x,int s)
{
	if(!x)return;
	print(x-1,pre[x][s]);
	if(!opt[x][s])
		printf("HOLD\n");
	else if(opt[x][s]>0)
		printf("BUY %s\n",st[opt[x][s]].name);
	else
		printf("SELL %s\n",st[-opt[x][s]].name);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%lf%d%d%d",&C,&M,&N,&K)==4)
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%s%d%d",st[i].name,&st[i].s,&st[i].k);
			st[i].s+=1e-12;
			for(int j=1;j<=M;j++)
				scanf("%lf",&pri[i][j]);
		}
		init();
		calc();
		printf("%.2lf\n",d[M][0]);
		print(M,0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

