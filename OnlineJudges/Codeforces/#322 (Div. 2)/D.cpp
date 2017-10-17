#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int x,y;
	int type;
}blo[4];
bool cnmp(jp A,jp B){return A.x==B.x?A.y>B.y:A.x>B.x;}
int main()
{
	scanf("%d%d%d%d%d%d",&blo[1].x,&blo[1].y,&blo[2].x,&blo[2].y,&blo[3].x,&blo[3].y);
	blo[1].type=1;
	blo[2].type=2;
	blo[3].type=3;
	if(blo[1].x<blo[1].y)
	{
		blo[1].x+=blo[1].y;
		blo[1].y=blo[1].x-blo[1].y;
		blo[1].x-=blo[1].y;
	}
	if(blo[2].x<blo[2].y)
	{
		blo[2].x+=blo[2].y;
		blo[2].y=blo[2].x-blo[2].y;
		blo[2].x-=blo[2].y;
	}
	if(blo[3].x<blo[3].y)
	{
		blo[3].x+=blo[3].y;
		blo[3].y=blo[3].x-blo[3].y;
		blo[3].x-=blo[3].y;
	}
	sort(blo+1,blo+4,cnmp);
	if(blo[1].x==blo[2].x&&blo[2].x==blo[3].x
	&&blo[1].x==blo[1].y+blo[2].y+blo[3].y)
	{
		for(int j=1;j<=blo[1].y;j++)
		{
			for(int i=1;i<=blo[1].x;i++)
				printf("%c",'A'-1+blo[1].type);
			printf("\n");
		}
		for(int j=1;j<=blo[2].y;j++)
		{
			for(int i=1;i<=blo[1].x;i++)
				printf("%c",'A'-1+blo[2].type);
			printf("\n");
		}
		for(int j=1;j<=blo[3].y;j++)
		{
			for(int i=1;i<=blo[1].x;i++)
				printf("%c",'A'-1+blo[3].type);
			printf("\n");
		}
	}
	else if(blo[1].x==blo[2].y+blo[3].y
	&&blo[2].y+blo[3].y==blo[2].x+blo[1].y
	&&blo[2].x==blo[3].x)
	{
		for(int i=1;i<=blo[1].y;i++)
		{
			for(int j=1;j<=blo[1].x;j++)
				printf("%c",'A'-1+blo[1].type);
			printf("\n");
		}
		for(int i=1;i<=blo[2].x;i++)
		{
			for(int i=1;i<=blo[1].x;i++)
			{
				if(i<=blo[2].y)
					printf("%c",'A'-1+blo[2].type);
				else
					printf("%c",'A'-1+blo[3].type);
			}
			printf("\n");
		}
	}
	else
		printf("-1");
    return 0;
}

