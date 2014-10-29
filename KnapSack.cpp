#include "KnapSack.h"
#include "Greedy.h"

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

void KS_List::generate()
{
  clear();

  normal_distribution<int> gauss(getmu(),getsigma());

  Data = new KS_Item*[getsize()];

  for (int i = 0; i < size; ++i)
    Data[i] = new KS_Item(gauss(), gauss());

}

void  KS_List::clear()
{
  for (int i = 0; i < size; ++i)
    delete Data[i];

  delete [] Data;

  Data = NULL;

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