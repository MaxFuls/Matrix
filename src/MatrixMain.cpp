#include <iostream>
#include "MatrixHeader.h"

int main() {
	
	MatrixProg::Matrix& matrix = *(new MatrixProg::Matrix);
	matrix.FirstElement = new MatrixProg::MatrixElements;
	try
	{
		std::cout << "Enter number of lines" << std::endl;
		matrix.lines = MatrixProg::NumInput<int>(0, std::numeric_limits<int>::max());
		std::cout << "Enter number of columns" << std::endl;
		matrix.columns = MatrixProg::NumInput<int>(0, std::numeric_limits<int>::max());
		std::cout << "Enter values " << std::endl;
		MatrixProg::MatrixInput(matrix);
		std::cout << std::endl << "The matrix is..." << std::endl;
		MatrixProg::MatrixOutput(matrix);
		int* vector = MatrixProg::CreateVector(matrix);
		if (vector != nullptr) {
			std::cout << std::endl << "The vector is..." << std::endl;
			MatrixProg::VectorOutput(matrix.lines, vector);
			MatrixProg::VectorSort(vector, matrix.lines);
			std::cout << std::endl << "The new vector is..." << std::endl;
			MatrixProg::VectorOutput(matrix.lines, vector);
		}
		else {
			std::cout << "It is impossible to create vector, using one line" << std::endl;
		}
		MatrixProg::MatrixErase(matrix);
		MatrixProg::EraseVector(vector);
		delete& (matrix);

	}
	catch (const std::bad_alloc& ba){
	
		std::cerr << "Not enough memory" << std::endl;
		MatrixProg::MatrixErase(matrix);
		return 1;
	}
	catch (const std::exception& ex) {

		std::cout << ex.what() << std::endl;
		MatrixProg::MatrixErase(matrix);
		return 1;
	}
	return 0;
}