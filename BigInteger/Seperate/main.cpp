#include <bits/stdc++.h>
#include "ClassBigInt.h"
using namespace std;
using namespace ClassBigInt;

int main(int argc, char **argv) {
  bigInt a = getFactorial(100), b = getFactorial(81);
  cout <<"a=100!=\t" << a << endl << "b=81!=\t" << b << endl << "a+b=\t" << a+b << endl << "a-b=\t" << a-b << endl\
    << "a*b=\t" << a*b << endl << "a/b=\t" << a/b << endl << "a mod b=\t" << a%b << endl << "GCD(a,b)=\t" << getGcd(a,b) << endl;
  return 0;
}
