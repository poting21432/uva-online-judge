#include <cstdio>
#include <cstring>

int  rows;
int  cols;
char buf[128];
char matrix[128][128];

void read()
{
  memset(matrix, ' ', sizeof(matrix));
  rows = 0;
  cols = 0;
  while ( gets(buf) ) {
    int len = strlen(buf);
    if ( len>cols ) cols = len;
    for ( int j=0; j<len; ++j ) matrix[rows][j] = buf[j];
    ++rows;
  }
}

void print()
{
  for ( int j=0; j<cols; ++j ) {
    int end = 0;
    for ( int i=0; i<rows; ++i )
      if ( matrix[i][j] /*&& matrix[i][j]!=' '*/ )
	{ end=i; break; }
    for ( int i=rows-1; i>=end; --i ) {
      putchar(matrix[i][j]);
    }
    putchar('\n');
  }
}

int main()
{
  read();
  print();
}
