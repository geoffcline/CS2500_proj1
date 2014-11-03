#include "KnapSack.h"
#include "Greedy.h"
#include <iostream>

bool KS_Item::operator< (const KS_Item& rhs) const
{
  float LHS_ratio = getvalue() / static_cast<float>(getweight());
  float RHS_ratio = rhs.getvalue() / static_cast<float>(rhs.getweight());
  
  return LHS_ratio < RHS_ratio;
}

bool KS_Item::operator== (const KS_Item& rhs) const
{
  return (getvalue() == rhs.getvalue()) && (getweight() == rhs.getweight());
}

const KS_Item& KS_Item::operator= (const KS_Item& rhs)
{
  value = rhs.getvalue();
  weight = rhs.getweight();
  
  return *this;
}

void KS_List::generate(const int newsz)
{
  //static random number generator, ensures random across calls
  static default_random_engine generator(static_cast<unsigned int>(time(0)));
  
  
  normal_distribution<float> gauss(getmu(),getsigma());

  clear();
  
  size = newsz;
  
  Data = new KS_Item*[getsize()];
  
  for (int i = 0; i < getsize(); ++i)
  {
    do
    {
      Data[i] = new KS_Item(static_cast<int>(gauss(generator)), static_cast<int>(gauss(generator)));
    } while (Data[i] -> getweight() < 0 || Data[i] -> getvalue() < 0);
    //prevents creation of items with negative weight or value
    
  }
  
  
}

void KS_List::generate()
{
  generate(getsize());
}

void  KS_List::clear()
{
  if(getsize() != 0)
  {
    for (int i = 0; i < size; ++i)
      delete Data[i];
    
    delete [] Data;
    
    Data = NULL;
  }
  
  size = 0;
}

const KS_List& KS_List::operator= (const KS_List& rhs)
{
  size = rhs.getsize();
  mu = rhs.getmu();
  sigma = rhs.getsigma();
  
  Data = new KS_Item*[size];
  
  for (int i = 0; i < size; ++i)
    Data[i] = new KS_Item(*(rhs[i]));
  
  return *this;
}

int KS_List::getweights() const
{
  int weight_sum = 0;
  
  for (int i = 0; i < getsize(); ++i)
    weight_sum += Data[i] -> getweight();
  
  return weight_sum;
  
}

ostream& operator << (ostream& out, const KS_List& list)
{
  for (int i = 0; i < list.getsize(); i++)
  {
    out << *list[i] << endl;
  }
  
  return out;
}

ostream& operator << (ostream& out, const KS_Item& item)
{

  out << "I: \t" << item.getvalue() << "\t" << item.getweight();
  
  return out;
}

