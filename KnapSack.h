#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>

using namespace std;

class KS_Item
{
  private:
    int value;
    int weight;
  public:
    const int getweight() const;
    const int getvalue() const;
    KS_Item(const KS_Item &i);
    KS_Item(const int v, const int w);
    const KS_Item& operator= (const KS_Item& rhs);

    bool operator< (const KS_Item& rhs);
    bool operator==(const KS_Item& rhs);
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
    void  setsize (const int s);
    int   getsize () const;
    void  setmu   (const float m);
    float getmu   () const;
    void  setsigma(const float s);
    float getsigma() const;
    void  generate();
    void  clear();
    friend void QuickSortP(KS_List& rhs);
    KS_Item*& operator [] (const int i);
    KS_List(const KS_List &rhs);
    KS_List(const float s = 0, const float m = 0, const int sz = 1);
    ~KS_List();
    const KS_List& operator= (const KS_List& rhs);
};



#endif 