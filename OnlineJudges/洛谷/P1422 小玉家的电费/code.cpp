#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	double ans=0;
	int x;
	scanf("%d",&x);
	if(x<=150)
		ans=0.4463*x;
	else if(x<=400)
		ans=0.4463*150+0.4663*(x-150);
	else
		ans=0.4463*150+0.4663*250+0.5663*(x-400);
	printf("%.1f",ans);
	return 0;
}

