#include <iostream>
#include "function.cpp"

using namespace std;

int main()
{
  matrix<double> X({{1.1, 0.2, 0.5, 2.4}});
  matrix<double> W1 = matrix<double>::randn(4, 5);
  matrix<double> b1(1, 5); b1 = b1.add(1.0);
  matrix<double> Y_tmp = X.dot(W1).add(b1);
  sigmoid s;
  matrix<double> Y(1, 5); for (int j=0; j < 5; ++j) Y._raw[0][j] = s.f(Y_tmp, j);
  Y_tmp.show();
  Y.show();
  return 0;
}
