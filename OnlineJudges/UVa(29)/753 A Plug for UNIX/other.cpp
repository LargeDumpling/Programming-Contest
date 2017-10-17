#include<map>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=405,M=405,INF=~0u>>1;
string str;
int nin[N],nout[N];
map<string,int> in,out;
map<string,int>::iterator it;
struct Edge{
	int v,c,f,next;
	Edge(){}
	Edge(int v,int c,int next):v(v),c(c),f(0),next(next){}
}e[M<<1];int fst[N],tot;
void Add(int u,int v,int c){
	e[tot]=Edge(v,c,fst[u]);fst[u]=tot++;
	e[tot]=Edge(u,0,fst[v]);fst[v]=tot++;
}
struct Dinic{
	int n,s,t;
	int d[N],q[N];
	bool BFS(){
		int head=0,tail=-1;
		for(int i=s;i<=t;i++) d[i]=n;
		d[s]=0;q[++tail]=s;
		while(head<=tail){
			int u=q[head++];
			for(int i=fst[u];i!=-1;i=e[i].next){
				int v=e[i].v;
				if(d[v]==n && e[i].f<e[i].c){
					d[v]=d[u]+1;
					q[++tail]=v;
				}
			}
		}
		return d[t]!=n;
	}
	int cur[N];
	int DFS(int u,int a){
		if(u==t || !a) return a;
		int flow=0,f;
		for(int& i=cur[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(d[u]+1==d[v] && (f=DFS(v,min(a,e[i].c-e[i].f)))){
				e[i].f+=f;
				e[i^1].f-=f;
				flow+=f;
				a-=f;
				if(!a) break;
			}
		}
		return flow;
	}
	int Maxflow(){
		int flow=0;
		while(BFS()){
			memcpy(cur,fst,sizeof cur);
			flow+=DFS(s,INF);
		}
		return flow;
	}
}dinic;
int main(){
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	int T,n,m,k;
	scanf("%d",&T);
	while(T--){
		in.clear();
		out.clear();
		memset(nin,0,sizeof nin);
		memset(nout,0,sizeof nout);
		tot=0;
		memset(fst,-1,sizeof fst);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>str;
			if(!in.count(str)) nin[in[str]=in.size()]=1;
			else nin[in[str]]++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%*s");
			cin>>str;
			if(!out.count(str)) nout[out[str]=out.size()]=1;
			else nout[out[str]]++;
		}
		for(it=out.begin();it!=out.end();it++){
			Add(0,it->second,nout[it->second]);
		}
		scanf("%d",&k);
		for(int i=1,u,v;i<=k;i++){
			cin>>str;
			if(!out.count(str)) u=out[str]=out.size();
			else u=out[str];
			cin>>str;
			if(!out.count(str)) v=out[str]=out.size();
			else v=out[str];
			Add(u,v,INF);
		}
		int outs=out.size();
		for(it=out.begin();it!=out.end();it++){
			if(in.count(it->first)){
				Add(it->second,outs+in[it->first],INF);
			}
		}
		int t=outs+in.size()+1;
		for(it=in.begin();it!=in.end();it++){
			Add(outs+it->second,t,nin[it->second]);
		}
		dinic.s=0;
		dinic.n=dinic.t=t;
		printf("%d\n",m-dinic.Maxflow());
		if(T) printf("\n");
	}
	return 0;
}

