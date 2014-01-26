#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

const int MAX_MONEY = 10000;

int coin_value[6] = {5, 10, 20, 50, 100, 200};
int coin_count[6] = {0, 0, 0, 0, 0, 0};
vector<int> coins;
int money;
int f[MAX_MONEY+1];

bool read()
{
  bool all_zeros = true;
  for ( int i=0; i<6; ++i ) {
    scanf("%d", &coin_count[i]);
    if ( coin_count[i] != 0 )
      all_zeros = false;
  }
  if ( all_zeros )
    return false;
  else {
    double m;
    scanf("%lf", &m);
    money = (int)(m*100);
    return true;
  }
}

void solve()
{
  coins.clear();
  for ( int i=0; i<6; ++i )
    for ( int j=0; j<coin_count[i]; ++j )
      coins.push_back( coin_value[i] );

  printf("money = %d\n", money);
  printf("coins.size() = %zd\n", coins.size());
  for ( int i=0; i<coins.size(); ++i ) printf("%d ", coins[i]);
  putchar('\n');

  for ( int j=1; j<=money; ++j ) f[j] = INT_MAX/2;
  f[0] = 0;
  for ( int i=0; i<coins.size(); ++i ) {
    for ( int j=money; j>=coins[i]; --j ) {
      f[j] = min(f[j], f[j-coins[i]]+1);
    }
  }
  printf("%d\n", f[money]);
}

int main()
{
  while ( read() )
    solve();
}
