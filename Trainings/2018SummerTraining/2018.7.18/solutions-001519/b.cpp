#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stdio.h> 
#include <set> 
#include <algorithm> 
using namespace std;
int main(void)
{
	int n, q, p;
	scanf("%d%d%d", &n, &q, &p);
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	s.insert(p);
	int d = 0;
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			s.insert(x + d);
		}
		else if (t == 2) {
			if (!s.empty()) {
				d++;
				s.erase(s.begin());
				s.insert(*(--s.end()) + 1);
			}
		}
	}
	s.erase(--s.end());
	for (int x : s) {
		printf("%d ", x - d);
	}
	printf("\n");
}