#include <cstdio>

int  m, n;
char buf [101];
char grid[100][101];

bool read()
{
  gets(buf);
  sscanf(buf, "%d %d", &m, &n);
  if ( m==0 && n==0 ) return false;
  for ( int i=0; i<m; ++i ) gets(grid[i]);
  return true;
}

void init()
{
  for ( int i=0; i<m; ++i )
    for ( int j=0; j<n; ++j )
      if ( grid[i][j] == '.' )
	grid[i][j] = '0';
}

bool inBound(int i, int j)
{
  return i>=0 && i<m && j>=0 && j<n;
}

void sweep()
{
  static int di[8] = {-1,-1,-1, 0, 0,+1,+1,+1};
  static int dj[8] = {-1, 0,+1,-1,+1,-1, 0,+1};
  for ( int i=0; i<m; ++i ) {
    for ( int j=0; j<n; ++j ) {
      if ( grid[i][j]=='*' ) {
	for ( int k=0; k<8; ++k ) {
	  int ni = i + di[k];
	  int nj = j + dj[k];
	  if ( inBound(ni, nj) && grid[ni][nj]!='*' ) {
	    ++grid[ni][nj];
	  }
	}
      }
    }
  }
}

int main()
{
  for ( int t=1; ; ++t ) {
    if ( !read() ) break;
    init();
    sweep();
    if ( t>1 ) putchar('\n');
    printf("Field #%d:\n", t);
    for ( int i=0; i<m; ++i ) puts(grid[i]);
  }
}
