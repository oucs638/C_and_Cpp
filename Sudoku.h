#include <iostream>
#include <vector>
class Sudoku
{
	public:
		Sudoku();
		Sudoku(const int init_map[]);
		void setMap(const int set_map[]);
		int getElement(int index);
		void setElement(int index, int value);
		int getFirstZeroIndex();
		bool isCorrect();
		static const int sudokuSize = 81;
		void zeroMap();
		void preCheck();
		bool reCheck(int n, int num);
		void addRecord(int index, int value);
		void delRecord(int index, int value);
		void printAll();

	private:
		bool checkUnity(int arr[]);
		int map[sudokuSize];
		bool row[9][9];
		bool column[9][9];
		bool cell[9][3][3];
};
