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
	int Lenth=rand()%20+1;
	printf("%d\n",Lenth);
	for(int i=1;i<=Lenth;i++)
		printf("%c",rand()%26+97);
	fclose(stdout);
	return 0;
}

