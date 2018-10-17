#include <iostream>
#include "function.cpp"

using namespace std;

class layer {
public:
  matrix<double> W, b;
  func AF, h=nullptr;
  layer(from, to, f) {
    W = matrix<double>::randn(from, to);
    b = matrix(1, to); b = b.add(1.0);
    AF = f;
  }
  chain(layer) {
    h = layer.AF;
  }
  matrix<double> forward(matrix<double> X) {
    matrix<double> a = X.dot(W).add(b);
    matrix<double> Y(1, to); for (int j=0; j < to; ++j) Y._raw[0][j] = AF.f(a, j);
    return Y;
  }
  double backward(matrix<double> out, matrix<double> t) {
    vector<matrix<double> > delta();
    for (int j=0; j < to; ++j) {
      matrix<double> dEdy_i = AF.df(out, )
      (1, to);
    }
    if (h==nullptr) {
      delta = out.sub(t);
    } else {
      matrix<double> dEdy = AF.df(out, t);
      matrix<double> dyda = h.df(out, i);
      delta._raw[0][i] = 
    }
  }
};

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

  for (int epoch=0; epoch < 100; ++epoch) {
    matrix<double> dZ(1, 3); 
    matrix<double> dW2(5, 3);
  }

  cout << L << endl;
  return 0;
}
