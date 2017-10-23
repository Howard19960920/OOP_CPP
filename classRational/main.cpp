#include <iostream>
#include <cstdlib>
#include "rational.hpp"
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator-(const Rational&);

int main(int argc, char *argv[]) {
  int a,b,c,d;
  system("clear");
  cout << "Please input 2 fraction numbers with the instruction: " << endl << "numerator[A]: "; cin >> a;
  cout << "denominator[A]: "; cin >> b;
  while( b == 0 ) {
    cout << "The denominator should not be zero." << endl << "denominator[A]: ";
    cin >> b;
  }
  cout << "numerator[B]: "; cin >>c;
  cout << "denominator[B]: "; cin >>d;
  while( d == 0 ) {
    cout << "The denominator should not be zero." << endl << "denominator[B]: ";
    cin >> d;
  }
  cout << "Good! All the inputs are legal!" << endl
    << "Your first fraction is: " << a << "/" << b  <<", and the second one is: " << c << "/" << d <<endl
    << "**********************************************************************" << endl
    << "\t\t\t\t" <<"DEMO TIME"<<endl<<"**********************************************************************"<<endl;
  Rational obj1(a,b), obj2(c,d);
  cout << "Operator:'+': " << obj1 <<" + "<< obj2 << " = " << obj1+obj2 << endl << endl;
  cout << "Operator:'-': " << obj1 <<" - "<< obj2 << " = " << obj1-obj2 << endl << endl;
  cout << "Operator:'*': " << obj1 <<" * "<< obj2 << " = " << obj1*obj2 << endl << endl;
  cout << "Operator:'/': " << obj1 <<" / "<< obj2 << " = " << obj1/obj2 << endl << endl;
  cout << "Operator:'-': " << "-A" << " = " << -obj1 << ", " << "-B" << " = " << -obj2 << endl << endl;
  cout << "Operator:'A == B ?' ";
  if( obj1 == obj2 )
    cout << "Yes" << endl;
  else
    cout << "No\n"<< endl;

  cout << "Operator:'A > B ?' ";
  if( obj1 > obj2 )
    cout << "Yes" << endl << endl;
  else
    cout << "No"<< endl << endl;

  cout << "Operator:'A >= B ?' ";
  if( obj1 >= obj2 )
    cout << "Yes" << endl << endl;
  else
    cout << "No"<< endl << endl;

  cout << "Operator:'A < B ?' ";
  if( obj1 < obj2 )
    cout << "Yes" << endl << endl;
  else
    cout << "No"<< endl << endl;
  cout << "Operator:'A <= B ?' ";
  if( obj1 <= obj2 )
    cout << "Yes" << endl << endl;
  else
    cout << "No"<< endl << endl;
  cout << "A[0]: " << obj1[0] <<", A[1]: " << obj1[1] << ", B[0]: " << obj2[0] << ", B[1]: "<< obj2[2] << endl << endl;

  cout << "**********************************************************************" << endl << "\t\t\t\t"
    << "END"
    << endl<< "**********************************************************************" << endl;
  return 0;
}

Rational operator+(const Rational &obj1, const Rational &obj2) {
  return Rational((obj1.getNumerator()*obj2.getDenominator()+obj1.getDenominator()*obj2.getNumerator()),\
      obj1.getDenominator()*obj2.getDenominator());
}

Rational operator-(const Rational &obj1, const Rational &obj2) {
  return Rational((obj1.getNumerator()*obj2.getDenominator()-obj1.getDenominator()*obj2.getNumerator()),\
      obj1.getDenominator()*obj2.getDenominator());
}

Rational operator-(const Rational &obj) {
  return Rational(-1*obj.getNumerator(), obj.getDenominator());
}
