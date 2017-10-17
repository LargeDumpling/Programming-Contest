/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
class jp
{
	private:
		vector<int> s;
	public:
		jp() { s.reserve(150000); }
		void insert(int x) { s.insert(upper_bound(s.begin(),s.end(),x),x); }
		void del(int x) { s.erase(lower_bound(s.begin(),s.end(),x)); }
		int rank(int x) { return lower_bound(s.begin(),s.end(),x)-s.begin()+1; }
		int kth(int x) { return s[x-1]; }
		int pre(int x) { return *(--lower_bound(s.begin(),s.end(),x)); }
		int next(int x) { return *upper_bound(s.begin(),s.end(),x); }
}Traep;
int main()
{
	freopen("code.in","r",stdin);
	freopen("vector.out","w",stdout);
	int T_T,a,b;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&a,&b);
		switch(a)
		{
			case 1: Traep.insert(b); break;
			case 2: Traep.del(b); break;
			case 3: printf("%d\n",Traep.rank(b)); break;
			case 4: printf("%d\n",Traep.kth(b)); break;
			case 5: printf("%d\n",Traep.pre(b)); break;
			case 6: printf("%d\n",Traep.next(b)); break;
			default: break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

