#include <cstdio>

void printAnswer(int n)
{
  if ( n==1 ) puts("1 month");
  else        printf("%d months\n", n);
}

int main()
{
  int N;
  double down;
  double loan;
  int    m;
  double rate[101];
  while ( ~scanf("%d %lf %lf %d", &N, &down, &loan, &m) ) {
    if ( N<0 ) break;
    for ( int i=0; i<=N; ++i ) rate[i] = -1.0;
    for ( int i=0; i<m; ++i ) {
      int x;
      double r;
      scanf("%d %lf", &x, &r);
      rate[x] = 1.0-r;
    }
    double current_rate = 1.0;
    for ( int i=0; i<=N; ++i ) {
      if ( rate[i]==-1.0 ) rate[i] = current_rate;
      else                 current_rate = rate[i];
    }

    double car_value  = (down+loan) * rate[0];
    double money_owed = loan;
    double money_paied_each_month = loan / N;

    if ( money_owed < car_value ) {
      puts("0 months");
    }
    else {
      //printf("Initial car_value = %.5f, money_owed = %.5f\n", car_value, money_owed);
      for ( int month=1; month<=N; ++month ) {
	car_value *= rate[month];
	money_owed -= money_paied_each_month;
	//printf("At the end of month[%d], car_value = %.5f, money_owed = %.5f\n", month, car_value, money_owed);
	if ( money_owed <= car_value ) {
	  printAnswer(month);
	  break;
	}
      }
    }
    
  }
}
