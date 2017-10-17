#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int pan[35],pn;
void sWap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void inverse(int k)
{
	for(int i=(k>>1);i;i--)
		sWap(pan[i],pan[k-i+1]);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int mAx;
	string in;
	while(getline(cin,in))
	{
		cout<<in<<"\n";
		stringstream IN(in);
		pn=0;
		while(IN>>pan[pn+1])pn++;
		for(int i=pn;i>1;i--)
		{
			mAx=1;
			for(int j=2;j<=i;j++)
				if(pan[j]>pan[mAx])
					mAx=j;
			if(mAx!=i)
			{
				if(mAx>1)
					printf("%d ",pn-mAx+1),inverse(mAx);
				printf("%d ",pn-i+1);
				inverse(i);
			}
		}
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

