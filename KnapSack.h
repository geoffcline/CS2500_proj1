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
    item(const item &i);
    item(const int v, const int w);
    const KS_Item& operator= (const KS_Item& rhs);

    bool operator< (const item_ratio& rhs);
    bool operator==(const item_ratio& rhs);
    bool operator> (const item_ratio& rhs) {return !(*this < rhs);}
    bool operator!=(const item_ratio& rhs) {return !(*this == rhs);}
    bool operator<=(const item_ratio& rhs) {return (*this < rhs) || (*this == rhs);}
    bool operator>=(const item_ratio& rhs) {return (*this > rhs) || (*this == rhs);}
};



class KS_List
{
  private:
    KS_Item** Data;
    int size;
    float mu;
    float sigmal
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
    KSlist(const KS_List &rhs);
    KSlist(const int s = 0, const float m = 0, const float sz = 1);
    ~KSlist();
    const KS_List& operator= (const KS_List& rhs);
};



#endif 