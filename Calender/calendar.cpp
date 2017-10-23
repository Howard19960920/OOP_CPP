/*
 *  CCU CISE 2nd Grader
 *  4044-100-16
 *  Howard, Sung
 *  OOP first assignment - calender.
 */
#include <iostream>
#include <string>
using namespace std;
bool inputYrMn( int &year, int &month );
/*Preconditions:
 * year and month are the user inputs which is the month that users want to look up.
 *Postconditions:
 * return true if inputs are valid, and false on the other way round.
 */
void get1stDayOfMonth( int year, int month, int &firstDay, int &numOfDay );
/*Preconditions:
 * year and month are the user inputs which is the month that the users want to look up.
 * firstDay and numOfday represent the first day and the total day count of that month respectively.
 *PostConditions:
 * function returns nothing, but thru the method of call-by-refference, we can change the value of int firstDay and int numOfday directly.
 */
void showCalendar( int year, int month, int firstDay, int numOfDay );
/*Preconditions:
 * year and month are the user inputs which users want to look up.
 * firstDay and the numOfday hold the values of the first day and the total day count of that month respectively.
 *Postconditions:
 * function reuturns nothing, but will print out the corresponded calendar to the input year and month.
 */
int main()  {

  int year, month, firstDay, numOfDay;
  char ans;
  cout<<"*************************************EFFECTS************************************"<< endl << endl
    << "Input a year and a month, the program will print out the corresponed calendar." << endl << endl
    << "**************************************RULES*************************************" << endl << endl
    << "1. Year should be an integer in range of 1901 ~ 2099." << endl
    << "2. Month should be an integer in range of 1 ~ 12." << endl
    << "3. The program will transform your inputs as type of integers anyway."<< endl << endl
    << "********************************************************************************"<< endl;

  do {
    cout << "~$:";
    cin >> year >> month;
    if( !inputYrMn( year, month ) ) {
      cout << "Invalid input. Please try again." << endl;

    }
    else  {

      get1stDayOfMonth( year, month, firstDay, numOfDay );
      showCalendar( year, month, firstDay, numOfDay );
    }
    cout << "continue (y/n) ?" << endl;
    cin >> ans;

  } while( ans =='y' || ans =='Y' );

  return 0;
}

bool inputYrMn( int &year, int &month ) {

  return (year >= 1901 && year <= 2099) ? (( month >= 1 && month <= 12 )? 1 : 0 ) : 0;
}

void get1stDayOfMonth( int year, int month, int &firstDay, int &numOfDay )  {

  bool isLeap = (year % 400 == 0 ) ||  ((year % 4 == 0) && (year % 100 != 0));
  int dayOfmonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  dayOfmonth[1] += isLeap;
  numOfDay = dayOfmonth[ month-1 ];
  int dayCnt = 1, i;
  for( i=0; i < month-1 ; i++ )
    dayCnt += dayOfmonth[ i ];

  year -= 1;
  dayCnt += (year + (year/4) - (year/100) + (year/400) );
  firstDay = dayCnt % 7;
  return;
}

void showCalendar( int year, int month, int firstDay, int numOfDay )  {

  int i, date = 1;
  const string monthOfYear[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  cout  << "----------------------------------------------------" << endl
    << "\t\t     " << year << " " << monthOfYear[ month-1 ] << endl
    << "----------------------------------------------------" << endl;
  cout << "SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT" << endl ;
  for ( i = 0 ,date = 1 ; date <= numOfDay; i ++, date ++  ) {

    for( ; i < firstDay; i++ ) {
      cout << " \t";
    }

    if ( i % 7 == 0 )
      cout << endl;

    cout << date << "\t";
  }
  cout<< endl
    << "----------------------------------------------------" << endl;
  return;
}
