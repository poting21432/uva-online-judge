#include <cstdio>
#include <cctype>

const char suits[4][9] = {
  "Clubs",
  "Diamonds",
  "Hearts",
  "Spades"
};

const char values[13][6] = {
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "Jack",
  "Queen",
  "King",
  "Ace"
};

void printCard(int n)
{
  int i = n / 13;
  int j = n % 13;
  printf("%s of %s\n", values[j], suits[i]);
}

int main()
{
  int T;
  int shuffle[100][52];
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    int n;
    scanf("%d", &n);
    for ( int i=0; i<n; ++i ) {
      for ( int j=0; j<52; ++j ) {
	scanf("%d", &shuffle[i][j]);
	--shuffle[i][j];
      }
    }
    getchar();
    int card[52];
    for ( int i=0; i<52; ++i ) card[i] = i;
    bool finished = false;
    char buf[32];
    while ( true ) {
      if ( gets(buf)==NULL )
	break;
      int s;
      if ( sscanf(buf, "%d", &s)==EOF )
	break;
      //printf("Shuffle[%d]\n", s);
      --s;
      int new_card[52];
      for ( int i=0; i<52; ++i ) {
	new_card[i] = card[shuffle[s][i]];
	//new_card[shuffle[s][i]] = card[i];
      }
      for ( int i=0; i<52; ++i ) {
	//printf("%d --> %d\n", card[i], new_card[i]);
	card[i] = new_card[i];
      }
    }
    if ( t>1 ) putchar('\n');
    for ( int i=0; i<52; ++i ) printCard(card[i]);
  }
}
