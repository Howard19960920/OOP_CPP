#include <iostream>
#include "rational.hpp"
using namespace std;

int myGcd( int a, int b ) { return (a==0) ? b : myGcd( b%a, a ) ; }
istream& operator>>(istream& IN,  Rational &obj) {
  char slash;
  IN >> obj.numer >> slash >> obj.denomi;
  return IN;
}
ostream& operator<<(ostream& OUT, Rational obj) {
  if( obj.denomi == 0 ) {
    OUT << "Error! Devided by zero.";
    return OUT;
  }
  obj.normalize();
  if( obj.denomi == 1 )
    OUT << obj.numer;
  else
    OUT << obj.numer << "/" << obj.denomi;
  return OUT;
}
bool Rational::operator>(const Rational &obj)const {
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d > c*b )?true:false;
}
bool Rational::operator>=(const Rational &obj)const {
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d >= c*b )?true:false;
}
bool Rational::operator<(const Rational &obj)const {
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d < c*b )?true:false;
}
bool Rational::operator<=(const Rational &obj)const {
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d <= c*b )?true:false;
}
int Rational::operator[](const bool index)const {
  return index?this->denomi:this->numer;
}

void Rational::normalize() {
  if(this->denomi<0)  { this->denomi*=-1; this->numer*=-1; }
  int absNumer = (this->numer>=0)?this->numer:(-1*this->numer);
  int bcd = myGcd( absNumer, this->denomi );
  this->numer/=bcd;
  this->denomi/=bcd;
}
Rational operator*(const Rational &obj1, const Rational &obj2) {
  return Rational( obj1.numer*obj2.numer, obj1.denomi*obj2.denomi);
}
Rational operator/(const Rational &obj1, const Rational &obj2) {
  return Rational(obj1.numer*obj2.denomi, obj1.denomi*obj2.numer);
}
bool operator==(const Rational &obj1, const Rational &obj2) {
  return (((obj1.numer*obj2.denomi)==(obj1.denomi*obj2.numer)))?true:false;
}
