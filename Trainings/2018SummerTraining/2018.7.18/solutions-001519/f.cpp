/*
ID: konak
LANG: C++
PROG: vnyc
*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(x) (x).begin(),(x).end()
#define VAR(v,init) __typeof(init) v=init
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

template<class T>
inline int size(const T&a) { return a.size(); }

/////////////////////////////////////////

const int INF = 1000 * 1000 * 1000;

typedef pair<int,int> Point;

Point rotate(Point p) {
    return Point(p.first+p.second,p.second-p.first);
}

struct TreeEntry {
    vector<int> entries;
    int min;
    int max;
};

int power_of_two(int x) {
    int y = 1;
    while (y < x) y *= 2;
    return y;
}

int left(int x) {
    return 2*x+1;
}

int right(int x) {
    return 2*x+2;
}

void construct_tree(vector<Point> &input, vector<TreeEntry> &tree) {
    sort(input.begin(),input.end());
    int R = power_of_two(size(input));
    while (size(input) < R)
	input.push_back(Point(INF,INF));
    tree.resize(2*R-1);
	
    REP(i,R) {
	tree[i+R-1].min = input[i].first;
	tree[i+R-1].max = input[i].first;
	tree[i+R-1].entries.push_back(input[i].second);
    }
    FORD(i,R-2,0) {
	int l = left(i);
	int r = right(i);
	tree[i].min = tree[l].min;
	tree[i].max = tree[r].max;
	copy(tree[l].entries.begin(),tree[l].entries.end(),back_inserter(tree[i].entries));
	copy(tree[r].entries.begin(),tree[r].entries.end(),back_inserter(tree[i].entries));
	sort(tree[i].entries.begin(),tree[i].entries.end());
    }
}

int integers_lower_eq_than(const vector<int> &v, int y) {
    return int(upper_bound(v.begin(),v.end(),y) - v.begin());
}

int count_rec(vector<TreeEntry> &tree,int node, int x, int y) {
//    if (node >= size(tree)) return 0;
    if (tree[node].min > x) return 0;
    if (tree[node].max <= x) return integers_lower_eq_than(tree[node].entries,y);
    return count_rec(tree,left(node),x,y) + count_rec(tree,right(node),x,y);
}

int count_points(vector<TreeEntry> &tree, Point p) {
    return count_rec(tree,0,p.first,p.second);
}

int main() {
	int R;
	scanf("%d",&R);

	vector<Point> points;
	REP(nothing2,R) {
	    int x,y;
	    scanf("%d%d",&x,&y);
	    Point p(x,y);
	    points.push_back(rotate(p));
	}

	vector<TreeEntry> tree;
	construct_tree(points, tree);

	int Q;
	scanf("%d",&Q);
	REP(nothing3,Q) {
	    int x,y,d;
	    scanf("%d%d%d",&x,&y,&d);
	
	    Point p = rotate(Point(x,y+d));
	    int result = count_points(tree,p);

	    p = rotate(Point(x+d,y));
	    --p.second;
	    result -= count_points(tree,p);

	    p = rotate(Point(x-d,y));
	    --p.first;
	    result -= count_points(tree,p);

	    p = rotate(Point(x,y-d));
	    --p.first;
	    --p.second;
	    result += count_points(tree,p);

	    printf("%d\n",result);
	}
}