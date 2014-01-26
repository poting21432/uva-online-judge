#include <cstdio>
#include <cstring>

int  value[8][8];
bool queen[8][8];
bool row[8];
bool col[8];
bool diag1[15];
bool diag2[15];
int  queen_count;

int max_score = 0;

void read()
{
  for ( int i=0; i<8; ++i )
    for ( int j=0; j<8; ++j )
      scanf("%d", &value[i][j]);
}

void printBoard()
{
  for ( int i=0; i<8; ++i ) {
    for ( int j=0; j<8; ++j ) {
      if ( queen[i][j] ) putchar('Q');
      else               putchar('-');
    }
    putchar('\n');
  }
  putchar('\n');
}

bool ok(int i, int j)
{
  int d1 = i-j+7;
  int d2 = i+j;
  return !queen[i][j] && !row[i] && !col[j] && !diag1[d1] && !diag2[d2];
}

void place(int i, int j)
{
  queen[i][j] = true;
  row[i] = true;
  col[j] = true;
  int d1 = i-j+7;
  int d2 = i+j;
  diag1[d1] = true;
  diag2[d2] = true;
  ++queen_count;
}

void remove(int i, int j)
{
  queen[i][j] = false;
  row[i] = false;
  col[j] = false;
  int d1 = i-j+7;
  int d2 = i+j;
  diag1[d1] = false;
  diag2[d2] = false;
  --queen_count;
}

int getScore()
{
  int score = 0;
  for ( int i=0; i<8; ++i )
    for ( int j=0; j<8; ++j )
      if ( queen[i][j] )
	score += value[i][j];
  return score;
}

void search(int i, int j)
{
  if ( i==8 ) {
    // done
    if ( queen_count==8 ) {
      int score = getScore();
      if ( score > max_score ) {
	max_score = score;
	//printf("score = %d\n", score);
	//printBoard();
      }
    }
  }
  else if ( j==8 ) {
    search(i+1, 0);
  }
  else {
    if ( ok(i,j) ) {
      place (i, j  );
      search(i, j+1);
      remove(i, j  );
    }
    search(i, j+1);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    read();
    max_score = 0;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));
    queen_count = 0;
    search(0,0);
    printf("%5d\n", max_score);
  }
}
