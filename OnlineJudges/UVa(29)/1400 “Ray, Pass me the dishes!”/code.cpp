/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
const int D=100000
char in[D],*I=in,out[D/10],*O=out;
int n,m,mi[500050],ma[500050],al,ar;
long long num[500050],da;
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
long long dd(int l,int r){return num[r]-num[l];}
void build(int root,int l,int r)
{
	if(l==r)
	{
		mi[root]=ma[root]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	mi[root]=num[mi[root<<1]]<=num[mi[root<<1|1]]?mi[root<<1]:mi[root<<1|1];
	ma[root]=num[ma[root<<1]]>=num[ma[root<<1|1]]?ma[root<<1]:ma[root<<1|1];
	return;
}
int mIn(int root,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return mi[root];
	int mid=(l+r)>>1,ans=0,tem;
	if(L<=mid)
	{
		tem=mIn(root<<1,l,mid,L,R);
		if(!ans||num[tem]<num[ans])ans=tem;
	}
	if(mid<R)
	{
		tem=mIn(root<<1|1,mid+1,r,L,R);
		if(!ans||num[tem]<num[ans])ans=tem;
	}
	return ans;
}
int mAx(int root,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return ma[root];
	int mid=(l+r)>>1,ans=0,tem;
	if(L<=mid)
	{
		tem=mAx(root<<1,l,mid,L,R);
		if(!ans||num[tem]>num[ans])ans=tem;
	}
	if(mid<R)
	{
		tem=mAx(root<<1|1,mid+1,r,L,R);
		if(!ans||num[tem]>num[ans])ans=tem;
	}
	return ans;
}
void query(int root,int l,int r,int L,int R)
{
	if(l==r)return;
	if(L<=l&&r<=R)
	{
		if(da<dd(mi[root<<1],ma[root<<1|1]))
		{
			al=mi[root<<1];ar=ma[root<<1|1];
			da=dd(al,ar);
		}
		return;
	}
	int mid=(l+r)>>1,mmi=0,mma=0;
	if(L<=mid)
	{
		query(root<<1,l,mid,L,R);
		mmi=mIn(root<<1,l,mid,L,R);
	}
	if(mid<R)
	{
		query(root<<1|1,mid+1,r,L,R);
		mma=mAx(root<<1|1,mid+1,r,L,R);
	}
	if(mmi&&mma)
	{
		if(da<dd(mmi,mma))
		{
			al=mmi;ar=mma;
			da=dd(mmi,mma);
		}
		if(da==dd(mmi,mma))
		{
			if(mmi<al)
			{
				al=mmi;
				ar=mma;
			}
			else if(al==mmi&&mma<ar)
				ar=mma;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int a,b;
	num[0]=2147483647;
	char tex[10]="Case ";
	num[1]=0;
	for(int cAse=1;read1n(n);cAse++)
	{
		read1n(m);
		write1n(tex);
		write1n(cAse);
		*(O++)=':';*(O++)='\n';
		for(int i=2;i<=n+1;i++)
		{
			read1n(num[i]);
			num[i]+=num[i-1];
		}
		build(1,1,n+1);
		while(m--)
		{
			read1n(a);read1n(b);
			b++;
			al=a;ar=a+1;
			da=num[a+1]-num[a];
			query(1,1,n+1,a,b);
			write1n(al);*(O++)=' ';
			write1n(ar-1);*(O++)='\n';
		}
	}
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

