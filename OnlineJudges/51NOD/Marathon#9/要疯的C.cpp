#include <cmath>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

#define I64	long long
#define unt unsigned int
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)

#define CH	(ch=getchar())
int		IN(){
		int x=0,ch;
		for	(;CH<'0'||ch>'9';);
		for	(;ch>='0'&&ch<='9';CH)	(x*=10)+=ch-'0';
		return	x;
}

#define n	500005
#define P	1000000007

int		N,M,D,Ans,Q[n],F[n],G[n],V[n],fa[n],st[n];
struct	Lin{int v,next;}E[n<<1];

int		Pow(int a,int b){
		int ret=1;
		for	(;b;b>>=1,a=1ll*a*a%P)
			if	(b&1)	ret=1ll*ret*a%P;
		return	ret;
}

void	Link(int u,int v){
		E[++D]=(Lin){v,st[u]};	st[u]=D;
		E[++D]=(Lin){u,st[v]};	st[v]=D;
}

int		main(){
		N=IN();	M=Pow(2,P-2);
		For(i,2,N)	Link(IN(),IN());	V[Q[1]=1]=1;
		for	(int l=0,r=1;l<r;)	{
			int u=Q[++l];
			for	(int i=st[u],v;i;i=E[i].next)
				if	(!V[v=E[i].v])	V[Q[++r]=v]=1,fa[v]=u;
		}
		Rep(i,N,1)	{
			int u=Q[i];	G[u]=M;
			for	(int i=st[u],v;i;i=E[i].next)
			if	((v=E[i].v)!=fa[u])	{
				F[u]=(1ll*G[u]*G[v]+F[u])%P;
				G[u]=(1ll*G[v]*M+G[u])%P;
			}
		}
		For(i,1,N)	Ans=(Ans+F[i])%P;
		printf("%d\n",1ll*Pow(2,N)*Ans%P);
}
