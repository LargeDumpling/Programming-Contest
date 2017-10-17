#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
bool data[4050][4050];
int T,n,q;
void add(int x1,int y1)
{
	for(int i=x1,j;i<=n;i+=low(i))
		for(j=y1;j<=n;j+=low(j))
			data[i][j]^=true;
	return;
}
bool query(int x1,int y1)
{
	bool sum=0;
	for(int i=x1,j;i;i-=low(i))
		for(j=y1;j;j-=low(j))
			sum^=data[i][j];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[2];
	int x1,y1,x2,y2;
	scanf("%d",&T);
	while(T--)
	{
		memset(data,false,sizeof(data));
		scanf("%d%d",&n,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%s",tex);
			if(tex[0]=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				//change_x(1,x1,y1,x2,y2,1,n);
				add(x2+1,y2+1);
				add(x1,y2+1);
				add(x2+1,y1);
				add(x1,y1);
			}
			else if(tex[0]=='Q')
			{
				scanf("%d%d",&x1,&y1);
				printf("%d\n",query(x1,y1));
			}
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

