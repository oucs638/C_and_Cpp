#include "Sudoku.h"

Sudoku::Sudoku()
{
    for (int i = 0; i < sudokuSize; ++i)
        map[i] = 0;
}

Sudoku::Sudoku(const int initMap[])
{
    for (int i = 0; i < sudokuSize; ++i)
        map[i] = initMap[i];
}

void Sudoku::resetMap(const int setMap[])
{
    for (int i = 0; i < sudokuSize; ++i)
        map[i] = setMap[i];
}

void Sudoku::resetElement(int index, int value)
{
    map[index] = value;
}

int Sudoku::getElement(int index)
{
    return map[index];
}

int Sudoku::firstZeroIndex()
{
    for (int i = 0; i < sudokuSize; ++i)
        if (map[i] == 0)
            return i;
    return -1;
}

bool Sudoku::checkSet(int arr[])
{
    int tmp[9];
    for (int i = 0; i < 9; ++i)
        tmp[i] = 0;
    for (int i = 0; i < 9; ++i)
        ++tmp[arr[i] - 1];
    for (int i = 0; i < 9; ++i)
        if (tmp[i] != 1)
            return false;
    return true;
}

bool Sudoku::isCorrect()
{
    int tmp[9];
    for (int i = 0; i < 81; i += 9) // check rows
    {
        for (int j = 0; j < 9; ++j)
            tmp[j] = map[i + j];
        if (!checkSet(tmp))
            return false;
    }
    for (int i = 0; i < 9; ++i) // check cols
    {
        for (int j = 0; j < 9; ++j)
            tmp[j] = map[i + 9 * j];
        if (!checkSet(tmp))
            return false;
    }
    for (int i = 0; i < 9; ++i) // check cells
    {
        for (int j = 0; j < 9; ++j)
            tmp[j] = map[27 * (i / 3) + 3 * (i % 3) + 9 * (j / 3) + (j % 3)];
        if (!checkSet(tmp))
            return false;
    }
    return true;
}

void Sudoku::preCheck()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            rowR[i][j] = false;
            colR[i][j] = false;
        }
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                cellR[i][j][k] = false;
    for (int i = 0; i < 81; ++i)
        if (map[i] != 0)
        {
            rowR[i / 9][map[i] - 1] = true;
            colR[i % 9][map[i] - 1] = true;
            cellR[map[i] - 1][(i / 9) / 3][(i % 9) / 3] = true;
        }
}

bool Sudoku::reCheck(int n, int num)
{
    bool tmp = (rowR[n / 9][num - 1] || colR[n % 9][num - 1] || cellR[num - 1][(n / 9) / 3][(n % 9) / 3]) ? false : true;
    return tmp;
}

void Sudoku::addR(int index, int value)
{
    rowR[index / 9][value - 1] = true;
    colR[index % 9][value - 1] = true;
    cellR[value - 1][(index / 9) / 3][(index % 9) / 3] = true;
}

void Sudoku::delR(int index, int value)
{
    rowR[index / 9][value - 1] = false;
    colR[index % 9][value - 1] = false;
    cellR[value - 1][(index / 9) / 3][(index % 9) / 3] = false;
}

void Sudoku::printAll()
{
    for (int i = 0; i < 81; ++i)
    {
        cout << map[i] << " ";
        if (i % 27 == 26)
            cout << endl
                 << endl;
        else if (i % 9 == 8)
            cout << endl;
        else if (i % 3 == 2)
            cout << " ";
    }
}