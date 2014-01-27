#include <cstdio>
#include <cstring>
#include <cctype>

char buf[256];
int  cnt[10];
bool pressed[10];
char finger[14][11] = {
  //234567890
  ".###..####", // c 
  ".###..###.", // d
  ".###..##..", // e
  ".###..#...", // f
  ".###......", // g
  ".##.......", // a
  ".#........", // b
  "..#.......", // C
  "####..###.", // D
  "####..##..", // E
  "####..#...", // F
  "####.....",  // G
  "###.......", // A
  "##........"  // B
};

int findNote(char ch)
{
  if      ( ch=='c' ) return 0;
  else if ( ch=='d' ) return 1;
  else if ( ch=='e' ) return 2;
  else if ( ch=='f' ) return 3;
  else if ( ch=='g' ) return 4;
  else if ( ch=='a' ) return 5;
  else if ( ch=='b' ) return 6;
  else if ( ch=='C' ) return 7;
  else if ( ch=='D' ) return 8;
  else if ( ch=='E' ) return 9;
  else if ( ch=='F' ) return 10;
  else if ( ch=='G' ) return 11;
  else if ( ch=='A' ) return 12;
  else if ( ch=='B' ) return 13;
  else                return -1;
}

int main()
{
  int T;
  gets(buf);
  sscanf(buf, "%d", &T);
  for ( int t=1; t<=T; ++t ) {
    gets(buf);
    memset(cnt, 0, sizeof(cnt));
    memset(pressed, 0, sizeof(pressed));
    for ( char *ptr=buf; *ptr; ++ptr ) {
      int note = findNote(*ptr);
      if ( note !=-1 ) {
	//printf("note[%c,id=%d] %s\n", *ptr, note, finger[note]);
	for ( int i=0; i<10; ++i ) {
	  if ( finger[note][i]=='#' ) {
	    if ( !pressed[i] ) {
	      ++cnt[i];
	      pressed[i] = true;
	    }
	  }
	  else {
	    pressed[i] = false;
	  }
	}
      }
    }
    printf("%d", cnt[0]);
    for ( int i=1; i<10; ++i ) printf(" %d", cnt[i]);
    putchar('\n');
  }
}
