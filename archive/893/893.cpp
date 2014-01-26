#include <cstdio>

bool isLeapYear(int y)
{
  if      ( y%400==0 ) return true;
  else if ( y%100==0 ) return false;
  else if ( y%4  ==0 ) return true;
  else                 return false;
}

int daysInMonth(int m, int y)
{
  if ( m==2 ) {
    if ( isLeapYear(y) ) return 29;
    else                 return 28;
  }
  else if ( m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ) {
    return 31;
  }
  else {
    return 30;
  }
}

int main()
{
  int offset, day, month, year;
  while ( ~scanf("%d %d %d %d", &offset, &day, &month, &year) ) {
    if ( offset==0 && day==0 && month==0 && year==0 )
      break;
    else {
      while ( offset != 0 ) {
	int days_this_year  = isLeapYear(year)?366:365;
	int days_this_month = daysInMonth(month, year);
	if ( offset >= days_this_year && !isLeapYear(year) && !isLeapYear(year+1) ) {
	  // goto next year
	  ++year; offset -= days_this_year;
	}
	else if ( offset >= days_this_month ) {
	  // goto next month
	  ++month; offset -= days_this_month;
	  if ( month>12 ) { ++year; month=1; }

	  int new_days_this_month = daysInMonth(month, year);
	  if ( day > new_days_this_month ) {
	    ++month;
	    day -= new_days_this_month;
	    if ( month>12 ) { ++year; month=1; }
	  }
	}
	else {
	  // goto next day
	  ++day; --offset;
	  if ( day>days_this_month ) { ++month; day=1; }
	  if ( month>12 ) { ++year; month=1; }
	}
      }
      printf("%d %d %d\n", day, month, year);
    }
  }
}
