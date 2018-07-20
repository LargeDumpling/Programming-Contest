#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stdio.h> 
#include <stack> 
#include <algorithm> 
#include <vector>
using namespace std;
#define INF 1000000000 

int n, v, k;
int dp[5005][5005];
int c[5005];

stack<int> a;
stack<int> b;
int get(stack<int>* s, int v) { // least number of coins to make v using coins in s
	if (s->empty()) {
		if (v > 0) {
			return INF;
		}
		else {
			return 0;
		}
	}
	return dp[s->top()][v];
}
void push(stack<int>* s, int i) {
	for (int j = 0; j <= v; j++) {
		dp[i][j] = INF;
	}
	dp[i][0] = 0;
	dp[i][c[i]] = 1;
	if (!s->empty()) {
		for (int j = 0; j <= v; j++) {
			if (j >= c[i]) {
				dp[i][j] = min(dp[i][j], get(s, j - c[i]) + 1);
			}
			dp[i][j] = min(dp[i][j], get(s, j));
		}
	}
	s->push(i);
}


//Mean

double mean() {
	return (double)v / k;
}

//Median

bool checkMedian(int vv) {
	if (vv >= 0) {
		for (int i = 0; i <= vv; i++) {
			if (get(&a, i) == (k % 2 == 1 ? k / 2 : k / 2 - 1) && get(&b, vv - i) == k / 2) {
				return true;
			}
		}
	}
	return false;
}

int median() {
	a = stack<int>();
	b = stack<int>();
	sort(c, c + n);
	for (int i = n - 1; i >= 0; i--) {
		push(&b, i);
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		b.pop();
		if (checkMedian(v - c[i])) {
			ans = min(ans, c[i]);
		}
		push(&a, i);
	}
	return ans;
}

//Mode

vector<int> bycnt[5001];
int cnt[10001];
int mode() {
	a = stack<int>();
	for (int i = 0; i < n; i++) {
		cnt[c[i]]++;
		bycnt[cnt[c[i]]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int x : bycnt[i]) {
			push(&a, x);
		}
		if (get(&a, v) == k) {
			return i;
		}
	}
	return -1;
}

//Range
	
void popqueue() {
	if (b.empty()) { // move everything from in to out
		while (!a.empty()) {
			int i = a.top();
			a.pop();
			push(&b, i);
		}
	}
	b.pop();
}
bool checkRange() {
	for (int i = 0; i <= v; i++) {
		if (get(&a, i) + get(&b, v - i) == k) {
			return true;
		}
	}
	return false;
}
int range() {
	a = stack<int>();
	b = stack<int>();
	sort(c, c + n);
	int j = -1;
	int ans = INF;
	for (int i = 0; i < n; i++) {
		while (!checkRange() && j < n - 1) {
			push(&a, ++j);
		}
		if (checkRange()) {
			ans = min(ans, c[j] - c[i]);
		}
		popqueue();
	}
	return ans;
}

int main(void)
{
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		push(&a, i);
	}
	k = dp[n - 1][v];
	if (k == INF) {
		cout << -1 << endl;
		return 0;
	}
	printf("%.9f %d %d %d\n", mean(), median(), mode(), range());
}