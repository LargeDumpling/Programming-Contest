#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n=rand()%100+1,m=rand()%100+1,lenth;
	char tex[105][1005];
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
	{
		lenth=rand()%1000+1;
		for(int j=0;j<lenth;j++)
			tex[i][j]=rand()%26+97;
		tex[i][lenth]='\0';
		printf("%s\n",tex[i]);
	}
	for(int i=1;i<=m;i++)
		if(rand()%2)
		{
			lenth=rand()%4000+1;
			for(int i=1;i<=lenth;i++)
				printf("%c",rand()%26+97);
			printf("%s",tex[rand()%n+1]);
			lenth=rand()%4000+1;
			for(int i=1;i<=lenth;i++)
				printf("%c",rand()%26+97);
			printf("\n");
		}
		else
		{
			lenth=rand()%10000+1;
			for(int i=1;i<=lenth;i++)
				printf("%c",rand()%26+97);
			printf("\n");
		}
	fclose(stdout);
	return 0;
}

