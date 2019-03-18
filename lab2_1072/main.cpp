#include "EloSystem.h"

int main()
{
    int tmpI;
    double sa;
    EloSystem elo;
    ifstream infile("file.in", ios::in);
    ofstream outfile("file.out", ios::out);

    infile >> tmpI;
    elo.setK(tmpI);
    infile >> tmpI;
    elo.setRA(tmpI);
    infile >> tmpI;
    elo.setRB(tmpI);
    outfile << elo.getRA() << " " << elo.getRB() << endl;

    for (int index = 0; index < 6; ++index)
    {
        infile >> sa;
        elo.coculateALL(sa);
        outfile << elo.getRA() << " " << elo.getRB() << endl;
    }

    return 0;
}