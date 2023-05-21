#include "Log.hpp"

#include "BitcoinExchange.hpp"

int
main(int argc, char const *argv[])
{
	std::string database = "res/data.csv";

	if (argc == 1) {
		LOG_ERROR("No input file given")

		return 1;
	}
	if (argc > 3) {
		LOG_ERROR("Too many params")

		return 1;
	}

	if (argc == 3) {
		LOG_WARN("Parsing extra param as new database")
		database = argv[2];
	}

	try {
		BitcoinExchange btc_xchg(database);

		btc_xchg.batchProc(argv[1]);
	} catch (std::exception &e) {
		LOG_ERROR(e.what())
	}

	// read file passed as arg
	// file format: date | value
	// valid date: Year-Month-Day
	// value must be int or float 0-1000
	return 0;
}	// main
