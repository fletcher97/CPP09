#include <iostream>

#include "Log.hpp"

#include "RPN.hpp"

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		LOG_ERROR("Error: Exacly one argument shoud be given to this program")

		return 1;
	}

	RPN rpn;

	try {
		rpn.add(argv[1]);
		LOG_INFO(rpn.getResult())
	} catch (std::exception &e) {
		LOG_ERROR("Error: " << e.what())
	}

	return 0;
}	// main
