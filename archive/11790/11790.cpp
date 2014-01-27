#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

int N;

struct Building
{
  int H, W;
} A[MAX_N];

int f[MAX_N]; // longest increasing subsequence
int g[MAX_N]; // longest decreasing subsequence

void read()
{
  scanf("%d", &N);
  for ( int i=0; i<N; ++i ) scanf("%d", &A[i].H);
  for ( int i=0; i<N; ++i ) scanf("%d", &A[i].W);
}

void solve()
{
  int f_max;
  int g_max;
  f_max = f[0] = A[0].W;
  g_max = g[0] = A[0].W;
  for ( int i=1; i<N; ++i ) {
    f[i] = A[i].W;
    g[i] = A[i].W;
    for ( int j=0; j<i; ++j ) {
      if ( A[i].H>A[j].H && f[j]+A[i].W>f[i] ) f[i] = f[j]+A[i].W;
      if ( A[i].H<A[j].H && g[j]+A[i].W>g[i] ) g[i] = g[j]+A[i].W;
      if ( f[i] > f_max ) f_max = f[i];
      if ( g[i] > g_max ) g_max = g[i];
    }
  }
  //printf("f_max=%d, g_max=%d\n", f_max, g_max);
  if ( f_max >= g_max ) printf("Increasing (%d). Decreasing (%d).\n", f_max, g_max);
  else                  printf("Decreasing (%d). Increasing (%d).\n", g_max, f_max);
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    printf("Case %d. ", t);
    read();
    solve();
  }
}
