void main ()
{
  clock_t t;
  int maxw;

  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    L_working.generate()
    t = clock();
    GreedyKS(L_working, maxw);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\"" << endl; 
  }

  return;
}