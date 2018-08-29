/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=998244353;
const int MAXN=100050;
int n,w[MAXN],h[MAXN];
long long p[2][MAXN],f[MAXN],inv;
template<typename Ty=int,const int &len=0,Ty (*maintain)(Ty,Ty)=NULL>
class ZKW
{
	private:
		Ty *d;
		int M;
		int low(int x) { return x&(-x); }
		int get_min_size(int x)
		{
			while(x!=low(x)) x+=low(x);
			return x;
		}
		Ty def_maintain(Ty a,Ty b) { return a+b; }
	public:
		ZKW()
		{
			d=new Ty[M=(get_min_size(len)<<1)];
			if(maintain==NULL) maintain=def_maintain();
		}
		~ZKW() { delete d; }
		bool change(int pos,Ty x)
		{
			if(pos<0||M<=pos) return false;
			d[pos+=M]=x;
			for(pos>>=1;pos;pos>>=1)
				d[pos]=maintain(d[pos<<1],d[pos<<1|1]);
			return true;
		}
		Ty query(int L,int R)
		{
			Ty ans=Ty();
			for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
			{
				if(!(L&1)) ans=ans+d[L^1];
				if(R&1) ans=ans+d[R^1];
			}
			return ans;
		}
		Ty query(int x) { return d[x+M]; }
};
long long pow(long long x,long long N)
{
	long long ans;
	for(ans=1;N;N>>=1,x=x*x%mod)
		if(N&1)
			ans=ans*x%mod;
	return ans;
}
void init()
{
	h[0]=0;
	//for(int i=0;i<(M<<1);i++)
		//d[i]=1;
	return;
}
int main()
{
	ZKW<long long,MAXN,[](const long long A,const long long B) -> { return A*B; } > k;
	inv=pow(100,mod-2);
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%d",&p[0][i],&w[i]);
		p[0][i]=p[0][i]*inv%mod;
		h[++h[0]]=w[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	p[0][0]=p[1][0]=1;
	w[0]=0;
	for(int i=1;i<=n;i++)
	{
		w[i]=lower_bound(h+1,h+h[0]+1,w[i])-h;
		//p[1][i]=q
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

