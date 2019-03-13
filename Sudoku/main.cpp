#include "Sudoku.h"

bool isSolve(Sudoku qu, Sudoku &ans)
{
    int firstZero = qu.firstZeroIndex();
    if (firstZero == -1)
    {
        if (qu.isCorrect())
        {
            ans = qu;
            return true;
        }
        else
            return false;
    }
    else
    {
        for (int num = 1; num <= 9; ++num)
        {
            if (qu.reCheck(firstZero, num))
            {
                qu.resetElement(firstZero, num);
                qu.addR(firstZero, num);
                if (isSolve(qu, ans))
                    return true;
                else
                    qu.delR(firstZero, num);
            }
        }
        return false;
    }
}
void generate(Sudoku &qu, Sudoku &ans, int blank)
{
    srand(time(NULL));
    int tmp[9];
    for (int i = 0; i < 9; ++i)
        tmp[i] = 0;
    for (int i = 0; i < 9; ++i)
    {
        int num = rand() % 9 + 1;
        while (tmp[num - 1] != 0)
            num = rand() % 9 + 1;
        qu.resetElement(i, num);
        tmp[num - 1]++;
    }
    qu.preCheck();
    isSolve(qu, ans);
    qu = ans;
    for (int i = 0; i < blank; ++i)
    {
        int index = rand() % 81;
        while (qu.getElement(index) == 0)
            index = rand() % 81;
        qu.resetElement(index, 0);
    }
}

int main()
{
    srand(time(NULL));
    Sudoku qu, ans;
    char mission;
    cout << "What do you want to do?" << endl;
    cout << "solve(s) or generate(g)" << endl;
    cin >> mission;

    if (mission == 's')
    {
        int tmp;
        ifstream infile("question.txt", ios::in);
        for (int i = 0; i < 81; ++i)
        {
            infile >> tmp;
            qu.resetElement(i, tmp);
        }
        qu.printAll();
        qu.preCheck();
        if (isSolve(qu, ans) == true)
        {
            cout << "Solvable!" << endl;
            ans.printAll();
        }
        else
            cout << "Unsolvable!!" << endl;
    }
    else if (mission == 'g')
    {
        int blank;
        cout << "Which way do you want to decide how many blank?" << endl;
        cout << "keyboard(k) or random(r)" << endl;
        cin >> mission;

        if (mission == 'k')
            cin >> blank;
        else if (mission == 'r')
            blank = rand() % 80 + 1;
        else
            cout << "ERROR (not correct mission choice)" << endl;

        generate(qu, ans, blank);
        qu.printAll();
        ans.printAll();
    }
    else
        cout << "ERROR (not correct mission choice)" << endl;

    return 0;
}