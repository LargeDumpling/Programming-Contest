/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=10000000;
char in[D],*I=in,out[D/10],*O=out;
long long num[500050],f[500050];
int n,m,al,ar,d[2000050][4];
template<typename ty>
bool read1n(ty &x)
{
	bool a;
	for(x=0,a=false;*I<'0'||'9'<*I;I++)
		if(*I==-1)return false;
		else if(*I=='-')a=true;
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	if(a)x=-x;
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
void write1n(char *tex)
{
	while(*tex!='\0')*(O++)=*(tex++);
	return;
}
long long dd(int l,int r){return f[r]-f[l-1];}
void updata(int &a,int &b,int c,int d)
{
	if(dd(a,b)<dd(c,d))a=c,b=d;
	else if(dd(a,b)==dd(c,d))
	{
		if(a>c)
		{
			a=c;
			b=d;
		}
		else if(a==c&&b>d)b=d;
	}
	return;
}
void build(int root,int l,int r)
{
	d[root][0]=l;
	d[root][1]=r;
	d[root][2]=r;//前
	d[root][3]=l;//后
	if(l==r)return;
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	if(dd(l,d[root<<1|1][2])>dd(l,d[root<<1][2]))d[root][2]=d[root<<1|1][2];
	else d[root][2]=d[root<<1][2];
	if(dd(d[root<<1][3],r)>=dd(d[root<<1|1][3],r))d[root][3]=d[root<<1][3];
	else d[root][3]=d[root<<1|1][3];
	updata(d[root][0],d[root][1],d[root<<1][0],d[root<<1][1]);
	updata(d[root][0],d[root][1],d[root<<1|1][0],d[root<<1|1][1]);
	updata(d[root][0],d[root][1],d[root<<1][3],d[root<<1|1][2]);
	return;
}
int query_prf(int root,int l,int r,int R)
{//前
	if(d[root][2]<=R)return d[root][2];
	int mid=(l+r)>>1;
	if(R<=mid)return query_prf(root<<1,l,mid,R);
	int ar=R,temr=query_prf(root<<1|1,mid+1,r,R),teml=l;
	updata(teml,ar,teml,temr);
	updata(teml,ar,teml,d[root<<1][2]);
	return ar;
}
int query_suf(int root,int l,int r,int L)
{//后
	if(L<=d[root][3])return d[root][3];
	int mid=(l+r)>>1;
	if(mid<L)return query_suf(root<<1|1,mid+1,r,L);
	int al=L,teml=query_suf(root<<1,l,mid,L),temr=r;
	updata(al,temr,teml,temr);
	updata(al,temr,d[root<<1|1][3],temr);
	return al;
}
void query(int root,int l,int r,int L,int R)
{
	//if(l==r)return;
	if(L<=l&&r<=R)
	{
		updata(al,ar,d[root][0],d[root][1]);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)query(root<<1,l,mid,L,R);
	if(R>mid)query(root<<1|1,mid+1,r,L,R);
	if(L<=mid&&mid<R)
	{
		int mmi,mma;
		mmi=query_suf(root<<1,l,mid,L);
		mma=query_prf(root<<1|1,mid+1,r,R);
		updata(al,ar,mmi,mma);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int a,b;
	char tex[10]="Case ";
	for(int cAse=1;read1n(n);cAse++)
	{
		read1n(m);
		//printf("Case %d:\n",cAse);
		write1n(tex);
		write1n(cAse);
		*(O++)=':';*(O++)='\n';
		for(int i=1;i<=n;i++)
		{
			//scanf("%lld",&num[i]);
			read1n(num[i]);
			f[i]=f[i-1]+num[i];
		}
		build(1,1,n);
		for(int i=1;i<=m;i++)
		{
			//scanf("%d%d",&a,&b);
			read1n(a);read1n(b);
			al=ar=a;
			query(1,1,n,a,b);
			//printf("%d %d\n",al,ar);
			write1n(al);*(O++)=' ';
			write1n(ar);*(O++)='\n';
		}
	}
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

