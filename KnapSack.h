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
  
  //copy constructor
  KS_Item(const KS_Item &i): value(i.value), weight(i.weight) {}
  
  //default constructor
  KS_Item(const int v, const int w): value(v), weight(w) {}
  
  const KS_Item& operator= (const KS_Item& rhs);
  
  //COMPARISON OPERATORS
  //calculate value/weight ratio & compare
  bool operator< (const KS_Item& rhs) const;
  bool operator==(const KS_Item& rhs) const;
  bool operator> (const KS_Item& rhs) const {return !(*this < rhs);}
  bool operator!=(const KS_Item& rhs) const {return !(*this == rhs);}
  bool operator<=(const KS_Item& rhs) const {return (*this < rhs) || (*this == rhs);}
  bool operator>=(const KS_Item& rhs) const {return (*this > rhs) || (*this == rhs);}
  
  //formatted output of value & weight
  friend ostream& operator << (ostream& out, const KS_Item& item) ;
};


class KS_List
{
private:
  KS_Item** Data;
  int size;
  float mu;
  float sigma;
  
  //size must coresspond to current dynamic array
  void  setsize (const int s) {size = s; generate();}
public:
  int   getsize () const {return size;}
  void  setmu   (const float m) {mu = m;}
  float getmu   () const {return mu;}
  void  setsigma(const float s) {sigma = s;}
  float getsigma() const {return sigma;}
  
  //generate new array of items using mu & sigma
  void  generate();
  
  //change the size of the list, and regenrate items
  void  generate(const int newsz);
  
  void  clear();
  
  friend void QuickSortP(KS_List& rhs);
  
  //allow manipulation of member KS_Items
  KS_Item* operator [] (const int i) const {return Data[i];}
  
  KS_List(const KS_List &rhs) {*this = rhs;};
  
  KS_List(const float s = 0, const float m = 0, const int sz = 1): sigma(s), mu(m), size(0) {generate(sz);}
  
  ~KS_List() {clear();}
  
  //provide deep copy
  const KS_List& operator= (const KS_List& rhs);
  
  //returns sum weight of all items contained
  int getweights() const;
  
  //formated output of all contained items
  friend ostream& operator << (ostream& out, const KS_List& list);
};


#endif 