#include <cstdio>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

const int MAX_M = 1000;

int  M;
char c[MAX_M][MAX_M];

struct Pos
{
  int i, j;
  Pos(int ni, int nj): i(ni), j(nj) {}
};

int dist(const Pos &a, const Pos &b)
{
  return abs(a.i-b.i) + abs(a.j-b.j);
}

bool read()
{
  if ( ~scanf("%d", &M) ) {
    for ( int i=0; i<M; ++i )
      scanf("%s", c[i]);
    return true;
  }
  else {
    return false;
  }
}

int solve()
{
  vector<Pos> A;
  vector<Pos> B;
  for ( int i=0; i<M; ++i ) {
    for ( int j=0; j<M; ++j ) {
      if      ( c[i][j]=='1' ) A.push_back(Pos(i,j));
      else if ( c[i][j]=='3' ) B.push_back(Pos(i,j));
    }
  }
  int max = INT_MIN;
  for ( int i=0; i<A.size(); ++i ) {
    int min = INT_MAX;
    Pos init = A[i];
    for ( int j=0; j<B.size(); ++j ) {
      int d = dist(init, B[j]);
      if ( d < min ) min = d;
    }
    if ( min > max ) max = min;
  }
  return max;
}

int main()
{
  while ( read() )
    printf("%d\n", solve());
}
