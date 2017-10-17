#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=1e5+5,INF=~0u>>1;
void IO(){
	freopen("code.in","r",stdin);
	freopen("Goduang.out","w",stdout);
}
struct Treap{
	struct Node{
		int v,k,s;Node *c[2];
		Node(int v,Node *p):v(v){
			c[0]=c[1]=p;s=1;k=rand();
		}
		void Res(){s=c[0]->s+c[1]->s+1;}
	}*Null,*Root;
	void Rot(Node *&t,bool d){
		Node *c=t->c[d];
		t->c[d]=c->c[!d];
		c->c[!d]=t;
		t->Res();c->Res();
		t=c;
	}
	int x;
	void Ins(Node *&t){
		if(t==Null){t=new Node(x,Null);return;}
		bool d=t->v<x;
		Ins(t->c[d]);
		if(t->c[d]->k<t->k) Rot(t,d);
		else t->Res();
	}
	void Del(Node *&t){
		if(t==Null) return;
		if(t->v==x){
			if(t->c[0]==Null || t->c[1]==Null){
				bool d=t->c[1]!=Null;
				t=t->c[d];
				return;
			}
			bool d=t->c[1]->k<t->c[0]->k;
			Rot(t,d);
			Del(t->c[!d]);
		}
		else{
			bool d=t->v<x;
			Del(t->c[d]);
		}
		t->Res();
	}
	int Ran(Node *t){
		if(t==Null) return N;
		if(x<t->v) return Ran(t->c[0]);
		int r=t->c[0]->s;
		if(t->v==x) return min(r+1,Ran(t->c[0]));
		return r+1+Ran(t->c[1]);
	}
	int Sel(Node *t,int k){
		int r=t->c[0]->s;
		if(k<=r) return Sel(t->c[0],k);
		if(k==r+1) return t->v;
		return Sel(t->c[1],k-r-1);
	}
	int ret;
	void Pre(Node *t){
		if(t==Null) return;
		bool d=t->v<x;
		if(d) ret=t->v;
		Pre(t->c[d]);
	}
	void Suf(Node *t){
		if(t==Null) return;
		bool d=t->v<=x;
		if(!d) ret=t->v;
		Suf(t->c[d]);
	}
	Treap(){
		Null=new Node(0,0);
		Null->s=0;
		Null->k=INF;
		Root=Null;
	}
	void Insert(int x){this->x=x;Ins(Root);}
	void Delete(int x){this->x=x;Del(Root);}
	int Rank(int x){this->x=x;return Ran(Root);}
	int Select(int k){return Sel(Root,k);}
	int PreSuf(int x,bool d){
		this->x=x;
		if(!d) Pre(Root);
		else Suf(Root);
		return ret;
	}
}T;
int n;
void Init(){
	scanf("%d",&n);
}
int main(){
	IO();
	Init();
	for(int i=1,opt,x;i<=n;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1) T.Insert(x);
		else if(opt==2) T.Delete(x);
		else if(opt==3) printf("%d\n",T.Rank(x));
		else if(opt==4) printf("%d\n",T.Select(x));
		else printf("%d\n",T.PreSuf(x,!(opt&1)));
	}
	return 0;
}

