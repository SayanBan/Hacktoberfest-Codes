#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 2000015;

int t;
int n, w;
int a[Maxn];
ii val[Maxn];
ii myint[Maxm];
int st, en;
ll res;

void Solve(int l, int r)
{
	if (l > r) return;
	if (l == r) {
		if (w <= 1) res++;
		return;
	}
	int m = l + r >> 1;
    ii mnmx = ii(a[m], a[m]);
    map <int, ii> M;
    for (int i = m; i <= r; i++) {
    	mnmx.first = min(mnmx.first, a[i]);
    	mnmx.second = max(mnmx.second, a[i]);
    	val[a[i]] = mnmx;
    }
    mnmx = ii(a[m], a[m]);
    for (int i = m - 1; i >= l; i--) {
    	mnmx.first = min(mnmx.first, a[i]);
    	mnmx.second = max(mnmx.second, a[i]);
    	val[a[i]] = mnmx;
    }
    int lef = a[m];
    while (val[lef - 1].first) lef--;
    int rig = a[m];
    while (val[rig + 1].first) rig++;
    ii my = ii(a[m], a[m]);
    st = Maxn, en = Maxn;
    for (int i = a[m]; i <= rig; i++) {
    	my.first = min(my.first, val[i].first);
    	my.second = max(my.second, val[i].second);
    	if (my.second == i) myint[en++] = my;
    }
    my = ii(a[m], a[m]);
    for (int i = a[m] - 1; i >= lef; i--) {
    	my.first = min(my.first, val[i].first);
    	my.second = max(my.second, val[i].second);
    	if (my.first == i) myint[--st] = my;
    }
    int L = Maxn, R = Maxn;
    int len = 0;
    int cur = Maxn + 1;
    while (cur > st) {
    	cur--;
    	while (L < en && (myint[L].second < myint[cur].second || myint[L].second - myint[cur].first + 1 < w)) { L++; len--; }
    	while (L > Maxn && (myint[L - 1].second >= myint[cur].second && myint[L - 1].second - myint[cur].first + 1 >= w)) { L--; len++; }
    	while (R < en && myint[cur].first <= myint[R].first) { R++; len++; }
    	res += max(len, 0);
    }
    for (int i = l; i <= r; i++)
    	val[a[i]] = ii(0, 0);
    Solve(l, m - 1); Solve(m + 1, r);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &w);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		res = 0;
		Solve(0, n - 1);
		printf("%lld\n", res);
	}
	return 0;
}
