/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("C.in","w",stdout);
	int T_T,n,q,l,r,op;
	printf("%d\n",T_T=1);
	while(T_T--)
	{
		printf("%d %d\n",n=rand()%5+1,q=rand()%5+1);
		for(int i=1;i<=n;i++)
			printf("%d ",rand()%5+1);
		putchar('\n');
		while(q--)
		{
			printf("%d ",op=rand()%3+1);
			l=rand()%n+1;
			r=rand()%n+1;
			if(r<l) swap(l,r);
			printf("%d %d",l,r);
			switch(op)
			{
				case 1:
					printf(" %d",rand()%5+1);
					break;
				case 2:
					printf(" %d",rand()%5+1);
					break;
				case 3:
					break;
				default:
					break;
			}
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

