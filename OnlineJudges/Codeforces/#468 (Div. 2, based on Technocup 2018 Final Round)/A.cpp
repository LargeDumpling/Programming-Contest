/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,b,sum=0;
int main()
{
	long long i=1;
	cin>>a>>b;
	if(b<a) swap(a,b);
	while(a<b)
	{
		if(a<b-1)
		{
			sum+=i*2LL;
			a++;
			b--;
		}
		else
		{
			sum+=i;
			break;
		}
		i++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

