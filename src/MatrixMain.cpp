#include <iostream>
#include "MatrixHeader.h"

int main() {
	MatrixProg::MatrixElements* FirstElement;
	FirstElement = new MatrixProg::MatrixElements;
	try
	{
		MatrixProg::MatrixInput();
	}
	catch (const std::exception&)
	{

	}
	return 0;
}