#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
map<set<int>,int> IDs;
vector<set<int> > vec;
int T,n;
int get_ID(set<int> x)
{
	if(IDs.count(x))return IDs[x];
	vec.push_back(x);
	return IDs[x]=vec.size()-1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char ch[10];
	set<int> x1,x2,x;
	scanf("%d",&T);
	while(T--)
	{
		stack<int> s;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ch);
			if(ch[2]=='S')
			{//PUSH
				s.push(get_ID(set<int>()));
			}
			else if(ch[2]=='P')
			{//DUP
				s.push(s.top());
			}
			else if(ch[2]=='I')
			{//UNION
				x1=vec[s.top()];s.pop();
				x2=vec[s.top()];s.pop();
				x.clear();
				set_union(ALL(x1),ALL(x2),INS(x));
				s.push(get_ID(x));
			}
			else if(ch[2]=='T')
			{//INTERSECT
				x1=vec[s.top()];s.pop();
				x2=vec[s.top()];s.pop();
				x.clear();
				set_intersection(ALL(x1),ALL(x2),INS(x));
				s.push(get_ID(x));
			}
			else if(ch[2]=='D')
			{//ADD
				x1=vec[s.top()];s.pop();
				x=x2=vec[s.top()];s.pop();
				x.insert(get_ID(x1));
				s.push(get_ID(x));
			}
			printf("%d\n",vec[s.top()].size());
		}
		printf("***\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

