/* Code by Howard Sung, CCU CSIE 2nd grader
 * Thursday, June, 8th, 2017              */

#include <bits/stdc++.h>
#include "ClassBigInt.h"
using namespace std;

namespace ClassBigInt  {
  /* Default Constructor */
  bigInt::bigInt(void)  {
    this->sign = true;
    this->num.push_back(0);
  }

  /* Construct by long long */
  bigInt::bigInt(long long ini) {
    this->sign = (ini >= 0) ? true : false;
    ini = (ini >= 0) ? ini : (-ini);
    if(ini == 0)
      this->num.push_back(0);
    else
      while(ini)  {
        this->num.push_back(ini%10);
        ini /= 10;
      }
  }

  /* Construct by string */
  bigInt::bigInt(string ini)  {
    this->sign = (ini[0] == '-') ? false : true;
    int rbnd = (ini[0] == '-') ? 1 : 0; /* reverse bound*/
    for( int i = (ini.length()-1); i>= rbnd; i--)
      this->num.push_back((ini[i]-'0'));
    this->regularization();
  }

  /* Destructor, vector<int>().swap(this->num) will swap the vector with a null vector with no memory allocation */
  bigInt::~bigInt() {
    this->num.clear();
    vector<int>().swap(this->num);
  }

  /* Copy Constructor */
  bigInt::bigInt(const bigInt &src)  {
    this->sign = src.sign;
    this->num = src.num;
  }

  /* Assignment Operator Overloaded*/
  bigInt& bigInt::operator = (const bigInt& src)  {
    if( this == &src )
      return *this;
    this->sign = src.sign;
    this->num  = src.num;
    return *this;
  }

  /************REGULARIZATION*************/
  void bigInt::regularization(void)  {

    while(this->num.back() == 0 && this->num.size()>1)
      this->num.pop_back();
    if(this->num.size() == 1 && this->num.front() == 0)
      this->sign = true;
  }

  /* Ostream Operator Overloaded */
  ostream& operator << (ostream &os, const bigInt &src)  {
    /************STANDARD OUT**************/
    if(!src.sign) os << "-";
    for(int i = (src.num.size()-1); i>=0; i--)
      os << src.num.at(i);
    return os;
  }

  /* Istream Operator Overloaded */
  istream& operator >> (istream &is, bigInt &src) {
    /************STANDARD IN***************/
    long long val;
    is >> val;
    src = bigInt(val);
    return is;
  }

  /* GT Operator Overloaded */
  bool operator > (const bigInt& s1, const bigInt& s2)  {
    if(s1.sign != s2.sign) /*if the signs are different*/
      return s1.sign ? true : false;
    if(s1.num.size() != s2.num.size())  /*if the signs are the same and the length are different*/
      return (s1.sign) ? ((s1.num.size() > s2.num.size()) ? true : false) : ((s1.num.size() < s2.num.size()) ? true : false);
    for( int i = (s1.num.size()-1); i>=0; i--)  {  /* if both the size and sign are the same */
      if(s1.num.at(i) != s2.num.at(i))
        return (s1.sign) ? ((s1.num.at(i) > s2.num.at(i)) ? true : false) : ((s1.num.at(i) < s2.num.at(i)) ? true : false);
    }
    return false;
  }

  /* LT Operator Overloaded */
  bool operator < (const bigInt& s1, const bigInt &s2)  {
    if(s1.sign != s2.sign) /*if the signs are different*/
      return s1.sign ? false : true;
    if(s1.num.size() != s2.num.size())  /*if the signs are the same and the length are different*/
      return (s1.sign) ? ((s1.num.size() > s2.num.size()) ? false : true) : ((s1.num.size() < s2.num.size()) ? false : true);
    for( int i = (s1.num.size()-1); i>=0; i--)  {  /* if both the size and sign are the same */
      if(s1.num.at(i) != s2.num.at(i))
        return (s1.sign) ? ((s1.num.at(i) > s2.num.at(i)) ? false : true) : ((s1.num.at(i) < s2.num.at(i)) ? false : true);
    }
    return false;
  }

  /* GE Operator Overloaded */
  bool operator >= (const bigInt& s1, const bigInt& s2) {
    return (s1 < s2) ? false : true;
  }

  /* LE Operator Overloaded */
  bool operator <= (const bigInt& s1, const bigInt& s2) {
    return (s1 > s2) ? false : true;
  }

  /* Equal Operator Overloaded */
  bool operator == (const bigInt& s1, const bigInt& s2) {
    return (s1 >= s2 && s1 <= s2) ? true : false;
  }

  /* Not Equal Operator Overloaded */
  bool operator != (const bigInt& s1, const bigInt& s2) {
    return (s1 == s2) ? false : true;
  }

  /* Negative Sign Operator Overloaded */
  bigInt& operator - (const bigInt& s1) {
    bigInt *reval = new bigInt(s1);
    reval->sign = reval->sign ? false : true;
    reval->regularization();
    return *reval;
  }

  /* Mod Operator Overloaded */
  bigInt& operator % (const bigInt &s1, const bigInt &s2) {
    bigInt *reval = new bigInt, lval(s1), rval(s2), temp;
    const bool tempSign = (lval.sign == rval.sign) ? true : false;
    lval.sign = rval.sign = true;
    temp = lval/rval;
    *reval = (lval - (temp * rval));
    reval->sign = tempSign;
    reval->regularization();
    return *reval;
  }

  /* Addition Operator Overloaded */
  bigInt& operator + (const bigInt &s1, const bigInt &s2 )  { /*Only deal with the case of the same sign, or it is actually substraction.*/
    if(s1.sign == s2.sign)  {
      int carry(0);
      bigInt *reval = new bigInt, utemp, ltemp; /*utemp and ltemp are local variables available only in this if scope*/
      reval->num.pop_back();
      reval->sign = s1.sign; /* || s2.sign*/
      utemp = (s1.num.size() >= s2.num.size()) ? s1 : s2; /* upper temp has longer vector than lower temp */
      ltemp = (s1.num.size() <  s2.num.size())? s1 : s2;
      for(unsigned int i = 0; i < ltemp.num.size(); i++) {
        reval->num.push_back(((utemp.num.at(i) + ltemp.num.at(i) + carry )%10));
        carry = (utemp.num.at(i) + ltemp.num.at(i) + carry)/10;
      }
      for(unsigned int i = ltemp.num.size(); i < utemp.num.size(); i++)  {
        reval->num.push_back((utemp.num.at(i) + carry)%10);
        carry = (utemp.num.at(i) + carry)/10;
      }
      if(carry > 0)
        reval->num.push_back(carry);
      reval->regularization();
      return *reval;
    }
    else  { // View the addition of two different sign numbers as an act of substraction.
      bigInt utemp, ltemp;
      utemp = s1.sign ? s1 : s2;
      ltemp = s2.sign ? s1 : s2;
      ltemp.sign = true;
      bigInt *reval = new bigInt(utemp - ltemp);
      reval->regularization();
      return *reval;
    }
  }

  /* Substraction Operator Overloaded */
  bigInt& operator -  (const bigInt &s1, const bigInt &s2)  {
    if(s1.sign == s2.sign)  {
      int borrow(0);
      bigInt *reval = new bigInt, utemp, ltemp;
      reval->num.pop_back();
      if(s1.num.size() != s2.num.size())  {
        utemp = (s1.num.size() > s2.num.size()) ? s1 : s2;
        ltemp = (s1.num.size() < s2.num.size()) ? s1 : s2;
        reval->sign = (s1 == utemp) ? s1.sign : (!s1.sign);
      }
      else  { /* if the length of vector are the same */
        utemp = (s1.sign) ? ((s1 >= s2) ? s1 : s2) : ((s1 < s2) ? s1 : s2);
        ltemp = (s1.sign) ? ((s1 < s2) ? s1 : s2) : ((s1 > s2) ? s1 : s2);
        reval->sign = ((s1.sign) ? ((utemp == s1) ? s1.sign : (!s1.sign)) : ((utemp == s2) ? s1.sign : (!s1.sign)));
      }
      for(unsigned int i = 0; i < ltemp.num.size(); i++) {
        if((utemp.num.at(i) - ltemp.num.at(i) - borrow) >= 0) {
          reval->num.push_back(utemp.num.at(i) - ltemp.num.at(i) - borrow);
          borrow = 0;
        }
        else  {
          reval->num.push_back(10 + utemp.num.at(i) - ltemp.num.at(i) - borrow);
          borrow = 1;
        }
      }
      for(unsigned int i = ltemp.num.size(); i < utemp.num.size(); i++)  {
        if((utemp.num.at(i) - borrow) >= 0) {
          reval->num.push_back(utemp.num.at(i) - borrow);
          borrow = 0;
        }
        else  {
          reval->num.push_back(10 + utemp.num.at(i) - borrow);
          borrow = 1;
        }
      }
      reval->regularization();
      return *reval;
    }
    else  { /* Substraction of two different signs numbers can be viewed as addition */
      bigInt *reval = new bigInt, utemp = s1, ltemp = s2;
      *reval = (utemp.sign) ? (utemp + (-ltemp)) : (utemp + (-ltemp));
      reval->regularization();
      return *reval;
    }
  }

  /* Multiplication Operator Overloaded */
  bigInt& operator * (const bigInt&s1, const bigInt&s2)  {
    int carry, sum, i, j;
    bigInt *reval = new bigInt, utemp, ltemp;
    reval->sign = (s1.sign == s2.sign) ? true : false;
    reval->num.pop_back();
    utemp = (s1.num.size() >= s2.num.size()) ? s1 : s2;
    ltemp = (s1.num.size() <  s2.num.size()) ? s1 : s2;
    int r = ltemp.num.size(), c = (utemp.num.size() + ltemp.num.size()), multab[r][c];
    memset(multab, 0, (sizeof(int) * r * c));
    /* Setting up the multiplication table */
    /* Every digit of the lower number represent one calculation*/
    for(i = 0; i < ltemp.num.size(); i++) {
      carry = 0;
      for(j = 0; j < utemp.num.size(); j++) {
        multab[i][i + j] = (ltemp.num.at(i) * utemp.num.at(j) + carry)%10;
        carry = (ltemp.num.at(i) * utemp.num.at(j) + carry)/10;
      }
      /* If the carry of this calculation has an extra carry, put it into the table */
      if(carry > 0)
        multab[i][i +j] = carry;
    }
    carry = 0;
    /* Adding up the multiplication table column by column */
    for(i = 0; i < c; i++) {
      sum = 0;
      for(j = 0; j < r; j++)
        sum += multab[j][i];
      /* Put the result of (sum+carry)%10 in the return vector*/
      /* Note that the carry might exceed one digit*/
      reval->num.push_back((sum + carry) % 10);
      carry = (sum + carry)/10;
    }
    /* Since the carry might exceed one digit, use while loop to push_back each digit of carry */
    while(carry > 0)  {
      reval->num.push_back(carry % 10);
      carry /= 10;
    }
    reval->regularization();
    return *reval;
  }

  /* Divide Operator Overloaded */
  bigInt& operator / (const bigInt &s1, const bigInt &s2) {
    const bool tempSign = (s1.sign == s2.sign) ? true : false;
    bigInt *reval = new bigInt, lval(s1), rval(s2); /* left operand and right operand */
    lval.sign = rval.sign = true;
    /* Escape Special cases' calculations */
    if(lval == rval)  {
      *reval = bigInt(1);
      reval->sign = tempSign;
      return *reval;
    }
    else if(rval == 1)  {   /* Does it auto-transform here ? */
      *reval = lval;
      reval->sign = tempSign;
      return *reval;
    }
    else if(rval > lval)  {
      *reval = bigInt(0); /* Cannot call default constructor here ? */
      return *reval;
    }
    /* Do the division with two dividable numbers */
    int delta(0), mtimes; /* We will cat delta zero at the begin of the vector */
    bigInt quotient(1), mtotal;
    vector<bigInt> subtab;
    subtab.push_back(rval);
    /* Multiply by 10 untill rval is GT lval */
    while(lval >= rval) {
      rval.num.insert(rval.num.begin(), 0);
      quotient.num.insert(quotient.num.begin(), 0);
      /* Establish a substraction table */
      subtab.push_back(rval); /* Where the index of the subtab vector is the times 1 multiply by 10*/
      delta++; /* how many zero I added up at the end of rval */
    }

    while((--delta) >= 0)  {
      mtimes = 0;
      while(rval > lval)  {
        rval = rval - subtab.at(delta);
        mtimes++;
      }
      if(delta != 0)  {
        rval = rval + subtab.at(delta);
        mtimes--;
      }
      mtotal.num.insert(mtotal.num.begin(), mtimes);
    }
    mtotal.num.pop_back(); /* Pop out the initialize zero */
    *reval = quotient - mtotal;
    reval->sign = tempSign;
    reval->regularization();
    return *reval;
  }
  /***************************NON MEMBER FUNCTION***************************/

  bigInt& getFactorial(const bigInt& s1)  {
    bigInt *reval = new bigInt(1), temp(s1);
    while(temp > 0)  {
      *reval = *reval * temp;
      temp = temp - 1;
    }
    return *reval;
  }

  bigInt getGcd(bigInt s1, bigInt s2)  {
    return (s1 == 0) ? s2 : getGcd(s2%s1, s1);
  }

}
