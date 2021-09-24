#ifndef VECOPS_HXX
#define VECOPS_HXX

#ifndef HEADERS_HXX
#include "Headers.hxx"
#endif

#include <algorithm>
#include <numeric>

std::vector<int> Argsort(const std::vector<double> &v)
{
   std::vector<int> i(v.size());
   std::iota(i.begin(), i.end(), 0);
   std::sort(i.begin(), i.end(), [&v](int i1, int i2) { return v[i1] < v[i2]; });
   return i;
}

std::vector<int> Take(const std::vector<int> &v, const std::vector<int> &i)
{
   const int isize = i.size();
   std::vector<int> r(isize);
   for (int k = 0; k < isize; k++)
      r[k] = v[i[k]];
   return r;
}

#endif
