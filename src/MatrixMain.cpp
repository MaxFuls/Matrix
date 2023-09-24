#include <iostream>
#include "MatrixHeader.h"
#include "Leaks.h"
int main() {

	MatrixProg::Matrix& matrix = *(new MatrixProg::Matrix);
	matrix.FirstElement = new MatrixProg::MatrixElements;
	std::cout << sizeof(matrix)<<std::endl;
	std::cout << sizeof(*(matrix.FirstElement)) << std::endl;

	try{
		std::cout << "Enter number of lines" << std::endl;
		matrix.lines = MatrixProg::NumInput<int>(0, std::numeric_limits<int>::max());
		std::cout << "Enter number of columns" << std::endl;
		matrix.columns = MatrixProg::NumInput<int>(0, std::numeric_limits<int>::max());
	}
	catch(const std::runtime_error& re){

		std::cout << re.what() << std::endl;
		delete matrix.FirstElement;
		delete  &matrix;
		return 1;
	}
	int* vector = new int[matrix.lines]();
	try {
		std::cout << "Enter values " << std::endl;
		MatrixProg::MatrixInput(matrix);
		std::cout << std::endl << "The matrix is..." << std::endl;
		MatrixProg::MatrixOutput(matrix);
		MatrixProg::CreateVector(matrix, vector);
		std::cout << std::endl << "The vector is..." << std::endl;
		MatrixProg::VectorOutput(matrix.lines, vector);
		MatrixProg::VectorSort(vector, matrix.lines);
		std::cout << std::endl << "The new vector is..." << std::endl;
		MatrixProg::VectorOutput(matrix.lines, vector);
		MatrixProg::MatrixErase(matrix);
		MatrixProg::EraseVector(vector);
		delete &matrix;
		return 0;
	}
	catch (const std::runtime_error& re) {

		std::cout << re.what() << std::endl;
		if (matrix.FirstElement->value == 0) {
			
			delete matrix.FirstElement;
			delete[] vector;
		}
		else {
			MatrixProg::MatrixErase(matrix);
			MatrixProg::EraseVector(vector);
		}
		delete &matrix;
		return 1;
	}
	catch (const std::logic_error& le) {

		std::cout << le.what() << std::endl;
		MatrixProg::EraseVector(vector);
		delete matrix.FirstElement;
		delete  &matrix;
		return 1;
	}
	catch (const std::bad_alloc& ba){
	
		std::cerr << "Not enough memory" << std::endl;
		MatrixProg::MatrixErase(matrix);
		MatrixProg::EraseVector(vector);
		delete &(matrix);
		return 1;
	}
	catch (const std::exception& ex) {

		std::cout << "Something gets wrong" << std::endl;
		MatrixProg::MatrixErase(matrix);
		MatrixProg::EraseVector(vector);
		delete &(matrix);
		return 1;
	}
}