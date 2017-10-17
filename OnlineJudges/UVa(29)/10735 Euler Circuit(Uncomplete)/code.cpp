/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Dinic
{
	int sta,tar,fir[1005],cur[1005],lev[1005],end[10050],next[10050],c[10050],f[10050],ed;
	//int q[1000050];
	queue<int>q;
	Dinic(int n=0)
	{
		memset(fir,0,sizeof(fir));
		ed=1;
		sta=n+1;
		tar=sta+1;
	}
	void init(int n=0)
	{
		memset(fir,0,sizeof(fir));
		ed=1;
		sta=n+1;
		tar=sta+1;
		return;
	}
	void addedge(int u,int v,int cap)
	{
		end[++ed]=v;
		next[ed]=fir[u];
		fir[u]=ed;
		c[ed]=cap;
		f[ed]=0;
		end[++ed]=u;
		next[ed]=fir[v];
		fir[v]=ed;
		c[ed]=f[ed]=cap;
		return;
	}
	int inc(int &x){return ++x>1000048?x-1000048:x;}
	#define head q[0]
	#define tail q[1000049]
	bool BFS()
	{
		memset(lev,0,sizeof(lev));
		int u;
		lev[sta]=1;
		while(q.size())q.pop();
		//q[inc(tail)]=sta;
		q.push(sta);
		while(q.size())
		{
			//u=q[inc(head)];
			u=q.front();
			q.pop();
			for(int i=fir[u];i;i=next[i])if(c[i]>f[i]&&!lev[end[i]])
			{
				lev[end[i]]=lev[u]+1;
				//q[inc(tail)]=end[i];
				q.push(end[i]);
			}
		}
		memcpy(cur,fir,sizeof fir);
		return lev[tar];
	}
	#undef head
	#undef tail
	int DFS(int u,int maxf)
	{
		if(u==tar)return maxf;
		int totf=0,temf;
		for(int i=fir[u];i;i=next[i])if(c[i]>f[i]&&lev[end[i]]==lev[u]+1)
		{
			totf+=(temf=DFS(end[i],min(maxf,c[i]-f[i])));
			f[i]+=temf;
			maxf-=temf;
			f[i^1]-=temf;
		}
		if(!totf)lev[u]=-1;
		return totf;
	}
	int max_flow()
	{
		int ans=0;
		while(BFS())ans+=DFS(sta,2147483647);
		return ans;
	}
	bool full()
	{
		bool flag=true;
		for(int i=fir[sta];i;i=next[i])if(f[i]!=c[i])flag=false;
		return flag;
	}
}G;
int T,n,m,in[105],out[105],fir[105],end[505],next[505],ed;
bool dirct[505];
void addedge(int u,int v,bool dir)
{
	out[u]++;
	in[v]++;
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	dirct[ed]=dir;
	return;
}
int check()
{
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(in[i]!=out[i])flag=0;
		if(abs(in[i]-out[i])&1)return -1;
	}
	return flag;
}
int asc[106],ase[505],asn[505],aned=0,ans[1050];
bool printed[505];
void asaddedge(int u,int v)
{
	ase[++aned]=v;
	asn[aned]=asc[u];
	asc[u]=aned;
	return;
}
void print(int u)
{
	for(int i=asc[u];i;i=asn[i])if(!printed[i])
	{
		printed[i]=true;
		int j=ase[i];
		print(ase[i]);
		//printf(" %d",ase[i]);
		ans[++ans[0]]=j;//Because ase may be changed in the prev
	}
	return;
}
void pRint(int u)
{
	for(int i=fir[u];i;i=next[i])if(!printed[i])
	{
		printed[i]=true;
		int j=end[i];
		pRint(j);
		ans[++ans[0]]=j;
	}
	return;
}
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,cAse=0;
	char sta;
	scanf("%d",&T);
	while(T--)
	{
		if(cAse++)putchar('\n');
		memset(fir,0,sizeof fir);
		memset(dirct,false,sizeof(dirct));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		ed=1;
		scanf("%d%d",&n,&m);
		//read1n(n);
		//read1n(m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %c",&a,&b,&sta);
			addedge(a,b,sta=='D');
		}
		a=check();
		if(a==-1)printf("No euler circuit exist\n");
		else if(a==1)
		{
			memset(printed,false,sizeof(printed));
			ans[0]=0;
			pRint(1);
			printf("1");
			for(int i=ans[0];i;i--)printf(" %d",ans[i]);
			putchar('\n');
		}
		else if(a==0)
		{
			G.init(n+1);
			for(int i=1;i<=n;i++)
			{
				//if(in[i]==out[i])continue;
				if(in[i]>out[i])G.addedge(i,G.tar,(in[i]-out[i])>>1);
				if(in[i]<out[i])G.addedge(G.sta,i,(out[i]-in[i])>>1);
				for(int j=fir[i];j;j=next[j])
					if(!dirct[j])
						G.addedge(i,end[j],1);
			}
			G.max_flow();
			if(!G.full())printf("No euler circuit exist\n");
			else
			{
				memset(asc,ed=0,sizeof(asc));
				memset(printed,false,sizeof(printed));
				for(int i=1;i<=n;i++)
					for(int j=fir[i];j;j=next[j])if(dirct[j])
						asaddedge(i,end[j]);
				for(int i=1;i<=n;i++)
					for(int j=G.fir[i];j;j=G.next[j])
						if(1<=G.end[j]&&G.end[j]<=n&&!(j&1))
						{
							if(G.f[j]==G.c[j])asaddedge(G.end[j],i);
							else asaddedge(i,G.end[j]);
						}
				ans[0]=0;
				print(1);
				printf("1");
				for(int i=ans[0];i;i--)printf(" %d",ans[i]);
				putchar('\n');
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

