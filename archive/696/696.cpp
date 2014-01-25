#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_SIZE = 500;

int  M, N;
int  max_knights = 0;
int  current_knights = 0;
bool board[MAX_SIZE][MAX_SIZE];

int di[8] = {-2,-2,-1,-1,+1,+1,+2,+2};
int dj[8] = {-1,+1,-2,+2,-2,+2,-1,+1};

bool inBound(int i, int j)
{
  return i>=0 && i<M
      && j>=0 && j<N;
}

bool ok(int i, int j)
{
  for ( int k=0; k<8; ++k ) {
    int ni = i + di[k];
    int nj = j + dj[k];
    if ( inBound(ni,nj) && board[ni][nj] )
      return false;
  }
  return true;
}

void search(int i, int j)
{
  if ( i==M ) { return; }
  if ( j==N ) { search(i+1,0); return; }

  if ( ok(i,j) ) {
    max_knights = max(max_knights, ++current_knights);
    board[i][j] = true;
    search(i, j+1);
    board[i][j] = false;
    --current_knights;
  }

  search(i, j+1);
}

void solve()
{
  max_knights = 0;
  current_knights = 0;
  memset(board, 0, sizeof(board));
  search(0, 0);
  //printf("%d knights may be placed on a %d row %d column board.\n", max_knights, M, N);
  printf("f(M=%d, N=%d) = %d\n", M, N, max_knights);
}

void new_solve()
{
  if ( M>N ) swap(M,N);

  int ans = 0;
  if      ( M==1 ) ans = N;
  else if ( M==2 ) {
    if   ( (N-1)%4==0 ) ans = N+1;
    else                ans = (1+(N-1)/4)*4;
  }
  else {
    ans = (int)ceil(((double)M*(double)N)/2.0);
  }
  printf("%d knights may be placed on a %d row %d column board.\n", ans, M, N);
  //printf("f(M=%d, N=%d) = %d\n", M, N, ans);

}

void test()
{
  for ( int m=1; m<=8; ++m, putchar('\n') )
    for ( int n=1; n<=8; ++n ) {
      M = m;
      N = n;
      new_solve();
    }
}

int main()
{
  //test(); return 0;

  while ( scanf("%d %d", &M, &N) ) {
    if ( M==0 && N==0 )
      break;
    else
      new_solve();
  }
}
