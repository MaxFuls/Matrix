#include <iostream>
#include "MatrixHeader.h"
#include <limits>
namespace MatrixProg {

	void MatrixInput(MatrixElements* ptr, int lines, int columns) {
		
		try {
			for (int i{ 0 }; i < lines; i++) {
				int variable;
				for (int j{ 0 }; j < columns; j++) {
					std::cout << "Enter value " << std::endl;
					variable = NumInput<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
					if (variable) {

						ptr = addElement(i, j, variable, ptr);
					}

				}
			}
		}
		catch (...) {

			throw;
		}

	}
	MatrixElements* addElement(int line, int column, int value, MatrixElements* pointer) {

		pointer->line = line;
		pointer->column = column;
		pointer->value = value;
		pointer->nextElement = new MatrixElements;
		return pointer->nextElement;

	}
	void MatrixOutput(MatrixElements* pointer, int lines, int columns) {

		for (int i{ 0 }; i < lines; i++) {
			for (int j{ 0 }; j < columns; j++) {
				if (pointer->line == i && pointer->column == j) {
					std::cout << pointer->value << "    ";
					pointer = pointer->nextElement;
				}
				else {
					std::cout << "0    ";
				}
			}
			std::cout << "" << std::endl;
		}

	}

	void MatrixErase(MatrixElements* pointer) {



	}
}