#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
struct jp
{
	int x,y;
	jp(int X=0,int Y=0):x(X),y(Y){}
	bool operator<(const jp A)const
	{
		return x==A.x?y<A.y:x<A.x;
	}
}poi[105];
int n;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	bool flag,exi[105];
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&poi[i].x,&poi[i].y);
	sort(poi+1,poi+n+1);
	for(int i=1;i<=n;i++)
	{
		flag=true;
		for(int j=1;j<=n;j++)
			if(poi[i].x<=poi[j].x&&poi[i].y<=poi[j].y&&(poi[i].x!=poi[j].x||poi[i].y!=poi[j].y))
				flag=false;
		exi[i]=flag;
		if(flag)cnt++;
	}
	for(int i=1;i<=n;i++)
		if(exi[i])
		{
			cnt--;
			printf("(%d,%d)",poi[i].x,poi[i].y);
			if(cnt)
				printf(",");
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
