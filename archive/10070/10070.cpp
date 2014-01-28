#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool lessThan(const string &a, const string &b)
{
  if ( a.length() != b.length() ) return a.length() < b.length();
  else {
    for ( int i=0; i<a.length(); ++i )
      if ( a[i] != b[i] )
	return a[i] < b[i];
    return false;
  }
}

bool isMultipleOf(const string &y, const int n)
{
  int L = y.length();
  if ( n==3 ) {
    int sum = 0;
    for ( int i=0; i<L; ++i ) sum += y[i]-'0';
    return sum % 3 == 0;
  }
  else if ( n==5 ) {
    return y[L-1]=='0' || y[L-1]=='5';
  }
  else if ( n==4 ) {
    if ( L<=2 ) return atoi(y.c_str()) % 4 == 0;
    else        return isMultipleOf(y.substr(L-2), 4);
  }
  else if ( n==11 ) {
    int sum[2] = {0, 0};
    for ( int i=0; i<L; ++i ) {
      sum[i%2] += y[i]-'0';
    }
    return abs(sum[0]-sum[1]) % 11 == 0;
  }
  else if ( n==100 ) {
    return L>=3 && y.substr(L-2)=="00";
  }
  else if ( n==400 ) {
    return !lessThan(y,"400") && isMultipleOf(y,100) && isMultipleOf(y.substr(0,L-2),4);
  }
  else if ( n==15 ) {
    return !lessThan(y,"15") && isMultipleOf(y,3) && isMultipleOf(y,5);
  }
  else if ( n==55 ) {
    return !lessThan(y, "55") && isMultipleOf(y,5) && isMultipleOf(y,11);
  }
  return false;
}

bool isLeapYear(const string &y)
{
  if ( isMultipleOf(y, 400) ) return true;
  if ( isMultipleOf(y, 100) ) return false;
  if ( isMultipleOf(y, 4  ) ) return true;
  return false;
}

bool isHuluculuYear(const string &y)
{
  return isMultipleOf(y, 15);
}

bool isBulukuluYear(const string &y)
{
  return isMultipleOf(y, 55) && isLeapYear(y);
}

bool isOrdinaryYear(const string &y)
{
  return !isLeapYear(y) && !isHuluculuYear(y) && !isBulukuluYear(y);
}

void test()
{
  string str[10] = {"1", "12", "30", "55", "128", "200", "400", "495", "1000", "1100"};
  int div[8] = {3, 4, 5, 11, 100, 400, 15, 55};
  for ( int i=0; i<10; ++i ) {
    for ( int j=0; j<8; ++j ) {
      printf("isMultipleOf(%s, %d) = %d\n", str[i].c_str(), div[j], isMultipleOf(str[i], div[j]));
    }
  }
}

int main()
{
  //test();

  string y;
  bool first_case = true;
  while ( cin >> y ) {
    if ( first_case ) first_case = false;
    else putchar('\n');

    if ( isLeapYear(y) )
      puts("This is leap year.");
    if ( isHuluculuYear(y) )
      puts("This is huluculu festival year.");
    if ( isBulukuluYear(y) )
      puts("This is bulukulu festival year.");
    if ( isOrdinaryYear(y) )
      puts("This is an ordinary year.");
  }
}
