#include <cstdio>
#include <cctype>

const char ATTACKED = '@';

char buf[256];
char board[8][9] = {
  "--------",
  "--------",
  "--------",
  "--------",
  "--------",
  "--------",
  "--------",
  "--------"
};

void makeBoard()
{
  char *ptr;
  int i, j;
  i = 0;
  j = 0;
  for ( ptr=buf; *ptr; ++ptr ) {
    //printf("[i=%d][j=%d][ch=%c]\n", i, j, *ptr);
    if ( isdigit(*ptr) ) {
      int count = *ptr-'0';
      //printf("[count=%d]", count);
      while ( count-- ) {
	board[i][j++] = '-';
      }
    }
    else if ( *ptr=='/' ) ++i, j=0;
    else board[i][j++] = *ptr;
  }
}

void printBoard()
{
  for ( int i=0; i<8; ++i ) puts(board[i]);
  putchar('\n');
}

int countSquares()
{
  int count = 0;
  for ( int i=0; i<8; ++i )
    for ( int j=0; j<8; ++j )
      if ( board[i][j]=='-' )
	++count;
  return count;
}

bool inBound(int i, int j)
{
  return i>=0 && i<8 && j>=0 && j<8;
}

void attackPawn(int i, int j)
{
  if ( inBound(i-1, j-1) && !isalpha(board[i-1][j-1]) ) board[i-1][j-1]=ATTACKED;
  if ( inBound(i-1, j+1) && !isalpha(board[i-1][j+1]) ) board[i-1][j+1]=ATTACKED;
}

void attackpawn(int i, int j)
{
  if ( inBound(i+1, j-1) && !isalpha(board[i+1][j-1]) ) board[i+1][j-1]=ATTACKED;
  if ( inBound(i+1, j+1) && !isalpha(board[i+1][j+1]) ) board[i+1][j+1]=ATTACKED;
}


void attackLine(int i, int j, int dir, int moves)
{
  static int di[8] = {-1,-1,-1, 0, 0,+1,+1,+1};
  static int dj[8] = {-1, 0,+1,-1,+1,-1, 0,+1};
  int ni=i, nj=j;
  while ( moves-- ) {
    ni += di[dir];
    nj += dj[dir];
    if ( !inBound(ni,nj) || isalpha(board[ni][nj]) )
      break;
    else
      board[ni][nj] = ATTACKED;
  }
}

void attackKnight(int i, int j)
{
  static int ki[8] = {-2,-2,-1,-1,+1,+1,+2,+2};
  static int kj[8] = {-1,+1,-2,+2,-2,+2,-1,+1};
  for ( int k=0; k<8; ++k ) {
    int ni = i + ki[k];
    int nj = j + kj[k];
    if ( inBound(ni, nj) && !isalpha(board[ni][nj]) )
      board[ni][nj] = ATTACKED;
  }
}

void attackBishop(int i, int j)
{
  attackLine(i, j, 0, 7);
  attackLine(i, j, 2, 7);
  attackLine(i, j, 5, 7);
  attackLine(i, j, 7, 7);
}

void attackRook(int i, int j)
{
  attackLine(i, j, 1, 7);
  attackLine(i, j, 3, 7);
  attackLine(i, j, 4, 7);
  attackLine(i, j, 6, 7);
}

void attackQueen(int i, int j)
{
  attackLine(i, j, 0, 7);
  attackLine(i, j, 1, 7);
  attackLine(i, j, 2, 7);
  attackLine(i, j, 3, 7);
  attackLine(i, j, 4, 7);
  attackLine(i, j, 5, 7);
  attackLine(i, j, 6, 7);
  attackLine(i, j, 7, 7);
}

void attackKing(int i, int j)
{
  attackLine(i, j, 0, 1);
  attackLine(i, j, 1, 1);
  attackLine(i, j, 2, 1);
  attackLine(i, j, 3, 1);
  attackLine(i, j, 4, 1);
  attackLine(i, j, 5, 1);
  attackLine(i, j, 6, 1);
  attackLine(i, j, 7, 1);
}

void attack()
{
  for ( int i=0; i<8; ++i ) {
    for ( int j=0; j<8; ++j ) {
      if ( isalpha(board[i][j]) ) {
	char ch = toupper(board[i][j]);
	if      ( board[i][j]=='P' ) attackPawn(i, j);
	else if ( board[i][j]=='p' ) attackpawn(i, j);
	else if ( ch=='N' ) attackKnight(i, j);
	else if ( ch=='B' ) attackBishop(i, j);
	else if ( ch=='R' ) attackRook  (i, j);
	else if ( ch=='Q' ) attackQueen (i, j);
	else if ( ch=='K' ) attackKing  (i, j);
      }
    }
  }
}

int main()
{
  while ( gets(buf) ) {
    makeBoard();
    attack();
    //printBoard();
    printf("%d\n", countSquares());
  }
}
