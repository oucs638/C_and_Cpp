#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{  //initialize map
	for(int i=0; i<sudokuSize; ++i)
		map[i]=0;
}
Sudoku::Sudoku(const int init_map[])
{
	for(int i=0; i<sudokuSize; ++i)
		map[i] = init_map[i];
}

void Sudoku::setMap(const int set_map[])
{
	for(int i=0; i<sudokuSize; ++i)
		map[i] = set_map[i];
}
int Sudoku::getElement(int index)
{
	return map[index];
}
void Sudoku::setElement(int index, int value)
{
	map[index] = value;
}
int Sudoku::getFirstZeroIndex()
{
	for(int i=0; i<sudokuSize; ++i)
		if(map[i]==0)
			return i;
	return -1;
}
bool Sudoku::checkUnity(int arr[])
{
	int arr_unity[9];  //counters

	for(int i=0; i<9; ++i)
		arr_unity[i]=0;  //initialize
	for(int i=0; i<9; ++i)
		++arr_unity[arr[i]-1];  //count
	for(int i=0; i<9; ++i)
		if(arr_unity[i] != 1)  //all element
			return false;  //must be 1
	return true;
}

bool Sudoku::isCorrect()
{
	bool check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9)  //check rows
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+j];
		check_result = checkUnity(check_arr);
		if(check_result==false)
			return false;
	}
	for(int i=0; i<9; ++i)  //check columns
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+9*j];
		check_result = checkUnity(check_arr);
		if(check_result==false)
			return false;
	}
	for(int i=0; i<9; ++i)  //check cells
	{
		for(int j=0; j<9; ++j)
		{
			location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
			check_arr[j] = map[location];
		}
		check_result = checkUnity(check_arr);
		if(check_result==false)
			return false;
	}
	return true;
}

void Sudoku::zeroMap()
{
	for(int i=0; i<81; ++i)
		map[i]=0;
}
void Sudoku::printAll()
{
	for(int i=0; i<81; ++i)
	{
		cout << map[i] << " ";
		if(i%27==26)
			cout << endl << endl;
		else if(i%9==8)
			cout << endl;
		else if(i%3==2)
			cout << " ";
	}
}
void Sudoku::preCheck()
{  //initialize check matrix
	for(int i=0; i<9; ++i)
		for(int j=0; j<9; ++j)
		{
			row[i][j]=false;
			column[i][j]=false;
		}
	for(int i=0; i<9; ++i)
		for(int j=0; j<3; ++j)
			for(int k=0; k<3; ++k)
				cell[i][j][k]=false;
   //check question
	for(int i=0; i<81; ++i)
		if(map[i]!=0)
		{
			row[i/9][map[i]-1]=true;
			column[i%9][map[i]-1]=true;
			cell[map[i]-1][(i/9)/3][(i%9)/3]=true;
		}
}
bool Sudoku::reCheck(int n, int num)
{
	if(row[n/9][num-1]==true || column[n%9][num-1]==true || cell[num-1][(n/9)/3][(n%9)/3]==true)
		return false;
	else
		return true;
}
void Sudoku::addRecord(int index, int value)
{
	row[index/9][value-1]=true;
	column[index%9][value-1]=true;
	cell[value-1][(index/9)/3][(index%9)/3]=true;
}
void Sudoku::delRecord(int index, int value)
{
	row[index/9][value-1]=false;
	column[index%9][value-1]=false;
	cell[value-1][(index/9)/3][(index%9)/3]=false;
}
