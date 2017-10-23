#include <iostream>
#include <cstdlib>
using namespace std;
class Rational {
 public:
   Rational():numer(0), denomi(1) {} // PRE: Default constructor, POS: Create anonymous class obj;
   Rational(int n, int d):numer(n), denomi(d) {} // PRE: constructor, take 2 integer as n&d, POS:Create anonymous obj
   Rational(int wholeNumber):numer(wholeNumber), denomi(1) {} //PRE:constructor, take numer, POS:Create anonymous obj
   const int getNumerator()const{return this->numer;}; //PRE:Take no input, POS:Return numerator
   const int getDenominator() const{return this->denomi;};//PRE:Take no input, POS:Return denominator
   void normalize(); // PRE:Do the fraction normalization, POS: return nothing
   bool operator>(const Rational&) const; //PRE:Passing one class obj, POS: return a bool compare A>B
   bool operator<(const Rational&) const; //PRE:Passing one class obj, POS: return a bool compare A<B
   bool operator>=(const Rational&) const;//PRE:Passing one class obj, POS: return a bool compare A>=B
   bool operator<=(const Rational&) const;//PRE:Passing one class obj, POS: return a bool compare A<=B
   int operator[](const bool) const;//PRE:Passing a bool as index, POS:return numer(0) or denomi(1)
   friend bool operator==(const Rational&, const Rational&);//PRE:Input 2 class obj, POS:return a bool compare A==B
   friend istream& operator>>(istream&, Rational&);//PRE:Input istream& and class Rational&, POS:return istream&
   friend ostream& operator<<(ostream&, Rational);//PRE:Input ostream& and class Rational, POS:return ostream&
   friend Rational operator*(const Rational&, const Rational&);//PRE:Input 2 obj, POS:Create anonymous class obj A*B
   friend Rational operator/(const Rational&, const Rational&);//PRE:Input 2 obj, POS:Create anonymous class obj A/B
 private:
   int numer, denomi;
};
Rational operator+(const Rational&, const Rational&);//PRE:Input 2 class obj, POS:Create anonymous class obj A+B
Rational operator-(const Rational&, const Rational&);//PRE:Input 2 class obj, POS:Create anonymous class obj A-B
Rational operator-(const Rational&);//PRE:Input 1 class obj, POS:Create anonymous class obj -A
void demo() {
  int a, b, c, d;
  system("clear");
  cout << "Please input 2 fraction numbers A&B by following the instructions." << endl << "A[Numerator]: "; cin >> a;
  cout << "A[Denominator]: "; cin >> b;
  while( b==0 )  {
    cout << "Error! Devided by zero." << endl << "A[Denominator]: "; cin >> b;
  }
  cout << "B[Numerator]: " ; cin >> c;
  cout << "B[Denominator]: "; cin >> d;
  while( d==0 )  {
    cout << "Error! Devided by zero." << endl << "B[Denominator]: "; cin >> d;
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
    cout << "Yes\n" << endl;
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
}
int main(int argc, char *argv[]) {
  demo();
  return 0;
}


istream& operator>>(istream& IN,  Rational &obj) { //friend
  char slash;
  IN >> obj.numer >> slash >> obj.denomi;
  return IN;
}
ostream& operator<<(ostream& OUT, Rational obj) { //friend
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
bool Rational::operator>(const Rational &obj)const { //member
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d > c*b )?true:false;
}
bool Rational::operator>=(const Rational &obj)const { //member
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d >= c*b )?true:false;
}
bool Rational::operator<(const Rational &obj)const { //member
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d < c*b )?true:false;
}
bool Rational::operator<=(const Rational &obj)const { //member
  int a = this->numer, b = this->denomi, c = obj.numer, d = obj.denomi;
  if( b<0 ){ b*=-1; a*=-1; }
  if( d<0 ){ c*=-1; c*=-1; }
  return ( a*d <= c*b )?true:false;
}
int Rational::operator[](const bool index)const { //member
  return index? this->denomi : this->numer;
}
int myGcd( int a, int b ) { // non-member
  return (a==0) ? b : myGcd(b%a, a);
}
void Rational::normalize() { //member
  if(this->denomi<0)  { this->denomi*=-1; this->numer*=-1; }
  int absNumer = (this->numer>=0)?this->numer:(-1*this->numer);
  int bcd = myGcd( absNumer, this->denomi );
  this->numer/=bcd;
  this->denomi/=bcd;
}
Rational operator*(const Rational &obj1, const Rational &obj2) { //friend
  return Rational( obj1.numer*obj2.numer, obj1.denomi*obj2.denomi);
}
Rational operator/(const Rational &obj1, const Rational &obj2) {  //friend
  return Rational(obj1.numer*obj2.denomi, obj1.denomi*obj2.numer);
}
bool operator==(const Rational &obj1, const Rational &obj2) { //friend
  return (((obj1.numer*obj2.denomi)==(obj1.denomi*obj2.numer)))?true:false;
}
Rational operator+(const Rational &obj1, const Rational &obj2) { //non-member
  return Rational((obj1.getNumerator()*obj2.getDenominator()+obj1.getDenominator()*obj2.getNumerator()),\
      obj1.getDenominator()*obj2.getDenominator());
}
Rational operator-(const Rational &obj1, const Rational &obj2) { //non-member
  return Rational((obj1.getNumerator()*obj2.getDenominator()-obj1.getDenominator()*obj2.getNumerator()),\
      obj1.getDenominator()*obj2.getDenominator());
}
Rational operator-(const Rational &obj) { //non-member
  return Rational(-1*obj.getNumerator(), obj.getDenominator());
}
