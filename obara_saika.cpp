#include <algorithm>

#include "shell.h"

#include "obara_saika.h"

X2::X2() {
}

X2::X2(int scale, std::vector<int> prefactors, std::vector<int> q, string kind, std::vector<int> oper, int order) {
}

X4::X4() {
}

X4::X4(int scale, std::vector<int> prefactors, std::vector<int> q, int order) {
}

int find_fun_to_lower(std::vector<int> q, int n) {

  // Determine the total angular momentum on each center.
  std::vector<int> l;
  for (int i = 0; i < n; i++)
    l.push_back(q[i*3] + q[i*3 + 1] + q[i*3 + 2]);

  // find function to lower
  // start with lowest angular momentum above s
  int fun = -1;
  int kmax = *std::max_element(l.begin(), l.end()) + 1;
  int k;
  for (int i = 0; i < n; i++) {
    k = l[i];
    // If we're larger than an s-function...
    if (k > 0)
      if (k < kmax) {
        kmax = k;
        fun = i;
      }
  }

  return fun;

}

int find_component_to_lower(std::vector<int> fun) {

  int i = 0;
  for (auto c : fun) {
    if (c > 0)
      return i;
    i++;
  }

  return -1;

}

double get_r12_squared(std::vector<double> r1, std::vector<double> r2) {

  return pow(r1[0] - r2[0], 2.0) + pow(r1[1] - r2[1], 2.0) + pow(r1[2] - r2[2], 2.0);

}

double get_k(double z1, double z2, std::vector<double> r1, std::vector<double> r2) {

  double r12 = get_r12_squared(r1, r2);
  double f0 = z1 + z2;
  double f2;
  if (r12 > 0.0) {
    double f1 = -z1*z2*r12/f0;
    f2 = exp(f1);
  } else
    f2 = 1.0;
  return pow(sqrt(2.0)*f2*pi, 5.0/4.0) / f0;

}

double get_rho(double za, double zb, double zc, double zd) {

  double z = za + zb;
  double n = zc + zd;
  return z * n / (z + n);

}

std::vector<double> get_bi_center(double z1, double z2, std::vector<double> r1, std::vector<double> r2) {

  double z = z1 + z2;
  double rx = (z1*r1[0] + z2*r2[0]) / z;
  double ry = (z1*r1[1] + z2*r2[1]) / z;
  double rz = (z1*r1[2] + z2*r2[2]) / z;

  std::vector<double> bi_center = {rx, ry, rz);
  return bi_center;

}

int sum(std::vector<int> v) {

  int acc = 0;
  for (auto elem : v)
    acc += elem;
  return acc;

}

double sum(std::vector<double> v) {

  double acc = 0.0;
  for (auto elem : v)
    acc += elem;
  return acc;

}

std::list<X4> apply_os4(X4 x4) {

  int s = sum(x4.q);
  if (s == 0) {
    std::list<X4> ret;
    ret.push_back(x4);
    return ret;
  }

  int fun = find_fun_to_lower(x4.q, 4);
  if (fun == -1) {
    std::list<X4> ret;
    ret.push_back(x4);
    return ret;
  }

  int component = find_component_to_lower();
  
}

double get_overlap(double za, double zb, std::vector<double> ra, std::vector<double> rb, std::vector<int> c) {

  double z = za + zb;
  double e = (za * zb) / z;
  std::vector<double> rp = get_bi_center(za, zb, ra, rb);
  double ab = get_r12_squared(ra, rb);
  double aux = exp(-e*ab) * pow(pi/z, 1.5);
  
}
