#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

class EloSystem
{
public:
  EloSystem();
  int getRA();
  int getRB();
  void setK(int val);
  void setRA(int val);
  void setRB(int val);
  void expectedScore();
  double ratingScore(int r1, double s, double e);
  void coculateALL(double s);

private:
  int K, RA, RB;
  double EA, EB;
  int roundDouble(double val);
};