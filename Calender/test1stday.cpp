/*
 *系級：資訊工程學系二年級
 *姓名：宋慶澔
 *學號：4044-100-16
 *年級：108級
*/
#include <iostream>
#include <string>
using namespace std;
void test1stday ( int year, int month, int &firstDay );
  /*Preconditions:
   * year and month are the user inputs which is the month that the users want to look up.
   * firstDay and numOfday represent the first day and the total day count of that month respectively.
   *PostConditions:
   * function returns nothing, but thru the method of call-by-refference, we can change the value of int firstDay and int numOfday directly.
   */
int main()  {

  int year, month, firstDay ;
  char ans;
  const string monthOfYear[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  const string weekDay[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
  do {
    cout<< "Input a year and a month, the program will output the first weekday of the corresponded month." << endl
        << "~$:";
    cin >> year >> month;
    test1stday( year, month, firstDay );
  	cout << "The first weekday of " << monthOfYear[month-1] << " " << year << " is " << weekDay[ firstDay] << endl;
  	cout << "Continue testing (y/n) ?" << endl;
  	cin >> ans;
  }
  while( ans == 'y' || ans == 'Y');

  return 0;
}

void test1stday( int year, int month, int &firstDay ) {

  bool isLeap = (year % 400 == 0 ) ||  ((year % 4 == 0) && (year % 100 != 0));
  int dayOfmonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  dayOfmonth[1] += isLeap;
  int dayCnt = 1, i;
  for( i=0; i < month-1 ; i++ )
    dayCnt += dayOfmonth[ i ];

  year -= 1;
  dayCnt += (year + (year/4) - (year/100) + (year/400) );
  firstDay = dayCnt % 7;
  return;

}

