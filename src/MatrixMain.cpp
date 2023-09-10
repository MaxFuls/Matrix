#include <iostream>
#include "MatrixHeader.h"

int main() {
	MatrixProg::MatrixElements* FirstElement;
	FirstElement = new MatrixProg::MatrixElements;
	int  m, n;
	std::cout << "Enter number of lines" << std::endl;
	m = MatrixProg::NumInput<int>(0, std::numeric_limits<int>::max());
	std::cout << "Enter number of columns" << std::endl;
	n = MatrixProg::NumInput<int>(0, std::numeric_limits<int>::max());
	try
	{
		MatrixProg::MatrixInput(FirstElement, m, n);
		MatrixProg::MatrixOutput(FirstElement, m, n);
	}
	catch (const std::exception&)
	{

	}
	return 0;
}