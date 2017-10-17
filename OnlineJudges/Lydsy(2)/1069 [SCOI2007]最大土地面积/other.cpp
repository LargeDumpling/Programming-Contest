#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<deque>
#define inf 2000000000
using namespace std;
int n,top;
struct P{double x,y;}p[2005],s[2005];
double dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
P operator-(P a,P b)
{
	P t;t.x=a.x-b.x;t.y=a.y-b.y;return t;
}
double operator*(P a,P b)
{
	return a.x*b.y-a.y*b.x;
}
bool operator<(P a,P b)
{
	double t=(a-p[1])*(b-p[1]);
	if(t==0)return dis(a,p[1])<dis(b,p[1]);
	return t<0;
}
void graham()
{
	int k=1;
	for(int i=2;i<=n;i++)
		if(p[k].y>p[i].y||(p[k].y==p[i].y&&p[k].x>p[i].x))
			k=i;
	swap(p[1],p[k]);
	sort(p+2,p+n+1);
	s[++top]=p[1];s[++top]=p[2];
	for(int i=3;i<=n;i++)
	{
		while(top>1&&(p[i]-s[top-1])*(s[top]-s[top-1])<=0)
			top--;
		s[++top]=p[i];
	}
}
double RC()
{
	s[top+1]=p[1];
	double ans=0;
	int a,b;
	for(int x=1;x<=top;x++)
	{
		a=x%top+1;b=(x+2)%top+1;
		for(int y=x+2;y<=top;y++)
		{
			while(a%top+1!=y&&(s[y]-s[x])*(s[a+1]-s[x])>(s[y]-s[x])*(s[a]-s[x]))
				a=a%top+1;
			while(b%top+1!=x&&(s[b+1]-s[x])*(s[y]-s[x])>(s[b]-s[x])*(s[y]-s[x]))
				b=b%top+1;
			ans=max((s[y]-s[x])*(s[a]-s[x])+(s[b]-s[x])*(s[y]-s[x]),ans);
		}
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	graham();
	printf("%.3lf",RC()/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
