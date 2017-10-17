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
	int n,lenth;
	n=rand()%40+1;
	while(n--)
	{
		if(!n%10)
			printf("\n");
		lenth=rand()%10+2;
		for(int i=1;i<=lenth;i++)
			printf("%c",rand()%26+97);
		printf(" ");
	}
	printf("\n#");
	fclose(stdout);
	return 0;
}

