#include "shell.h"

std::vector< std::vector<int> > get_ijk_list(int m) {

  int i, j, k;
  std::vector< std::vector<int> > l;
  for (int a = 1; a < m + 2; a++) {
    for (int b = 1; b < a + 1; b++) {
      i = m + 1 - a;
      j = a - b;
      k = b - 1;
      std::vector<int> perm {i, j, k};
      l.push_back(perm);
    }
  }

  return l;

}

std::vector<std::vector<int> > get_shell4(int a, int b, int c, int d) {

  std::vector<std::vector<int> > components;
  std::vector<int> tmp;

  for (auto p : get_ijk_list(a)) {
    for (auto q : get_ijk_list(b)) {
      for (auto r : get_ijk_list(c)) {
        for (auto s : get_ijk_list(d)) {
          tmp.insert(tmp.end(), p.begin(), p.end());
          tmp.insert(tmp.end(), q.begin(), q.end());
          tmp.insert(tmp.end(), r.begin(), r.end());
          tmp.insert(tmp.end(), s.begin(), s.end());
          components.push_back(tmp);
        }
      }
    }
  }


  return components;

}

std::vector<std::vector<int> > get_shell2(int a, int b) {

  std::vector<std::vector<int> > components;
  std::vector<int> tmp;

  for (auto p : get_ijk_list(a)) {
    for (auto q : get_ijk_list(b)) {
      tmp.insert(tmp.end(), p.begin(), p.end());
      tmp.insert(tmp.end(), q.begin(), q.end());
      components.push_back(tmp);
    }
  }

  return components;

}

int main() {

  // std::vector< std::vector<int> > l0, l1, l2;

  // l0 = get_ijk_list(0);
  // l1 = get_ijk_list(1);
  // l2 = get_ijk_list(2);
  

  return 0;

}
