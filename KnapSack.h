#ifndef KNAPSACK_H
#define KNAPSACK_H

class KS_Item
{
private:
  int value;
  int weight;
public:
  const int getweight() const {return weight;}
  const int getvalue() const {return value;}
  KS_Item(const KS_Item &i) {}
  KS_Item(const int v, const int w) {}
  const KS_Item& operator= (const KS_Item& rhs) {return rhs;}
  
  bool operator< (const KS_Item& rhs) {return true;}
  bool operator==(const KS_Item& rhs) {return true;}
  bool operator> (const KS_Item& rhs) {return !(*this < rhs);}
  bool operator!=(const KS_Item& rhs) {return !(*this == rhs);}
  bool operator<=(const KS_Item& rhs) {return (*this < rhs) || (*this == rhs);}
  bool operator>=(const KS_Item& rhs) {return (*this > rhs) || (*this == rhs);}
};


class KS_List
{
private:
  KS_Item** Data;
  int size;
  float mu;
  float sigma;
public:
  void  setsize (const int s) {size = s;}
  int   getsize () const {return size;}
  void  setmu   (const float m) {mu = m;}
  float getmu   () const {return mu;}
  void  setsigma(const float s) {sigma = s;}
  float getsigma() const {return sigma;}
  void  generate() {}
  void  clear() {}
  friend void QuickSortP(KS_List& rhs);
  KS_Item*& operator [] (const int i) {return Data[i];}
  KS_List(const KS_List &rhs) {}
  KS_List(const float s = 0, const float m = 0, const int sz = 1) {}
  ~KS_List() {}
  const KS_List& operator= (const KS_List& rhs) {return *this;}
};


#endif 