#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=10000007;
const int MAXN=100050;
struct jp
{
	long long data;
	jp* next;
	jp(const int &X=0):data(X) { next=NULL; }
}*h[mod];
int n,p;
int a[MAXN];
void add(long long x)
{
	int pos=x%mod;
	if(h[pos]==NULL) h[pos]=new jp(x);
	else for(jp *i=h[pos];i!=NULL;i=i->next)
	{
		if(i->data==x) break;
		else if(i->next==NULL) i->next=new jp(x);
	}
	return;
}
bool trovi(long long x)
{
	int pos=x%mod;
	for(jp *i=h[pos];i!=NULL;i=i->next)
		if(i->data==x) return true;
	return false;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int ans;
	read1n(n); read1n(p);
	ans=n;
	for(int i=1;i<=n;i++)
		read1n(a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i;i--)
		if(trovi((long long)a[i]*p)) ans--;
		else add((long long)a[i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

