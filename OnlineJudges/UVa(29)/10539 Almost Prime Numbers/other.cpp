#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

long long ampr[100001];
long long prim[100001];
int 	  used[1000001];

int bs(int r, long long key)
{
	int l = 0,mid;
	while (l < r) {
		mid = (l+r+1)>>1;
		if (ampr[mid] > key)
			r = mid-1;
		else l = mid;
	}
	return l;
}

bool cmp(long long a, long long b)
{
	return a < b;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	memset(used, 0, sizeof(used));
	int count = 0;
	for (int i = 2 ; i < 1000000 ; ++ i)
		if (!used[i]) {
			prim[count ++] = i;
			for (int j = i<<1 ; j < 1000000 ; j += i)
				used[j] = 1;
		}
	
	int number = 0;
	for (int i = 0 ; i < count ; ++ i) {
		long long base = prim[i]*prim[i]+0LL;
		while (base <= 1000000000000LL) {
			ampr[number ++] = base;
			base = base*prim[i];
		}
	}
	
	sort(ampr, ampr+number, cmp);
	
	int n,x,y;
	while (cin >> n)
	while (n --) {
		long long a,b;
		cin >> a >> b;
		x = bs(number-1, a);
		y = bs(number-1, b);
		if (ampr[x] == a) x --;
		if (ampr[0] > a) x --;
		if (ampr[0] > b) y --;
		cout << y-x << endl;
	}
	return 0;
}

