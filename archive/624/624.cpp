#include <cstdio>
#include <stack>

using namespace std;

int N; // capacity of the CD
int M; // number of tracks
int A[20]; // lengths of tracks

bool read()
{
  if ( scanf("%d %d", &N, &M)==EOF ) return false;
  else {
    for ( int i=0; i<M; ++i ) scanf("%d", &A[i]);
    return true;
  }
}

void solve()
{
  bool **f = new bool *[M];
  bool **g = new bool *[M];
  for ( int i=0; i<M; ++i ) {
    f[i] = new bool[N+1];
    g[i] = new bool[N+1];

    f[i][0] = true;
    for ( int j=1; j<=N; ++j )
      f[i][j] = false;
  }

  for ( int j=1; j<=N; ++j ) {
    f[0][j] = false;
    g[0][j] = false;
  }
  f[0][A[0]] = true;
  g[0][A[0]] = true;

  for ( int i=1; i<M; ++i ) {
    for ( int j=0; j<=N; ++j ) {
      if ( j-A[i]>=0 && f[i-1][j-A[i]] ) {
	f[i][j] = f[i-1][j-A[i]];
	g[i][j] = true;
      }
      else {
	f[i][j] = f[i-1][j];
	g[i][j] = false;
      }
    }
  }

  int max = 0;
  for ( int j=0; j<=N; ++j ) {
    if ( f[M-1][j] ) max = j;
  }

  int i = M-1;
  int j = max;
  stack<int> stack;
  while ( j != 0 ) {
    if ( g[i][j] ) {
      //printf("%d ", A[i]);
      stack.push( A[i] );
      j -= A[i];
    }
    --i;
  }

  while ( !stack.empty() ) {
    printf("%d ", stack.top());
    stack.pop();
  }

/*
  for ( int i=0; i<M; ++i )
    if ( g[i][max-A[i]] )
      printf("%d ", A[i]);
*/
  printf("sum:%d\n", max);

  delete [] f;
}

int main()
{
  while ( read() ) {
    solve();
    //break;
  }
}
