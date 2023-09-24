#include <iostream>
#include "MatrixHeader.h"
#include <limits>
#include <vector>

namespace MatrixProg {

	void MatrixInput(const Matrix& ptr) {

		try {
			int variable;
			MatrixElements* ptr_source = ptr.FirstElement;
			MatrixElements* ptr_for_last = ptr.FirstElement;
			for (int i{ 0 }; i < ptr.lines; i++) {

				for (int j{ 0 }; j < ptr.columns; j++) {

					variable = NumInput<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

					if (variable) {

						ptr_for_last = ptr_source;
						ptr_source = addElement(i, j, variable, ptr_source);
					}

				}
			}
			if (ptr.FirstElement->value != 0) {
				delete ptr_for_last->nextElement;
				ptr_for_last->nextElement = ptr.FirstElement;
			}
			
		}
		catch (const std::exception& e) {

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
		catch (const std::bad_alloc&  ba) {

			throw ba;
		}

	}
	void MatrixOutput(const Matrix& pointer) {

		MatrixElements* ptr = pointer.FirstElement;
		int i{ 0 }, j{ 0 };
		if (true) {
			for (i = 0; i < pointer.lines; i++) {
				for (j = 0; j < pointer.columns; j++) {

					if (ptr->line == i && ptr->column == j && ptr->value!=0) {
						std::cout << ptr->value << "    ";
						ptr = ptr->nextElement;
					}
					else {
						std::cout << "0    ";
					}
				}
				std::cout << "" << std::endl;
			}

		}
	}
	void MatrixErase(Matrix& pointer) {

		MatrixElements* ptr1;
		MatrixElements* ptr2 = ptr1 = pointer.FirstElement;
		while (true) {

			if (ptr1->nextElement->column == 0 && ptr1->nextElement->line==0) {
				delete ptr1->nextElement;
				delete ptr1;
				break;
			}
			else {
				ptr1 = ptr2->nextElement;
				delete ptr2;
				ptr2 = ptr1;
			}
		}
	}

	void CreateVector(const Matrix& pointer, int* vector) {

			if (pointer.lines == 1) {

				throw std::logic_error("It is impossible to create vector");
			}
			if (pointer.FirstElement->value == 0) {

				throw std::logic_error("There are not no-null elements. It is impossible to create vector");
			}
			MatrixElements* ptr = pointer.FirstElement->nextElement;
			MatrixElements* ptr_source = pointer.FirstElement;
			int i{ 0 }, j{ 1 }, number_of_elements{ 0 }, number_of_elements_in_line{ 0 };
			while (i < pointer.lines) {

				if (j == pointer.lines) {
					j = 0;
				}
				while (ptr_source->line == i) {
			
					while (ptr->line==i) {
						
						ptr = ptr->nextElement;

					}
					while (ptr->line == j) {

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
				j++;
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