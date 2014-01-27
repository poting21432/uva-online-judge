#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

int N;
int A[MAX_N][MAX_N];
int S[MAX_N][MAX_N];

bool read()
{
  if ( scanf("%d", &N)==EOF )
    return false;
  else {
    for ( int i=0; i<N; ++i ) 
      for ( int j=0; j<N; ++j )
	scanf("%d", &A[i][j]);
    return true;
  }
}

void prepare()
{
  S[0][0] = A[0][0];
  for ( int i=1; i<N; ++i ) S[i][0] = S[i-1][0] + A[i][0];
  for ( int j=1; j<N; ++j ) S[0][j] = S[0][j-1] + A[0][j];
  for ( int i=1; i<N; ++i )
    for ( int j=1; j<N; ++j )
      S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
}

int sum(int i1, int j1, int i2, int j2)
{
  if ( i1==0 && j1==0 )
    return S[i2][j2];
  else if ( i1==0 )
    return S[i2][j2] - S[i2][j1-1];
  else if ( j1==0 )
    return S[i2][j2] - S[i1-1][j2];
  else
    return S[i2][j2] - S[i2][j1-1] - S[i1-1][j2] + S[i1-1][j1-1];
}

void solve()
{
  int max_sum = INT_MIN;
  for ( int i1=0; i1<N; ++i1 )
    for ( int j1=0; j1<N; ++j1 )
      for ( int i2=i1; i2<N; ++i2 )
	for ( int j2=j1; j2<N; ++j2 )
	  max_sum = max(max_sum, sum(i1,j1,i2,j2));
  printf("%d\n", max_sum);
}

int main()
{
  while ( read() ) {
    prepare();
    solve();
  }
}
