#include <cstdio>

int  H, W, N;
char grid[100][101];
char temp[100][101];

void read()
{
  scanf("%d %d %d", &H, &W, &N);
  for ( int x=0; x<H; ++x ) scanf("%s", grid[x]);
}

int dx[4] = {-1,+1, 0, 0};
int dy[4] = { 0, 0,-1,+1};

bool inBound(int x, int y)
{
  return x>=0 && x<H && y>=0 && y<W;
}

bool win(char a, char b)
{
  if ( a=='R' ) return b=='S';
  if ( a=='S' ) return b=='P';
  if ( a=='P' ) return b=='R';
  return false;
}

void war()
{
  for ( int x=0; x<H; ++x ) {
    for ( int y=0; y<W; ++y ) {
      temp[x][y] = -1;
      for ( int k=0; k<4; ++k ) {
	int nx = x + dx[k];
	int ny = y + dy[k];
	if ( inBound(nx, ny) && win(grid[nx][ny], grid[x][y]) ) {
	  temp[x][y] = grid[nx][ny];
	  break;
	}
      }
      if ( temp[x][y]==-1 ) temp[x][y] = grid[x][y];
    }
  }

  for ( int x=0; x<H; ++x )
    for ( int y=0; y<W; ++y )
      grid[x][y] = temp[x][y];
}

void print()
{
  for ( int x=0; x<H; ++x ) puts(grid[x]);
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    read();
    if ( t>1 ) putchar('\n');
    for ( int day=1; day<=N; ++day ) war();
    print();
  }
}
