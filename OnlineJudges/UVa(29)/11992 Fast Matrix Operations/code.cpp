/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-24	File created.
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
const int D=10000000;
char in[D],*I=in,out[D/10],*O=out; 
template<typename ty>
bool read1n(ty &x)
{
	for(x=0;*I<'0'||'9'<*I;I++)if(*I==-1)return false;
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	return true;
}
int s[70];
void write1n(int x)
{
	if(!x)*(O++)='0';
	for(s[0]=0;x;x/=10)s[++s[0]]=x%10;
	while(s[0])*(O++)=s[s[0]--]+'0';
	return;
}
int n,m,q,d[4000050][3],tag1[4000050],tag2[4000050],sz;
int mAx(int a,int b){return a<b?b:a;}
int mIn(int a,int b){return a<b?a:b;}
void maintain(int root,int l,int r)
{
	if(r==l)return;
	d[root][0]=d[root<<1][0]+d[root<<1|1][0];
	d[root][1]=mAx(d[root<<1][1],d[root<<1|1][1]);
	d[root][2]=mIn(d[root<<1][2],d[root<<1|1][2]);
	return;
}
void down(int root,int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	if(tag1[root]>=0)
	{//¸³
		d[root<<1][1]=d[root<<1][2]=tag1[root];
		d[root<<1][0]=(mid-l+1)*tag1[root];
		d[root<<1|1][1]=d[root<<1|1][2]=tag1[root];
		d[root<<1|1][0]=(r-mid)*tag1[root];
		tag1[root<<1]=tag1[root<<1|1]=tag1[root];
		tag2[root<<1]=tag2[root<<1|1]=0;
		tag1[root]=-1;
	}
	if(tag2[root])
	{
		d[root<<1][1]+=tag2[root];
		d[root<<1][2]+=tag2[root];
		d[root<<1][0]+=(mid-l+1)*tag2[root];
		d[root<<1|1][1]+=tag2[root];
		d[root<<1|1][2]+=tag2[root];
		d[root<<1|1][0]+=(r-mid)*tag2[root];
		tag2[root<<1]+=tag2[root];
		tag2[root<<1|1]+=tag2[root];
		tag2[root]=0;
	}
	return;
}
void sEt(int root,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		d[root][0]=(r-l+1)*x;
		d[root][1]=d[root][2]=tag1[root]=x;
		tag2[root]=0;
		return;
	}
	down(root,l,r);
	int mid=(l+r)>>1;
	if(L<=mid)sEt(root<<1,l,mid,L,R,x);
	if(mid<R)sEt(root<<1|1,mid+1,r,L,R,x);
	maintain(root,l,r);
	return;
}
void aDd(int root,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		d[root][0]+=(r-l+1)*x;
		d[root][1]+=x;
		d[root][2]+=x;
		tag2[root]+=x;
		return;
	}
	down(root,l,r);
	int mid=(l+r)>>1;
	if(L<=mid)aDd(root<<1,l,mid,L,R,x);
	if(mid<R)aDd(root<<1|1,mid+1,r,L,R,x);
	maintain(root,l,r);
	return;
}
void init(int root,int l,int r)
{
	d[root][0]=d[root][1]=0;
	d[root][2]=0;
	tag1[root]=-1;tag2[root]=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	init(root<<1,l,mid);
	init(root<<1|1,mid+1,r);
	return;
}
int anss,ansma,ansmi;
void qUery(int root,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		anss+=d[root][0];
		ansma=mAx(ansma,d[root][1]);
		ansmi=mIn(ansmi,d[root][2]);
		return;
	}
	down(root,l,r);
	int mid=(l+r)>>1;
	if(L<=mid)qUery(root<<1,l,mid,L,R);
	if(mid<R)qUery(root<<1|1,mid+1,r,L,R);
	return;
}
int get_pos(int r,int c){return (r-1)*m+c;}
void set(int x1,int y1,int x2,int y2,int x)
{
	int l,r;
	l=get_pos(x1,y1);
	r=get_pos(x1,y2);
	for(int i=x1;i<=x2;i++,l+=m,r+=m)
		sEt(1,1,sz,l,r,x);
	return;
}
void change(int x1,int y1,int x2,int y2,int x)
{
	int l,r;
	l=get_pos(x1,y1);
	r=get_pos(x1,y2);
	for(int i=x1;i<=x2;i++,l+=m,r+=m)
		aDd(1,1,sz,l,r,x);
	return;
}
void query(int x1,int y1,int x2,int y2)
{
	int l,r;
	anss=0;
	ansma=-2147483647;
	ansmi=2147483647;
	l=get_pos(x1,y1);
	r=get_pos(x1,y2);
	for(int i=x1;i<=x2;i++,l+=m,r+=m)
		qUery(1,1,sz,l,r);
	if(ansma==-2147483647)ansma=0;
	if(ansmi==2147483647)ansmi=0;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int order,a,b,c,d,e;
	while(read1n(n))
	{
		read1n(m);read1n(q);
		sz=n*m;
		init(1,1,sz);
		for(int i=1;i<=q;i++)
		{
			read1n(order);
			read1n(a);
			read1n(b);
			read1n(c);
			read1n(d);
			switch(order)
			{
				case 1:
					read1n(e);
					//scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
					change(a,b,c,d,e);
					break;
				case 2:
					read1n(e);
					//scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
					set(a,b,c,d,e);
					break;
				case 3:
					//scanf("%d%d%d%d",&a,&b,&c,&d);
					query(a,b,c,d);
					printf("%d %d %d\n",anss,ansmi,ansma);
					break;
			}
		}
	}
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

