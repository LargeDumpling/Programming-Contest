/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int rand(int l, int r) {
	return l + rand() % (r - l + 1);
}

char randchar() {
	return 'a' + rand(0, 25);
}

string random(int n) {
	string res;
	for(int i = 0; i < n; i++) {
		res.push_back(randchar());
	}
	return res;
}

void getfull(string& s, int n) {
	while(s.size() < n) s.push_back(randchar());
}

string s[10000];

void get(int m, int n) {
	printf("%d\n", m);
	string t(random(n / 2));
	for(int i = 0; i < m; i++) {
		s[i].clear();
	}
	for(int i = 0; i < m / 2+1; i++) {
		s[i] = t;
	}
	for(int i = 0; i < m; i++) {
		getfull(s[i], n);
	}
	for(int i = 0; i < m; i++) {
		cout << s[i] << endl;
	}
}

int main()
{
	freopen("code.in", "w", stdout);
	srand(time(NULL));
	for(int T = 0; T < 1; T++) get(100, 1000);
	get(0, 0);

	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

