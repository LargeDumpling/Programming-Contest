#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
class chairT{
	int n,m,root[N],sz,rank[N];
	struct node{int l,r,w;}T[N*20];
	pair<int,int>a[N];
	void insert(int &i,int l,int r,int rk){
		T[++sz]=T[i];i=sz;
		T[i].w++;
		if(l==r)return;/*careful*/
		int mid=(l+r)>>1;
		if(rk<=mid)insert(T[i].l,l,mid,rk);
		else insert(T[i].r,mid+1,r,rk);
	}
 int tquery(int x,int y,int rk){
		int l=1,r=n,t,mid;
		x=root[x-1];y=root[y];
		while(l!=r){
   			t=T[T[y].l].w-T[T[x].l].w;mid=(l+r)>>1;
  			if(rk<=t)x=T[x].l,y=T[y].l,r=mid;
			else x=T[x].r,y=T[y].r,l=mid+1,rk-=t;
		}
		return a[l].first;
	}
	public:
		void init(){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;++i)scanf("%d",&a[i].first),a[i].second=i;
			sort(a+1,a+1+n);
			for(int i=1;i<=n;++i)rank[a[i].second]=i;
			for(int i=1;i<=n;++i)
				insert(root[i]=root[i-1],1,n,rank[i]);
		}
		int query(int l,int r,int rk){return tquery(l,r,rk);}
		void fuck(){
			init();
			while(m--){
				int i,j,k;
				scanf("%d%d%d",&i,&j,&k);
				printf("%d\n",query(i,j,k));
			}
		}
}T;

int main(){
	freopen("input.txt","r",stdin);
	T.fuck();
}
