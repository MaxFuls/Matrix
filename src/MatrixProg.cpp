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
			MatrixElements* ptr_source = ptr;
			for (int i{ 0 }; i < lines; i++) {
				int variable;
				for (int j{ 0 }; j < columns; j++) {
					std::cout << "Enter value " << std::endl;
					variable = NumInput<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
					if (variable && j == columns - 1 && i == lines - 1) {

						ptr->line = i;
						ptr->column = j;
						ptr->value = variable;
						ptr->nextElement = ptr_source;
					}
					else if (variable) {

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
			delete pointer->nextElement;
			throw;
		}

	}
	void MatrixOutput(MatrixElements* pointer, int lines, int columns) {

		std::cout << std::endl << "The matrix is..." << std::endl;
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
			int* vector = new int[lines]();
			MatrixElements* ptr = pointer->nextElement;
			MatrixElements* ptr_source = pointer;
			int i{ 0 }, number_of_elements{ 0 }, number_of_elements_in_line{ 0 };
			if (lines == 1) {
				std::cout << "It is impossible to create vector, using one line" << std::endl;
				delete[] vector;
				return nullptr;
			}
			while (i < lines) {

				while (ptr_source->line == i) {

					while (ptr->line == i) {

						ptr = ptr->nextElement;
					}
					while (ptr->line == i + 1 || ptr->line == 0) {

						if (ptr->value == ptr_source->value) {

							number_of_elements_in_line++;
						}
						else {
							number_of_elements++;
							number_of_elements_in_line++;
						}
						ptr = ptr->nextElement;
					}
					if (number_of_elements == number_of_elements_in_line) {
						*(vector + i) += 1;
					}
					ptr_source = ptr_source->nextElement;
					ptr = ptr_source->nextElement;
					number_of_elements = 0;
					number_of_elements_in_line = 0;
				}
				i++;
			}
			return vector;
		}
		catch (std::exception) {

			throw;
		}
	}
	void VectorOutput(int lines, int* vector) {

		for (int i{ 0 }; i < lines; i++)
			std::cout << *(vector + i) << std::endl;
	}
	void VectorSort(int* pointer, int length) {

		if (*(pointer) > *(pointer + 1)) {

			BubbleSortAscending(pointer, length);
		}
		else if (*(pointer) < *(pointer + 1)) {

			BubbleSortDescending(pointer, length);
		}
	}
	void BubbleSortAscending(int* pointer, int length) {

		int i{ 0 }, right_position{ 0 };
		while (right_position != length - 1) {
			right_position = 0;
			while (i < length-1) {
				if (*(pointer + i) > *(pointer + i + 1)) {

					swap(pointer + i, pointer + i + 1);
				}
				else {
					right_position++;
				}
				i++;
			}
			i = 0;
		}
	}
	void BubbleSortDescending(int* pointer, int length) {

		int i{ 0 }, right_position{ 0 };
		while (right_position != length - 1) {
			right_position = 0;
			while (i < length - 1) {
				if (*(pointer + i) < *(pointer + i + 1)) {

					swap(pointer + i, pointer + i + 1);
				}
				else {
					right_position++;
				}
				i++;
			}
			i = 0;
		}
	}
	void swap(int* first, int* second) {
		int tmp;
		tmp = *first;
		*first = *second;
		*second = tmp;
	}
	void EraseVector(int* pointer) {

		delete[] pointer;
	}
}