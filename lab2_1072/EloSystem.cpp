#include "EloSystem.h"

EloSystem::EloSystem()
{
    K = 0;
    RA = 0;
    RB = 0;
    EA = 0.0;
}

int EloSystem::getRA() { return RA; }
int EloSystem::getRB() { return RB; }
void EloSystem::setK(int val) { K = val; }
void EloSystem::setRA(int val) { RA = val; }
void EloSystem::setRB(int val) { RB = val; }

void EloSystem::expectedScore()
{
    EA = 1.0 / (1.0 + pow(10.0, (double)(RB - RA) / 400.0));
    EB = 1.0 / (1.0 + pow(10.0, (double)(RA - RB) / 400.0));
    EA = (int)(EA * pow(10, 3) + 0.5) / (pow(10, 3) * 1.0);
    EB = (int)(EB * pow(10, 3) + 0.5) / (pow(10, 3) * 1.0);
    cout << EA << " " << EB << endl;
}

double EloSystem::ratingScore(int r, double s, double e)
{
    double tmp = (double)K * (s - e);
    tmp = (int)(tmp * pow(10, 3) + 0.5) / (pow(10, 3) * 1.0);
    return r + tmp;
}

int EloSystem::roundDouble(double val)
{
    return (val > 0.0) ? floor(val + 0.5) : ceil(val - 0.5);
}

void EloSystem::coculateALL(double s)
{
    expectedScore();
    cout << ratingScore(RA, s, EA) << " " << ratingScore(RB, (1.0 - s), EB) << endl;
    RA = floor(ratingScore(RA, s, EA) + 0.5);
    RB = floor(ratingScore(RB, (1.0 - s), EB) + 0.5);
}