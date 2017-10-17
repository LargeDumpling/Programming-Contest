#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		a+=b;
		b=a-b;
		a-=b;
	}
	printf("%d %d",b,(a-b)/2);
    return 0;
}

