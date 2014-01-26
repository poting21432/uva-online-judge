#include <cstdio>
#include <cstdlib>
#include <ctime>

void gen()
{
  char blood[4][4] = {"A", "B", "AB", "O"};
  char rh[2][2] = {"+", "-"};
  printf("%s%s ", blood[rand()%4], rh[rand()%2]);
}

int main()
{
  srand(time(0));
  for ( int i=0; i<100000; ++i ) {
    int q = rand()%3;
    if ( q==0 ) {
      gen();
      gen();
      printf("? ");
    }
    else if ( q==1 ) {
      gen();
      printf("? ");
      gen();
    }
    else {
      printf("? ");
      gen();
      gen();
    }
    putchar('\n');
  }
  puts("E N D");
}
