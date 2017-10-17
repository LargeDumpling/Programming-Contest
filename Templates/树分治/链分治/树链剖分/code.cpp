/*LYDsy2243*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,col[100050];
int fir[100050],end[200050],next[200050],ed=0;
int dep[100050],hson[100050],size[100050],fa[100050];
int top[100050],w[100050],ts=0,fw[100050];
int L[400050],R[400050],Lc[400050],Rc[400050],sum[400050],tag[400050],sz=0;
const int D=10000000;
char in[D],*I=in,out[D/10],*O=out;
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
void DFS(int u)
{
	hson[u]=0;
	size[u]=1;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa[u])
			continue;
		dep[end[i]]=dep[u]+1;
		fa[end[i]]=u;
		DFS(end[i]);
		size[u]+=size[end[i]];
		if(size[end[i]]>size[hson[u]])
			hson[u]=end[i];
	}
	return;
}
void Subdivision(int u)
{
	w[u]=++ts;
	if(hson[u])
	{
		top[hson[u]]=top[u];
		Subdivision(hson[u]);
	}
	for(int i=fir[u];i;i=next[i])
		if(end[i]!=fa[u]&&end[i]!=hson[u])
		{
			top[end[i]]=end[i];
			Subdivision(end[i]);
		}
	return;
}
void down(int x)
{
	if(!tag[x]||L[x]==R[x])
		return;
	tag[x<<1]=tag[x];
	tag[x<<1|1]=tag[x];
	Lc[x<<1]=Rc[x<<1]=tag[x];
	Lc[x<<1|1]=Rc[x<<1|1]=tag[x];
	sum[x<<1]=sum[x<<1|1]=1;
	sum[x]=sum[x<<1]+sum[x<<1|1]-(Rc[x<<1]==Lc[x<<1|1]);
	tag[x]=0;
	return;
}
void up(int x)
{
	Lc[x]=Lc[x<<1];
	Rc[x]=Rc[x<<1|1];
	sum[x]=sum[x<<1]+sum[x<<1|1]-(Rc[x<<1]==Lc[x<<1|1]);
	return;
}
void build(int now,int l,int r)
{
	L[now]=l;
	R[now]=r;
	if(l==r)
	{
		Lc[now]=Rc[now]=col[fw[l]];
		sum[now]=1;
		return;
	}
	build(now<<1,l,(l+r)>>1);
	build(now<<1|1,((l+r)>>1)+1,r);
	up(now);
	return;
}
void change(int now,int l,int r,int c)
{
	down(now);
	if(l>r)
	{
		l+=r;
		r=l-r;
		l=l-r;
	}
	if(l<=L[now]&&R[now]<=r)
	{
		tag[now]=c;
		Lc[now]=Rc[now]=c;
		sum[now]=1;
		return;
	}
	if(r<=R[now<<1])
		change(now<<1,l,r,c);
	else if(l>R[now<<1])
		change(now<<1|1,l,r,c);
	else if(l<=R[now<<1]&&R[now<<1]<r)
		change(now<<1,l,r,c),change(now<<1|1,l,r,c);
	up(now);
	return;
}
int query(int now,int l,int r)
{
	down(now);
	if(l>r)
	{
		l+=r;
		r=l-r;
		l=l-r;
	}
	if(l<=L[now]&&R[now]<=r)
		return sum[now];
	else if(r<=R[now<<1])
		return query(now<<1,l,r);
	else if(l>R[now<<1])
		return query(now<<1|1,l,r);
	else if(l<=R[now<<1]&&R[now<<1]<r)
		return query(now<<1,l,r)+query(now<<1|1,l,r)-(Rc[now<<1]==Lc[now<<1|1]);
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
		if(dep[top[x]]>dep[top[y]])
			x=fa[top[x]];
		else
			y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
int getcol(int now,int x)
{
	down(now);
	if(L[now]==x&&x==R[now])
		return Lc[now];
	else if(x<=R[now<<1])
		return getcol(now<<1,x);
	else if(x>R[now<<1])
		return getcol(now<<1|1,x);
}
void C(int x,int y,int c)
{
	for(;top[x]!=top[y];x=fa[top[x]])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			x+=y;
			y=x-y;
			x-=y;
		}
		change(1,w[x],w[top[x]],c);
	}
	change(1,w[x],w[y],c);
	return;
}
int Q(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			x+=y;
			y=x-y;
			x-=y;
		}
		ans+=query(1,w[x],w[top[x]]);
		if(getcol(1,w[top[x]])==getcol(1,w[fa[top[x]]]))
			ans--;
		x=fa[top[x]];
	}
	ans+=query(1,w[x],w[y]);
	return ans;
}
char gc()
{
	return *(I++);
}
void pc(char x)
{
	*(O++)=x;
}
void readln(int &x)
{
	bool a=false;
	char ch;
	x=0;
	for(ch=gc();ch<'0'||'9'<ch;ch=gc())
		if(ch=='-')
			a=true;
	for(;'0'<=ch&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+ch-'0';
	if(a)
		x=-x;
}
void wsdsfln(int x)
{
	if(!x)pc('0');
	if(x<0)pc('-');
	static int s[20];
	while(x)
	{
		s[++s[0]]=x%10;
		x/=10;
	}
	while(s[0])
		pc(s[s[0]--]+'0');
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fread(in,1,D,stdin);
	int a,b,c,lca;
	char ch[5];
//	scanf("%d%d",&n,&m);
	readln(n),readln(m);
	for(int i=1;i<=n;i++)
//		scanf("%d",&col[i]);
		readln(col[i]);
	for(int i=1;i<n;i++)
	{
//		scanf("%d%d",&a,&b);
		readln(a),readln(b);
		addedge(a,b);
	}
	dep[1]=1;
	fa[1]=1;
	DFS(1);
	top[1]=1;
	char cha;
	Subdivision(1);
	for(int i=1;i<=n;i++)
		fw[w[i]]=i;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
//		scanf("%s",ch);
		for(cha=gc();cha!='Q'&&cha!='C';cha=gc());
		if(cha=='Q')
		{
//			scanf("%d%d",&a,&b);
			readln(a),readln(b);
//			lca=LCA(a,b);
//			printf("%d\n",Q(a,lca)+Q(b,lca)-1);
			wsdsfln(Q(a,b));
			pc('\n');
		}
		else if(cha=='C')
		{
//			scanf("%d%d%d",&a,&b,&c);
			readln(a),readln(b),readln(c);
//			lca=LCA(a,b);
//			C(a,lca,c);
//			C(b,lca,c);
			C(a,b,c);
		}
	}
//	printf(out);
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
