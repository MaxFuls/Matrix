#include <iostream>
#include "MatrixHeader.h"
#include <limits>
namespace MatrixProg {

	void MatrixInput() {

		int  m,  n;
		std::cout << "Enter number of lines" << std::endl;
		m = NumInput<int>(0, std::numeric_limits<int>::max());
		std::cout << "Enter number of columns" << std::endl;
		n = NumInput<int>(0, std::numeric_limits<int>::max());
		for (int i{ 0 }; i < m; i++) {
			for (int j{ 0 }; j < n; j++) {

			}
		}

	}









	void addElement(int line, int column, int value) {

	}

}