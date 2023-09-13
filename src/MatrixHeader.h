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
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	struct MatrixElements {
		int line{ 0 };
		int column{ 0 };
		int value{ 0 };
		MatrixElements* nextElement = nullptr;
	};
	MatrixElements* addElement(int line, int column, int value, MatrixElements* pointer);
	void MatrixInput(MatrixElements* ptr, int& lines, int& columns);
	void MatrixOutput(MatrixElements* pointer, int lines, int columns);
	void MatrixErase(MatrixElements* pointer);
	int* CreateVector(MatrixElements* pointer, int lines);
	void VectorOutput(int lines, int* vector);
	void VectorSort(int* pointer, int lenght);
	void BubbleSortAscending(int* pointer, int length);
	void BubbleSortDescending(int* pointer, int length);
	void swap(int* first, int* second);
	void EraseVector(int* pointer);

}