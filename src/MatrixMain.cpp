#include <iostream>
#include "MatrixHeader.h"

int main() {
	MatrixProg::MatrixElements* FirstElement;
	FirstElement = new MatrixProg::MatrixElements;
	int  lines{ 0 }, columns{ 0 };
	try
	{
		MatrixProg::MatrixInput(FirstElement, lines, columns);
		MatrixProg::MatrixOutput(FirstElement, lines, columns);
		int* vector = MatrixProg::CreateVector(FirstElement, lines);
		for (int i{ 0 }; i < lines; i++) {
			std::cout << *(vector + i) << std::endl;
		}
	}
	catch (const std::exception&)
	{

	}
	return 0;
}