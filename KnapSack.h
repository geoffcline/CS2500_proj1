#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <random>

using namespace std;

class KS_Item
{
private:
  int value;
  int weight;
public:
  const int getweight() const {return weight;}
  const int getvalue() const {return value;}
  KS_Item(const KS_Item &i): value(i.value), weight(i.weight) {}
  KS_Item(const int v, const int w): value(v), weight(w) {}
  const KS_Item& operator= (const KS_Item& rhs);
  
  bool operator< (const KS_Item& rhs) const;
  bool operator==(const KS_Item& rhs) const;
  bool operator> (const KS_Item& rhs) const {return !(*this < rhs);}
  bool operator!=(const KS_Item& rhs) const {return !(*this == rhs);}
  bool operator<=(const KS_Item& rhs) const {return (*this < rhs) || (*this == rhs);}
  bool operator>=(const KS_Item& rhs) const {return (*this > rhs) || (*this == rhs);}
  friend ostream& operator << (ostream& out, const KS_Item& item) ;
};


class KS_List
{
private:
  KS_Item** Data;
  int size;
  float mu;
  float sigma;
  void  setsize (const int s) {size = s; generate();}
public:
  int   getsize () const {return size;}
  void  setmu   (const float m) {mu = m;}
  float getmu   () const {return mu;}
  void  setsigma(const float s) {sigma = s;}
  float getsigma() const {return sigma;}
  void  generate(const int newsz);
  void  generate();
  void  clear();
  friend void QuickSortP(KS_List& rhs);
  KS_Item* operator [] (const int i) const {return Data[i];}
  KS_List(const KS_List &rhs) {*this = rhs;};
    KS_List(const float s = 0, const float m = 0, const int sz = 1): sigma(s), mu(m), size(0) {generate(sz);}
  ~KS_List() {clear();}
  const KS_List& operator= (const KS_List& rhs);
  int getweights() const;
  friend ostream& operator << (ostream& out, const KS_List& list);
};


#endif 