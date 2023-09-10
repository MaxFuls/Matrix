#include <iostream>
#include <limits>
#pragma warning(disable:4996)
namespace MatrixProg {

	template<typename T>
	T NumInput(T min, T max) {
		T a;
		while (true) {
			std::cin >> a;
			if (std::cin.eof())
				throw std::runtime_error("Error of input: EOF");
			else if (std::cin.bad())
				throw std::runtime_error(std::string("Error of input: ") + strerror(errno));
			else if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Repeat please" << std::endl;
			}
			else if (a > min && a < max) {
				return a;
			}
			else
				std::cout << "Incorrect number. Repeat please" << std::endl;
		}
	}
	struct MatrixElements {
		int line;
		int column;
		int value;
		MatrixElements* nextElement;
	};
	void addElement(int line, int column, int value);
	void MatrixInput();
	int SizeInput();
}