#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

int n;
int a[MAX_N];
int f[MAX_N]; // f[i]: LIS forward
int g[MAX_N]; // g[i]: LIS backward

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
  for ( int i=1; i<n; ++i ) {
    f[i] = 1;
    for ( int j=0; j<i; ++j )
      if ( a[j]<a[i] && f[j]+1>f[i] )
	f[i] = f[j]+1;
    //printf("f[%d] = %d\n", i, f[i]);
  }

  // LIS backward
  g[n-1] = 1;
  for ( int i=n-2; i>=0; --i ) {
    g[i] = 1;
    for ( int j=n-1; j>i; --j )
      if ( a[j]<a[i] && g[j]+1>g[i] )
	g[i] = g[j]+1;
    //printf("g[%d] = %d\n", i, g[i]);
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
