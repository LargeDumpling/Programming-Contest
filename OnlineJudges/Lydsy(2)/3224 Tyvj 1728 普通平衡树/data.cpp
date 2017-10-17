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
	//freopen(".in","r",stdin);
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n,num[100050],nu=0,opt;
	n=rand()%10+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		if(nu)
		{
			opt=rand()%6+1;
			if(opt==1)
				printf("1 %d\n",num[++nu]=rand());
			else if(opt==2)
				printf("2 %d\n",num[nu--]);
			else if(opt==3)
				printf("3 %d\n",rand());
			else if(opt==4)
				printf("4 %d\n",rand()%nu+1);
			else if(opt==5)
				printf("5 %d\n",rand());
			else if(opt==6)
				printf("6 %d\n",rand());
		}
		else
		{
			opt=rand()%4+1;
			if(opt==1)
				printf("1 %d\n",num[++nu]=rand());
			else if(opt==2)
				printf("3 %d\n",rand());
			else if(opt==3)
				printf("5 %d\n",rand());
			else if(opt==4)
				printf("6 %d\n",rand());
		}
	}
	//fclose(stdin);
	fclose(stdout);
	return 0;
}


