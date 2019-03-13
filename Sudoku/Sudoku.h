#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Sudoku
{
  public:
    Sudoku();
    Sudoku(const int initMap[]);
    static const int sudokuSize = 81;
    void resetMap(const int setMap[]);
    void resetElement(int index, int value);
    int getElement(int index);
    int firstZeroIndex();
    bool isCorrect();
    void preCheck();
    bool reCheck(int n, int num);
    void addR(int index, int value);
    void delR(int index, int value);
    void zeroMap();
    void printAll();

  private:
    int map[sudokuSize];
    bool rowR[9][9];
    bool colR[9][9];
    bool cellR[9][3][3];
    bool checkSet(int arr[]);
};