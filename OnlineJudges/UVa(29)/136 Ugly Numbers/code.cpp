#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >q;
set<long long>s;
int main()
{
	freopen("code.out","w",stdout);
	long long temp;
	q.push(1);
	for(int i=1;;i++)
	{
		temp=q.top();
		q.pop();
		if(i==1500)
		{
			printf("The 1500'th ugly number is %lld.",temp);
			break;
		}
		if(!s.count(2*temp))
		{
			s.insert(2*temp);
			q.push(2*temp);
		}
		if(!s.count(3*temp))
		{
			s.insert(3*temp);
			q.push(3*temp);
		}
		if(!s.count(5*temp))
		{
			s.insert(5*temp);
			q.push(5*temp);
		}
	}
	fclose(stdout);
	return 0;
}

