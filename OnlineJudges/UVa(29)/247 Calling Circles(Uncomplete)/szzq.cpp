#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

int n, m, tot;
bool to[30][30];
std::map<std::string, int> name_list;
std::string names[30];

void Build() {
	char s[30]; std::string str; int u, v;
	memset(to, false, sizeof(to));
	for (int i = 1; i <= n; i++) to[i][i] = true;
	tot = 0; name_list.clear();
	while (m--) {
		scanf("%s", s);
		str = std::string(s);
		if (!name_list.count(str)) {
			name_list[str] = ++tot; names[tot] = str;
		}
		u = name_list[str];
		
		scanf("%s", s);
		str = std::string(s);
		if (!name_list.count(str)) {
			name_list[str] = ++tot; names[tot] = str;
		}
		v = name_list[str];
		
		to[u][v] = true;
	}
}

void Floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				to[i][j] |= to[i][k] & to[k][j];
}

void Print(int kase) {
	bool printed[30], fir;
	memset(printed, false, sizeof(printed));
	
	if (kase > 1) puts("");
	printf("Calling circles for data set %d:\n", kase);
	for (int i = 1; i <= n; i++) {
		if (!printed[i]) {
			fir = true;
			for (int j = i; j <= n; j++)
				if (to[i][j] && to[j][i]) {
					if (!fir) printf(", ");
					fir = false;
					printf("%s", names[j].c_str());
					printed[j] = true;
				}
			puts("");
		}
	}
}

int main() {
	freopen("code.in","r",stdin);
	freopen("szzq.out","w",stdout);
	int kase = 0;
	
	while (~scanf("%d%d", &n, &m) && n && m) {
		Build();
		Floyd();
		Print(++kase);
	}
	
	return 0;
}
