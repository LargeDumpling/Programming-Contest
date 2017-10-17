#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int mAx=0,mAxd=0,a,b;
	for(int i=1;i<=7;i++)
	{
		scanf("%d%d",&a,&b);
		if(a+b>=9&&a+b>mAx)
		{
			mAx=a+b;
			mAxd=i;
		}
	}
	printf("%d",mAxd);
	return 0;
}

