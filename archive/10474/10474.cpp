#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N; // number of marbles
int Q; // number of queries
vector<int> A;

int main()
{
  int t = 0;
  while ( ~scanf("%d %d", &N, &Q) && !(N==0 && Q==0) ) {
    printf("CASE# %d:\n", ++t);
    A.clear();
    A.resize(N);
    for ( int i=0; i<N; ++i ) {
      scanf("%d", &A[i]);
      //printf("A[%d] = %d\n", i, A[i]);
    }

    sort(A.begin(), A.end());

    for ( int i=0; i<Q; ++i ) {
      int x;
      scanf("%d", &x);
      vector<int>::iterator pos = lower_bound(A.begin(), A.end(), x);
      if ( *pos != x )
	printf("%d not found\n", x);
      else
	printf("%d found at %zd\n", x, pos-A.begin()+1);
    }
  }
}
