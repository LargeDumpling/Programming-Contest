/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
struct jz
{
	int id,cnt;
	double total;
	jz() { id=cnt=total=0; }
	bool operator<(const jz &X)const
	{
		if(total==X.total) return cnt==X.cnt?id<X.id:cnt>X.cnt;
		return total>X.total;
	}
}p[MAXN];
int n,k;
int main()
{
	int x;
	double sum,pri;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		sum=0;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%lf",&x,&pri);
			sum+=pri;
			p[x].cnt++;
			p[x].total+=pri;
		}
		p[i].total-=sum;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		printf("%d %.2lf\n",p[i].id,p[i].total/100.);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

