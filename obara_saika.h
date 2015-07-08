#ifndef _OS_OBARA_SAIKA
#define _OS_OBARA_SAIKA

#include <vector>

class X2 {
public:
  int scale;
  std::vector<int> prefactors;
  std::vector<int> q;
  string kind;
  std::vector<int> oper;
  int order;

  X2();
  X2(int scale, std::vector<int> prefactors, std::vector<int> q, string kind, std::vector<int> oper, int order);
};

class X4 {
public:
  int scale;
  std::vector<int> prefactors;
  std::vector<int> q;
  int order;

  X4();
  X4(int scale, std::vector<int> prefactors, std::vector<int> q, int order);
};

int find_fun_to_lower(std::vector<int> q, int n);
int find_component_to_lower(std::vector<int> fun);
double get_r12_squared(std::vector<double> r1, std::vector<double> r2);
double get_k(double z1, double z2, std::vector<double> r1, std::vector<double> r2);
double get_rho(double za, double zb, double zc, double zd);
std::vector<double> get_bi_center(double z1, double z2, std::vector<double> r1, std::vector<double> r2);

int sum(std::vector<int> v);
double sum(std::vector<double> v);

double get_overlap(double za, double zb, std::vector<double> ra, std::vector<double> rb, std::vector<int> c);

#endif /* _OS_OBARA_SAIKA */
