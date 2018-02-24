#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
const int N=105,M=5e3+5,INF=~0u>>1;
typedef pair<double,int> pdi;
priority_queue<pdi,vector<pdi>,greater<pdi> > q;

/*struct Node{
	int No,d;
	bool operator < (const Node &rhs) const {
		return d>rhs.d;
	}
};
priority_queue<Node> Q;*/

struct Node{
	int x,y;
}p[N];
double Dis(int a,int b){
	int dx=(p[a].x-p[b].x),dy=(p[a].y-p[b].y);
	return sqrt(dx*dx+dy*dy);
}
struct Edge{
	int v;double w;Edge *next;
	Edge(){}
	Edge(int v,double w,Edge *next):v(v),w(w),next(next){}
}e[M],*fst[N];int tot;
void Add(int u,int v,double w){
	e[++tot]=Edge(v,w,fst[u]);fst[u]=e+tot;
	e[++tot]=Edge(u,w,fst[v]);fst[v]=e+tot;
}
double d[N];
bool vis[N];
int n,m;
int x,y;
void Wijkstra(){
	for(int i=1;i<=n;i++) d[i]=INF;
	d[x]=0;
	q.push(pdi(d[x],x));
	pdi p;
	while(!q.empty()){
		p=q.top();q.pop();
		int u=p.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(Edge *i=fst[u];i;i=i->next){
			int v=i->v;
			if(vis[v]) continue;
			double w=i->w;
			if(d[u]+w<d[v]) d[v]=d[u]+w,q.push(pdi(d[v],v));
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		p[i].x=x;p[i].y=y;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		Add(x,y,Dis(x,y));
	}
	scanf("%d%d",&x,&y);
	Wijkstra();
	printf("%.2f",d[y]);
	return 0;
}

