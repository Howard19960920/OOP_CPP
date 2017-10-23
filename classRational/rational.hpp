#include <iostream>
using namespace std;

class Rational {
  public:
    Rational():numer(0), denomi(1) {}
    Rational(int n, int d):numer(n), denomi(d) {}
    Rational(int wholeNumber):numer(wholeNumber), denomi(1) {}
    const int getNumerator()const{return this->numer;};
    const int getDenominator() const{return this->denomi;};
    void normalize();
    bool operator>(const Rational&) const;
    bool operator<(const Rational&) const;
    bool operator>=(const Rational&) const;
    bool operator<=(const Rational&) const;
    int operator[](const bool) const;
    friend bool operator==(const Rational&, const Rational&);
    friend istream& operator>>(istream&, Rational&);
    friend ostream& operator<<(ostream&, Rational);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);
  private:
    int numer, denomi;
};
