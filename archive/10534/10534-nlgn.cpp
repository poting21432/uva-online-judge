#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

int n;
int a[MAX_N];
int f[MAX_N]; // length of LIS forward
int g[MAX_N]; // length of LIS backward
vector<int> F; // quasai-LIS forward
vector<int> G; // quasai-LIS backward

bool read()
{
  if ( scanf("%d", &n)==EOF )
    return false;
  else {
    for ( int i=0; i<n; ++i )
      scanf("%d", &a[i]);
    return true;
  }
}

void solve()
{
  // LIS forward
  f[0] = 1;
  F.clear();
  F.push_back(a[0]);
  for ( int i=1; i<n; ++i ) {
    if ( a[i] > F[F.size()-1] ) {
      F.push_back(a[i]);
      f[i] = F.size();
    }
    else {
      vector<int>::iterator it = lower_bound(F.begin(), F.end(), a[i]);
      *it = a[i];
      f[i] = it - F.begin() + 1;
    }
    //printf("f[%d] = %d\n", i, f[i]);
  }

  // LIS backward
  g[n-1] = 1;
  G.clear();
  G.push_back(a[n-1]);
  for ( int i=n-2; i>=0; --i ) {
    if ( a[i] > G[G.size()-1] ) {
      G.push_back(a[i]);
      g[i] = G.size();
    }
    else {
      vector<int>::iterator it = lower_bound(G.begin(), G.end(), a[i]);
      *it = a[i];
      g[i] = it - G.begin() + 1;
    }
    //printf("f[%d] = %d\n", i, f[i]);
  }

  // combine
  int max_length = 0;
  for ( int i=0; i<n; ++i ) {
    int wavio_length = 2*min(f[i],g[i]) - 1;
    if ( wavio_length > max_length )
      max_length = wavio_length;
  }

  printf("%d\n", max_length);
}

int main()
{
  while ( read() )
    solve();
}
