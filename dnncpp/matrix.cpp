#include <iostream>
#include <vector>
#include <tuple>
#include <initializer_list>
#include <random>

using namespace std;

template<class T>
using Mat = vector<vector<T> >;

template<class T>
class matrix {
public:
  Mat<T> _raw;
  matrix(initializer_list<initializer_list<T> > base_array) {
    _raw = Mat<T>(base_array.begin(), base_array.end());
  }
  matrix(size_t h, size_t w) {
    _raw = Mat<T>(h, vector<T>(w));
  }
  static matrix<T> randn(size_t h, size_t w) {
    matrix<T> result = matrix<T>(h, w);
    random_device rnd;
    mt19937 mt;(rnd());
    uniform_real_distribution<> dist(0, 1);
    for (int j=0; j < h; ++j) {
      for (int k=0; k < w; ++k) {
        result._raw[j][k] = dist(mt);
      }
    }
    return result;
  }
  void show() {
    for (vector<T> &v : _raw) {
      for ( int x : v ) cout << x << ' ';
      cout << endl;
    }
  }
  tuple<size_t, size_t> shape() const {
    return make_tuple(_raw.size(), _raw[0].size());
  }
  matrix<T> dot(matrix<T> r) {
    size_t lh, lw, rh, rw;
    tie(lh, lw) = shape();
    tie(rh, rw) = r.shape();
    if (lw != rh) {
      throw "Exception : Unmatched matrix shape\n";
    } else {
      matrix<T> result = matrix(lh, rw);
      for (int j=0; j < lh; ++j) {
        for (int k=0; k < rw; ++k) {
          for (int l=0; l < lw; ++l) {
            result._raw[j][k] += _raw[j][l] * r._raw[l][k];
          }
        }
      }
      return result;
    }
  }
  matrix<T> add(matrix<T> r) {
    size_t lh, lw, rh, rw;
    tie(lh, lw) = shape();
    tie(rh, rw) = r.shape();
    if (lh != rh || lw != rw) {
      throw "Exception : Unmatched matrix shape\n";
    } else {
      matrix<T> result = matrix(lh, lw);
      for (int j=0; j < lh; ++j) {
        for (int k=0; k < lw; ++k) {
          result._raw[j][k] = _raw[j][k] + r._raw[j][k];
        }
      }
      return result;
    }
  }
  matrix<T> add(T a) {
    size_t lh, lw;
    tie(lh, lw) = shape();
    matrix<T> result = matrix(lh, lw);
    for (int j=0; j < lh; ++j) {
      for (int k=0; k < lw; ++k) {
        result._raw[j][k] += a;
      }
    }
    return result;
  }
  matrix<T> sub(matrix<T> r) {
    size_t lh, lw, rh, rw;
    tie(lh, lw) = shape();
    tie(rh, rw) = r.shape();
    if (lh != rh || lw != rw) {
      throw "Exception : Unmatched matrix shape\n";
    } else {
      matrix<T> result = matrix(lh, lw);
      for (int j=0; j < lh; ++j) {
        for (int k=0; k < lw; ++k) {
          result._raw[j][k] = _raw[j][k] - r._raw[j][k];
        }
      }
      return result;
    }
  }
  static matrix<double> identity(size_t h, size_t w) {
    matrix<double> result(h, w);
    for (int j=0; j < min(h, w); ++j) {
      result._raw[j][j] = 1.0;
    }
  }
  matrix<T> t() {
    size_t h, w;
    tie(h, w) = shape();
    matrix<T> result = matrix<T>(w, h);
    for (int j=0; j < w; ++j) {
      for (int k=0; k < h; ++k) {
        result._raw[j][k] = _raw[k][j];
      }
    }
    return result;
  }
};
