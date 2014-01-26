#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

bool check(const vector<int> &A, int N)
{
  bool covered[91];
  memset(covered, 0, sizeof(covered));
  for ( int i=0; i<A.size(); ++i ) {
    for ( int j=i; j<A.size(); ++j ) {
      int x = abs(A[i]-A[j]);
      //printf("(%d,%d) -> %d\n", A[i], A[j], x);
      covered[x] = true;
    }
  }
  for ( int i=0; i<=N; ++i )
    if ( !covered[i] )
      return false;
  return true;
}

int main()
{
  int N, B;
  while ( ~scanf("%d %d", &N, &B) && !(N==0 && B==0) ) {
    vector<int> A;
    for ( int i=0; i<B; ++i ) {
      int x;
      scanf("%d", &x);
      A.push_back(x);
    }
    puts(check(A,N)?"Y":"N");
  }
}
