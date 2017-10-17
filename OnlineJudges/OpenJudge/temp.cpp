#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int x,num=0;
	scanf("%d",&x);
	if(!(x%3)) num++;
	if(!(x%5)) num++;
	if(!(x%7)) num++;
	if(!num) putchar('n');
	else
	{
		if(!(x%3)) { printf("3"); if(--num) putchar(' '); }
		if(!(x%5)) { printf("5"); if(--num) putchar(' '); }
		if(!(x%7)) { printf("7"); if(--num) putchar(' '); }
	}
	return 0;
}

