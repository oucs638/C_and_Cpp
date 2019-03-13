#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
using namespace std;

bool solve(Sudoku question, Sudoku & answer)
{
	int firstZero;
	firstZero = question.getFirstZeroIndex();
	if(firstZero==-1)
	{  //end condition
		if(question.isCorrect())
		{
			answer = question;
			return true;
		}
		else
			return false;
	}
	else
	{
		for(int num=1; num<=9; ++num)
		{
			if(question.reCheck(firstZero, num))
			{
				question.setElement(firstZero, num);
				question.addRecord(firstZero, num);
				if(solve(question, answer))
					return true;
				else
					question.delRecord(firstZero, num);
			}
		}
		return false;
	}
}
void generate(Sudoku & question, Sudoku & answer, int blank)
{
	srand(time(NULL));
	int num, index;
	int check[9]={0};
	for(int i=0; i<9; ++i)
	{
		num=rand()%9+1;
		while(check[num-1]!=0)
			num=rand()%9+1;
		question.setElement(i, num);
		check[num-1]++;
	}

	question.preCheck();
	solve(question, answer);
	question=answer;
	
	for(int i=0; i<blank; ++i)
	{
		index=rand()%81;
		while(question.getElement(index)==0)
			index=rand()%81;
		question.setElement(index, 0);
	}
	
	
}
int main()
{
	srand(time(NULL));
	Sudoku ques;
	Sudoku ans;
	char mission;
	cout << "What do you want to do?" << endl;
	cout << "solve(s) or generate(g)" << endl;
	cin >> mission;
	
	if(mission=='s')
	{
		//printf("%c", mission);
		int num;
		ifstream infile("question", ios::in);
		for(int i=0; i<81; ++i)  //read in question
		{
			infile >> num;
			ques.setElement(i, num);
		}
		ques.printAll();
		ques.preCheck();
		if(solve(ques, ans)==true)
		{
			cout << "Solvable!\n";
			ans.printAll();
		}
		else
			cout << "Unsolvable!!\n";
	}
	else if(mission=='g')
	{
		int blank;
		cout << "Which way do you want to decide how many blank?" << endl;
		cout << "keyboard(k) or random(r)" << endl;
		cin >> mission;
		
		if(mission=='k')
			cin >> blank;
		else if(mission=='r')
			blank=rand()%80+1;
		else
			cout << "ERROR (not correct mission choice)" << endl;

		generate(ques, ans, blank);
		ques.printAll();
		ans.printAll();
	}
	else
	{
		cout << "ERROR (not correct mission choice)" << endl;
	}

	return 0;
}
