#include <sstream>

#include "Log.hpp"

#include "PmergeMe.hpp"

int
main(int argc, char const *argv[])
{
	if (argc == 1) {
		LOG_ERROR("Too few arguments")

		return 1;
	}

	PmergeMe pm;

	try {
		for (int i = 1; i < argc; i++) {
			std::string nums(argv[i]);

			pm.addElement(nums.erase(nums.find_last_not_of(' ') + 1));
		}

		// LOG_INFO("Before: " << pm.getData())
		pm.sort();
		// LOG_INFO("After: " << pm.getData())
		// pm.printVec();
		pm.printDeq();
	} catch (std::exception &e) {
		LOG_ERROR(e.what())
	}

	return 0;
}	// main
