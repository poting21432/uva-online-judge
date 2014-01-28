#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int N;
stack<int> L, M;

bool check()
{
  for ( int desired=N; desired>=1; --desired ) {
    if ( !M.empty() && M.top()==desired ) {
      M.pop();
    }
    else {
      bool in_L = false;
      while ( !L.empty() ) {
	int train = L.top(); L.pop();
	if ( train==desired ) {
	  in_L = true;
	  break;
	}
	else {
	  M.push(train);
	}
      }
      if ( !in_L )
	return false;
    }
  }
  return true;
}

int main()
{
  while ( ~scanf("%d", &N) && N!=0 ) {
    int x;
    while ( ~scanf("%d", &x) && x!=0 ) {
      while ( !L.empty() ) L.pop();
      while ( !M.empty() ) M.pop();
      L.push(x);
      for ( int i=1; i<N; ++i ) {
	scanf("%d", &x);
	L.push(x);
      }
      puts(check()?"Yes":"No");
    }
    putchar('\n');
  }
}
