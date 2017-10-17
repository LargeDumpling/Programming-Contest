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
	int n=rand()%10+1,num=0,order,numb[20];
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		order=rand()%3;
		if(order==0)
		{
			numb[++num]=rand()%20+1;
			printf("0 %d\n",numb[num]);
		}
		else if(order==1)
		{
			if(!num)
				printf("2\n");
			else
				printf("1 %d\n",numb[rand()%(num--)+1]);
		}
		else
			printf("2\n");
	}
	fclose(stdout);
	return 0;
}

