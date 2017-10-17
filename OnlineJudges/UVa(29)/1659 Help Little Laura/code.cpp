/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int D=10000000;
char in[D],*I=in,out[D/10],*O=out;
int n,tu,tuc,x[105],y[105];
double dIst(int a,int b){return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}
vector<int>link[105];
double map[105][105];
int fir[105],pre[105],end[20050],next[20050],c[20050],f[20050],ed,sta,tar;
double dis[105],len[20050];
void addedge(int u,int v,double lenth,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=cap;
	f[ed]=0;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=c[ed]=cap;
	len[ed]=-lenth;
	return;
}
bool SPFA()
{
	int u,v;
	bool exist[105];
	queue<int>q;
	for(int i=1;i<=104;i++)dis[i]=2147483647;
	memset(exist,false,sizeof(exist));
	memset(pre,0,sizeof(pre));
	dis[sta]=0;
	q.push(sta);
	while(q.size())
	{
		u=q.front();
		q.pop();
		exist[u]=false;
		for(int i=fir[u];i;i=next[i])if(c[i]>f[i]&&dis[u]+len[i]<dis[v=end[i]])
		{
			dis[v]=dis[u]+len[i];
			pre[v]=i;
			if(!exist[v])
			{
				exist[v]=true;
				q.push(v);
			}
		}
	}
	return dis[tar]!=dis[104];
}
double MCMF()
{
	int a=2147483647;
	double ans=0;
	while(SPFA())
	{
		for(int i=tar;i!=sta;i=end[pre[i]^1])a=min(a,c[pre[i]]-f[pre[i]]);
		ans+=a*dis[tar];
		for(int i=tar;i!=sta;i=end[pre[i]^1])
			f[pre[i]]+=a,f[pre[i]^1]-=a;
	}
	return ans;
}
bool read1n(int &x)
{
	for(x=0;*I<'0'||'9'<*I;I++)if(*I==-1)return false;
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	return x;
	return true;
}
int s[100];
void write1n(int x)
{
	if(!x)*(O++)='0';
	for(s[0]=0;x;x/=10)s[++s[0]]=x%10;
	while(s[0])*(O++)=s[s[0]--]+'0';
	return;
}
void write1n(char *x)
{
	while(*x!='\0')*(O++)=*(x++);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int X,sti[105],tai[105];
	//char /*caSe[]="Case ",*/temp[50];
	double cost,ans;
	//for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
	for(int cAse=1;read1n(n)&&n;cAse++)
	{
		//scanf("%d%d",&tu,&tuc);
		read1n(tu);read1n(tuc);
		for(int i=1;i<=n;i++)
		{
			//scanf("%d%d",&x[i],&y[i]);
			read1n(x[i]);read1n(y[i]);
			link[i].clear();
			//while(scanf("%d",&X)!=-1&&X)
			while(read1n(X)&&X)
				link[i].push_back(X);
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				map[i][j]=map[j][i]=dIst(i,j);
		memset(fir,0,sizeof(fir));
		memset(sti,0,sizeof(sti));
		memset(tai,0,sizeof(tai));
		ed=1;sta=n+1;tar=n+2;ans=0;
		for(int i=1;i<=n;i++)
		{
			for(unsigned j=0;j<link[i].size();j++)
			{
				cost=tuc-tu*map[i][link[i][j]];
				if(cost<0)
				{
					cost=-cost;
					ans+=cost;
					sti[link[i][j]]++;
					tai[i]++;
					addedge(link[i][j],i,cost,1);
				}
				else if(cost>0)
					addedge(i,link[i][j],cost,1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			X=sti[i]-tai[i];
			if(X<0)addedge(i,tar,0,-X);
			else if(X>0)addedge(sta,i,0,X);
		}
		ans-=MCMF();
		if(ans<0)ans=0;
		//write1n("Case ");
		//write1n(cAse);
		//*(O++)=':';*(O++)=' ';
		O+=sprintf(O,"Case %d: %.2f\n",cAse,ans);
		//printf("Case %d: %.2f\n",cAse,ans);
		/*sprintf(temp,"Case %d: %.2f\n",cAse,ans);
		write1n(temp);*/
	}
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

