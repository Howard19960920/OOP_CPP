#include <bits/stdc++.h>
using namespace std;

namespace ClassBigInt {

  class bigInt  {
   public:
     /**********************CONSTRUCTORS***********************/
     bigInt(void);
     bigInt(long long);
     bigInt(string);
     /*************************BIG THREE***********************/
     bigInt(const bigInt &);
     ~bigInt();
     bigInt& operator = (const bigInt&);
     void regularization(void);
     /*********************FRIEND FUNCTIONS********************/
     friend ostream& operator << (ostream&, const bigInt&);
     friend istream& operator >> (istream&, bigInt&);
     friend bool     operator >  (const bigInt&, const bigInt&);
     friend bool     operator <  (const bigInt&, const bigInt&);
     friend bool     operator >= (const bigInt&, const bigInt&);
     friend bool     operator <= (const bigInt&, const bigInt&);
     friend bool     operator == (const bigInt&, const bigInt&);
     friend bool     operator != (const bigInt&, const bigInt&);
     friend bigInt & operator -  (const bigInt&);
     friend bigInt & operator %  (const bigInt&, const bigInt&);
     friend bigInt & operator +  (const bigInt&, const bigInt&);
     friend bigInt & operator -  (const bigInt&, const bigInt&);
     friend bigInt & operator *  (const bigInt&, const bigInt&);
     friend bigInt & operator /  (const bigInt&, const bigInt&);
     /*********************************************************/
   private:
     vector<int> num;
     bool sign;
  };

  bigInt& getFactorial(const bigInt&);
  bigInt getGcd(bigInt, bigInt);
}
