#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 2005;
int A[MAXN], B[MAXN];
int F[MAXN][MAXN];
set<pair<int, int>> zigdown[MAXN], zigup[MAXN];
void insert(set<pair<int, int>> &S, pair<int, int> v) {
	int len = v.second;
	auto it = S.lower_bound({v.first, -1});
	if (prev(it)->second >= len) return;
	while (it != S.end() && it->second <= len) S.erase(it++);
	S.insert(v);
}
int query(set<pair<int, int>> &S, int v) {
	auto it = S.lower_bound({v, -1});
	return prev(it)->second;
}
int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &B[i]);
		zigdown[i] = {{INT_MIN, 0}};
		zigup[i] = {{INT_MIN, 0}};
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int bestdown = 0, bestup = 0;
		for (int j = 1; j <= M; ++j) {
			if (A[i] == B[j]) {
				bestup = max(bestup, query(zigdown[j], A[i]) + 1);
				bestdown = max(bestdown, query(zigup[j], -A[i]) + 1);
			}
			insert(zigdown[j], {A[i], bestdown});
			insert(zigup[j], {-A[i], bestup});
		}
		ans = max(ans, max(bestup, bestdown));
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i] == B[j]) F[i][j] = F[i - 1][j - 1] + 1;
			else F[i][j] = max(F[i - 1][j], F[i][j - 1]);
		}
	}
	if (ans < 2 && F[N][M] >= 2) ans = 2;
	printf("%d\n", ans);
}
