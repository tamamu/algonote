#include <cmath>
#include "matrix.cpp"

using namespace std;
using M = matrix<double>;

class func {
public:
  virtual ~func() {}
  virtual double f(const M &in, size_t i) const = 0;
  virtual double df(double y) const = 0;
  virtual M df(const M &y, size_t i) const {
    M m(1, get<1>(y.shape()));
    m._raw[0][i] = df(y._raw[0][i]);
    return m;
  }
};

class sigmoid : public func {
public:
  double f(const M &in, size_t i) const { return 1.0 / (1.0 + exp(-in._raw[0][i])); }
  double df(double y) const { return y * (1.0 - y); }
};

class softmax : public func {
public:
  double f(const M &in, size_t i) const {
    double alpha = *max_element(in._raw[0].begin(), in._raw[0].end());
    double numer = exp(in._raw[0][i] - alpha);
    double denom = 0.0;
    for (auto x : in._raw[0]) {
      denom += exp(x - alpha);
    }
    return numer / denom;
  }
  double df(double y) const {
    return y * (1.0 - y);
  }
  M df(const M &y, size_t i) const {
    M m(1, get<1>(y.shape()));
    for (int j = 0; j < y._raw[0].size(); ++j) {
      m._raw[0][j] = (j == i) ? df(y._raw[0][i]) : -y._raw[0][j] * y._raw[0][i];
    }
    return m;
  }
};
