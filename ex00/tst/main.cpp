#include <iostream>

#include "BitcoinExchangeUT.hpp"
#include "TestCollection.hpp"

int
main(void)
{
	ADD_TEST(BitcoinExchangeUT)

	flt::TestCollection::instance().test();
	flt::TestCollection::instance().report(std::cout);

	return flt::TestCollection::instance().get_failed_count() != 0;
}	// main
