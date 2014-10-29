#include "KnapSack.h"
#include "Greedy.h"

bool KS_Item::operator< (const KS_Item& rhs)
{
  float LHS_ratio = getvalue() / static_cast<float>(weight());
  float RHS_ratio = rhs.getvalue() / static_cast<float>(rhs.getweight());

  return LHS_ratio < RHS_ratio;
}

bool KS_Item::operator== (const KS_Item& rhs)
{
  return (getvalue() == rhs.getvalue()) && (getweight() == rhs.getweight());
}

const KS_Item& KS_Item::operator= (const KS_Item& rhs)
{
  value = rhs.getvalue();
  weight = rhs.getweight();
}

void  KS_Item::generate()
{
  //help how do I normal distrubution
}

void  KS_Item::clear()
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
    Data[i] = new KS_Item(*rhs[i]);
}