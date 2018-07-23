/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const unsigned long long mod=1000000007;
struct jz
{
	unsigned long long h;
	int id,len,cnt;
	jz() { h=id=len=cnt=0; }
	bool operator<(const jz &X)const { return len<X.len; }
}Q[MAXN];
struct jp
{
	int st;
	unsigned long long h;
	jp(const int &ST=0,const unsigned long long &H=0):st(ST),h(H) { }
	bool operator<(const jp &X)const { return h==X.h?st<X.st:h<X.h; }
	bool operator==(const jp &X)const { return h==X.h&&st==X.st; }
};
int n,m,sn;
unsigned long long H[MAXN],P[MAXN];
bool cmp_id(jz A,jz B) { return A.id<B.id; }
jp s[MAXN];
int nExt[MAXN];
void laboras(int len)
{
	sn=0;
	for(int i=len;i<=n;i++)
		s[++sn]=jp(i,(H[i]-H[i-len]*P[len]%mod+mod)%mod);
	sort(s+1,s+sn+1);
	s[0]=s[sn+1]=jp(-1,-1);
	nExt[0]=1;
	for(int i=1;i<=sn;i++)
	{
		/*if(s[i].h==s[i-1].h) nExt[i]=nExt[i-1];
		else nExt[i]=i+1;
		while(nExt[i]<=i||(s[nExt[i]].h==s[i].h&&nExt[i]<i+len)||nExt[i]!=sn+1)
			nExt[i]++;*/
		nExt[i]=lower_bound(s+1,s+sn+1,jp(s[i].st+len,s[i].h))-s;
	}
	return;
}
int query(unsigned long long hash,int len)
{
	int ans=0,t;
	t=lower_bound(s+1,s+sn+1,jp(-1,hash))-s;
	while(s[t].h==hash)
	{
		ans++;
		t=nExt[t];
		//t=lower_bound(s+1,s+sn+1,jp(s[t].st+len,s[t].h))-s;
	}
	return ans;
}
int main()
{
	char ch;
	scanf("%d%d",&n,&m);
	P[0]=1;
	P[1]=29;
	for(int i=2;i<MAXN;i++)
		P[i]=P[i-1]*P[1]%mod;
	H[0]=0;
	for(ch=getchar();ch<'a'||'z'<ch;ch=getchar());
	for(int i=1;'a'<=ch&&ch<='z';ch=getchar(),i++)
		H[i]=(H[i-1]*29%mod+ch-'a'+1)%mod;
	for(int i=1;i<=m;i++)
	{
		Q[i].id=i;
		Q[i].h=0;
		for(;ch<'a'||'z'<ch;ch=getchar());
		for(Q[i].len=0;'a'<=ch&&ch<='z';ch=getchar())
		{
			Q[i].len++;
			Q[i].h=(Q[i].h*P[1]%mod+ch-'a'+1)%mod;
		}
	}
	sort(Q+1,Q+m+1);
	for(int i=1;i<=m;i++)
	{
		if(Q[i].len!=Q[i-1].len)
			laboras(Q[i].len);
		Q[i].cnt=query(Q[i].h,Q[i].len);
	}
	sort(Q+1,Q+m+1,cmp_id);
	for(int i=1;i<=m;i++)
		cout<<Q[i].cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

