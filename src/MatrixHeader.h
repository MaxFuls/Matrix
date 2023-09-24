#include <iostream>
#include <limits>
#pragma warning(disable:4996)

namespace MatrixProg {

	template<typename T>
	T NumInput(T min, T max) {
		T a;
		while (true) {
			std::cin >> a;
			char c;
			std::cin.get(c);
			if (std::cin.eof())
				throw std::runtime_error("Error of input: EOF");
			else if (std::cin.bad())
				throw std::runtime_error(std::string("Error of input: ") + strerror(errno));
			else if (std::cin.fail()) {
				std::cout << "Repeat please" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (a > min && a < max && (c==' ' || c=='\n'))
				return a;
			else {
				std::cout << "Repeat please" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	struct MatrixElements {
		int line{ 0 };
		int column{ 0 };
		int value{ 0 };
		MatrixElements* nextElement;
	};
	struct Matrix {

		int lines { 0 };
		int columns { 0 };
		MatrixElements* FirstElement;
	};
	MatrixElements* addElement(int , int , int , MatrixElements* );
	void MatrixInput(const Matrix& );
	void MatrixOutput(const Matrix& );
	void MatrixErase(Matrix& );
	void CreateVector(const Matrix& , int*);
	void VectorOutput(int , int* );
	void VectorSort(int* , int );
	void BubbleSortAscending(int* , int );
	void BubbleSortDescending(int* , int );
	void swap(int*, int*);
	void EraseVector(int* );

}