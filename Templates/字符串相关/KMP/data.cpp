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
	int lenth;
	char tex[1005];
	lenth=rand()%1000+1;
	for(int j=0;j<lenth;j++)
		tex[j]=rand()%26+97;
	tex[lenth]='\0';
	printf("%s\n",tex);
	if(rand()%2)
	{
		lenth=rand()%4000;
		for(int i=1;i<=lenth;i++)
			printf("%c",rand()%26+97);
		printf("%s",tex);
		lenth=rand()%4000;
		for(int i=1;i<=lenth;i++)
			printf("%c",rand()%26+97);
		printf("\n");
	}
	else
	{
		lenth=rand()%10000;
		for(int i=1;i<=lenth;i++)
			printf("%c",rand()%26+97);
		printf("\n");
	}
	fclose(stdout);
	return 0;
}

