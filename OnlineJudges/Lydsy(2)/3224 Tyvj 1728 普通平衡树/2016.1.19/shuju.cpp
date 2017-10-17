#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int a[100010],ed=1;
int main()
{
	srand(time(NULL));
	freopen("code.in","w",stdout);
	int n=100000;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++)
	{
		int op=rand()%6+1;
		cout<<op<<" ";
		if(op==4)cout<<rand()%i+1<<"\n";
		else if(op==2)cout<<a[rand()%ed+1]<<"\n";
		else 
		{
			a[ed++]=rand()*rand()%10+1;
			cout<<a[ed-1]<<"\n";
		}
	}
	return 0;
}

