#include <iostream>
#include "function.cpp"

using namespace std;

int main()
{
  matrix<double> X({{1.1, 0.2, 0.5, 2.4}});
  matrix<double> W1 = matrix<double>::randn(4, 5);
  matrix<double> b1(1, 5); b1 = b1.add(1.0);
  matrix<double> Y_tmp = X.dot(W1).add(b1);
  sigmoid AF1;
  matrix<double> Y(1, 5); for (int j=0; j < 5; ++j) Y._raw[0][j] = AF1.f(Y_tmp, j);
  matrix<double> W2 = matrix<double>::randn(5, 3);
  matrix<double> b2(1, 3); b2 = b2.add(0.2);
  matrix<double> Z = Y.dot(W2).add(b2);
  softmax AF2;
  matrix<double> Py(1, 3); for (int j=0; j < 3; ++j) Py._raw[0][j] = AF2.f(Z, j);
  Py.show();
  cross_entropy loss;
  matrix<double> ty({{0, 0, 1}});
  double L = loss.f(ty, Py);
  cout << L << endl;
  return 0;
}
