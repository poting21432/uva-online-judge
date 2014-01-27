#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> A;
vector<int> f;
vector<int> pre;

int main()
{
  int x;
  while ( ~scanf("%d", &x) )
    A.push_back(x);
  N = A.size();

  f.resize(N);
  pre.resize(N);
  f[0] = 1;
  pre[0] = -1;
  for ( int i=1; i<N; ++i ) {
    f[i] = 1;
    pre[i] = -1;
    for ( int j=0; j<i; ++j ) {
      if ( A[j] < A[i] && f[j]+1 >= f[i] ) {
	f[i] = f[j] + 1;
	pre[i] = j;
      }
    }
    //printf("f[%d] = %d, pre[%d] = %d\n", i, f[i], i, pre[i]);
  }

  int max_len = 1;
  int end = 0;
  for ( int i=0; i<N; ++i ) {
    if ( f[i] >= max_len ) {
      max_len = f[i];
      end     =   i ;
    }
  }

  printf("%d\n-\n", max_len);

  stack<int> stack;
  while ( true ) {
    stack.push(A[end]);
    if ( pre[end]==-1 ) break;
    else end = pre[end];
  }

  while ( !stack.empty() ) {
    printf("%d\n", stack.top());
    stack.pop();
  }
}
