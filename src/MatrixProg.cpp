#include <iostream>
#include "MatrixHeader.h"
#include <limits>
namespace MatrixProg {

	void MatrixInput(MatrixElements* ptr, int& lines, int& columns) {
		
		try {
			std::cout << "Enter number of lines" << std::endl;
			lines = NumInput<int>(0, std::numeric_limits<int>::max());
			std::cout << "Enter number of columns" << std::endl;
			columns = NumInput<int>(0, std::numeric_limits<int>::max());
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

		try {
			pointer->line = line;
			pointer->column = column;
			pointer->value = value;
			pointer->nextElement = new MatrixElements;
			return pointer->nextElement;
		}
		catch (...) {
			throw;
		}

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

	int* CreateVector(MatrixElements* pointer, int lines) {

		try {
			int* vector;
			MatrixElements* ptr = pointer->nextElement;
			int i{ 0 }, number_of_elements{ 0 }, number_of_elements_in_line{ 0 };
			vector = new int[lines]();
			while (i < lines) {
				while (ptr->line == i) {
					ptr = ptr->nextElement;
				}
				while (pointer->line == i) {

					if (pointer->line < lines) {
						while (ptr->line == i + 1) {

							if (pointer->value == ptr->value) {

								number_of_elements_in_line++;
							}
							else if (pointer->value != ptr->value) {
								number_of_elements++;
								number_of_elements_in_line++;

							}
							ptr = ptr->nextElement;
						}
					}
					else {
						*(vector + i) = 999;
						break;

					}
					pointer = pointer->nextElement;
				}
				ptr = pointer->nextElement;
				if (number_of_elements==number_of_elements_in_line) {
					*(vector + i) = number_of_elements;
				}
				else {
					*(vector + i) = 0;
				}
				number_of_elements = 0;
				number_of_elements_in_line = 0;
				i++;
			}
			return vector;
		}
		catch (...) {
			throw;
		}
	}
}