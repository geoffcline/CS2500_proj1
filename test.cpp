int main ()
{
  clock_t t;
  int maxw;
    
  const float SIGMA = 0;
  const float MU = 0;
  const int SIZE = 0;
  const int TESTS = 0;

  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    L_working.generate()
    t = clock();
    GreedyKS(L_working, maxw);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\"" << endl; 
  }

  return 0;
}