#include <bits/stdc++.h>
using namespace std;

#define all(foo) foo.begin(), foo.end()

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define x first
#define y second


typedef long long ll;
typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f;
const int mx = 112345;

set<ii> tree[8*mx];

ii join (int nx0, int nx1, int ny0, int l, int r, int on = 1) {
  if (l > nx1 || r < nx0) return {inf, 0};
  if (l >= nx0 && r <= nx1) {
    auto it = tree[on].lower_bound(ii{ny0, -1});
    if (it != tree[on].end()) {
     return *it;
    }
    return {inf, 0};
  }
  int m = l+r>>1;
  return min(join(nx0, nx1, ny0, l, m, on+on), join(nx0, nx1, ny0, m+1, r, on+on+1));
}

void add (int id, int nx, int ny, int l, int r, int on = 1) {
  tree[on].insert(ii{ny, id});
  if (l == r) return;
  int m = l+r>>1;
  if (nx <= m) {
    add(id, nx, ny, l, m, on+on);
  } else {
    add(id, nx, ny, m+1, r, on+on+1);
  }
}

int arr[mx];

int root (int x) {
  return x == arr[x] ? x : arr[x] = root(arr[x]);
}

void join (int a, int b) {
  a = root(a);
  b = root(b);
  arr[a] = b;
}

int main () {
  int q, R;
  cin >> q >> R;
  iota(arr, arr+mx, 0);
  for (int i = 0; i < q; i++) {
    int x, y;
    char c;
    scanf(" %c", &c);
    sc2(x, y);
    if (c == '+') {
      int nx = x+y, ny = x-y;
      auto a = join(nx, nx+2*R, ny, 1, 2e5);
      auto c = join(nx, nx+2*R, ny-2*R, 1, 2e5);
      
      auto b = join(nx-2*R, nx, ny, 1, 2e5);
      auto d = join(nx-2*R, nx, ny-2*R, 1, 2e5);
      if (a.x != inf && a.x <= ny+2*R) join(i, a.y);
      if (b.x != inf && b.x <= ny+2*R) join(i, b.y);
      if (c.x != inf && c.x <= ny+2*R) join(i, c.y);
      if (d.x != inf && d.x <= ny+2*R) join(i, d.y);
      add(i, nx, ny, 1, 2e5);
    } else {
      x--, y--;
      puts(root(x) == root(y) ? "DA" : "NET");
    }
  }
}
