#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<int> s;
int a[200100], h[200100], ans[200100], n, d;
int main() {
    #ifdef TTEST
        freopen("input.txt", "r", stdin);
    #endif
    scanf("%d%*d%d",&n,&d);
    for(int i = 0;i < n; ++i){
        scanf("%d", &a[i]);
        h[a[i]] = i;
        s.insert(a[i]);
    }
    int day = 0;
    while(s.size()){
        ans[h[*s.begin()]] = ++day;
        int x = *s.begin();
        s.erase(x);
        while(s.upper_bound(x + d) != s.end()){
            x = *s.upper_bound(x + d);
            ans[h[x]] = day;
            s.erase(x);
        }
    }
    printf("%d\n", day);
    for(int i = 0;i < n; ++i){
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
    return 0;
}

