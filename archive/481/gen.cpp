#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  const int N = 50000;
  int A[N];
  for ( int i=0; i<N; ++i )
    A[i] = (i+1)*10;

  srand(time(0));
  int shuffle_count = rand()%100;
  while ( shuffle_count-- )
    random_shuffle(A, A+N);

  for ( int i=0; i<N; ++i )
    printf("%d\n", A[i]);
}
