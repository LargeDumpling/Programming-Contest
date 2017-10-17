/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-26	File created.
*/

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
	int n=rand()%200000+1,m=rand()%200000+1;
	int a,b,c;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) putchar(rand()%2+'0'); putchar('\n');
	while(m--)
	{
		if(!n) a=b=0;
		else
		{
			a=rand()%4;
			b=rand()%n+1;
		}
		printf("%d",a+1);
		switch(a)
		{
			case 0://1
				c=rand()%2+'0';
				n++;
				printf(" %d %c\n",b,c);
				break;
			case 1://2
				printf(" %d\n",b);
				n--;
				break;
			case 2://3
				c=rand()%n+1;
				if(b>c) swap(b,c);
				printf(" %d %d\n",b,c);
				break;
			case 3://4
				c=rand()%n+1;
				if(b>c) swap(b,c);
				printf(" %d %d\n",b,c);
				break;
			default: break;
		}
	}
	fclose(stdout);
	return 0;
}

