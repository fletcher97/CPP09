#include <iostream>

#include "PmergeMeUT.hpp"
#include "TestCollection.hpp"

int
main(void)
{
	ADD_TEST(PmergeMeUT)

	flt::TestCollection::instance().test();
	flt::TestCollection::instance().report(std::cout);

	return flt::TestCollection::instance().get_failed_count() != 0;
}	// main
