/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,m,head,tail,q[MAXN],k[MAXN];
long long F,f[MAXN],P[MAXN],x[MAXN],y[MAXN];
long long dx(int p1,int p2) { return x[p2]-x[p1]; }
long long dy(int p1,int p2) { return y[p2]-y[p1]; }
long long cal(int p1,int p2)
{ return f[p1]+(f[p1]-F)/P[p1+1]*P[p2]+(f[p1]-F)%P[p1+1]-F; }
bool cmp(int p1,int p2) { return x[p1]==x[p2]?y[p1]<y[p2]:x[p1]<x[p2]; }
bool cmp_P(int p1,int p2) { return P[p1]<P[p2]; }
vector<int> solve(int l,int r)
{
	if(l==r) return vector<int>(1,l);
	int mid=(l+r)>>1;
	vector<int> left=solve(l,mid);
	vector<int> tem;
	for(int i=mid+1;i<=r;i++) tem.push_back(i);
	sort(tem.begin(),tem.end(),cmp_P);
	head=0;
	tail=-1;
	for(unsigned i=0;i<left.size();i++) q[++tail]=left[i];
	for(unsigned i=0;i<tem.size();i++)
	{
		while(head<tail&&P[tem[i]]*dx(q[head],q[head+1])<=dy(q[head],q[head+1]))
			head++;
		k[tem[i]]=q[head];
		f[tem[i]]=cal(q[head],tem[i]);
	}
	for(int i=mid+1;i<=r;i++)
	{
		if(f[i-1]>f[i])
		{
			f[i]=f[i-1];
			k[i]=-1;
		}
		x[i]=(f[i]-F)/P[i+1];
		y[i]=f[i]+(f[i]-F)%P[i+1];
	}
	vector<int> right=solve(mid+1,r);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d%lld",&n,&m,&F);
	for(int i=1;i<=n;i++) scanf("%lld",&P[i]);
	solve(1,n);
	printf("%);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

