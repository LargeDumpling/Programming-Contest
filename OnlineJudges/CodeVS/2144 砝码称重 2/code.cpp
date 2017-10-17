#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=100007;
struct jp
{
	int pos,data;
	jp *next;
	jp() { next=NULL; }
}*h[mod];
int n,m,ans;
long long a[35];
void asigno(long long x,int key)
{
	int pos=abs(x)%mod;
	if(h[pos]==NULL)
	{
		h[pos]=new jp;
		h[pos]->pos=x;
		h[pos]->data=key;
	}
	else for(jp *i=h[pos];i!=NULL;i=i->next)
	{
		if(i->pos==x)
		{
			i->data=min(i->data,key);
			return;
		}
		else if(i->next==NULL)
		{
			i->next=new jp;
			(i->next)->pos=x;
			(i->next)->data=key;
			return;
		}
	}
	return;
}
bool trovi(long long x)
{
	int pos=abs(x)%mod;
	for(jp *i=h[pos];i!=NULL;i=i->next)
		if(i->pos==x)
			return true;
	return false;
}
int enketado(long long x)
{
	int pos=abs(x)%mod;
	for(jp *i=h[pos];i!=NULL;i=i->next)
		if(i->pos==x)
			return i->data;
	return 1<<30;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int limit,n2,cnt;
	long long sum;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	n2=n/2;
	limit=1<<n2;
	for(int i=0;i<limit;i++)
	{
		sum=cnt=0;
		for(int j=0;j<n2;j++) if(i&(1<<j))
		{
			cnt++;
			sum+=a[j];
		}
		asigno(sum,cnt);
	}
	ans=2147483647;
	limit=1<<(n-n2);
	for(int i=0;i<limit;i++)
	{
		sum=cnt=0;
		for(int j=0;j<n-n2;j++) if(i&(1<<j))
		{
			cnt++;
			sum+=a[n2+j];
		}
		if(trovi(m-sum))
			ans=min(ans,enketado(m-sum)+cnt);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

