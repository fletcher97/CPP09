#include "BitcoinExchange.hpp"

#include <fstream>

#include <cctype>
#include <sstream>

#include "Log.hpp"


static bool
isleap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}	// isleap


bool
BitcoinExchange::checkDate(const std::string &date) const
{
	int i = 0;
	bool ret = true;
	int year = 0, month = 0, day = 0;

	for (std::string::const_iterator it = date.begin(); it != date.end() && ret; it++, i++) {
		if (i == 10) {
			// Too big
			return false;
		}
		if (((i == 4) || (i == 7))) {
			// No/Wrong Y/M/D separator
			if (*it != '-') {
				return false;
			}
			continue;
		}
		if ((i != 4) && (i != 7) && !std::isdigit(*it)) {
			return false;
		}

		if (i < 4) {
			year *= 10;
			year += *it - '0';
			continue;
		}
		if (i < 7) {
			month *= 10;
			month += *it - '0';
			continue;
		}
		day *= 10;
		day += *it - '0';
	}

	if ((month > 12) || !month || (day > 31) || !day) {
		return false;
	}

	if (month == 2) {
		if (isleap(year)) {
			return day <= 29;
		}

		return day <= 28;
	}

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		return day <= 30;
	}

	return true;
}	// checkDate


BitcoinExchange::BitcoinExchange(const std::string &path)
{
	this->updateDB(path);
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	_btcValues(other._btcValues)
{}


BitcoinExchange::~BitcoinExchange()
{}


BitcoinExchange&
BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->_btcValues = other._btcValues;

	return *this;
}	// BitcoinExchange::operator=


double
BitcoinExchange::getValueAt(const std::string &date, double quantity) const
{
	if (!checkDate(date)) {
		throw BitcoinExchange::ParseError(date + " is not a valid date");
	}
	if (quantity < 0) {
		throw std::invalid_argument("Quantity too small");
	}
	if (quantity > 1000) {
		throw std::invalid_argument("Quantity too big");
	}

	double rate = 0;

	for (std::map< std::string, double >::const_iterator it = this->_btcValues.begin();
		 it != this->_btcValues.end();
		 it++)
	{
		if (it->first > date) {
			break;
		}
		rate = it->second;
	}

	return rate * quantity;
}	// BitcoinExchange::getValueAt


void
BitcoinExchange::batchProc(const std::string &path) const
{
	std::ifstream ifs(path.c_str());

	if (!ifs.is_open()) {
		throw BitcoinExchange::FileOpenError("Failed to open file " + path);
	}

	this->batchProc(ifs);

	ifs.close();
}	// BitcoinExchange::batchProc


void
BitcoinExchange::batchProc(std::istream &is) const
{
	std::string line;
	std::string date;
	std::string sep;
	std::string quantity;

	while (std::getline(is, line)) {
		std::istringstream iss(line);

		if (!(iss >> date)) {
			LOG_ERROR("Empty line")
			continue;
		}
		if (!checkDate(date)) {
			LOG_ERROR(date + " is not a valid date")
			continue;
		}

		if (!(iss >> sep)) {
			LOG_ERROR("Too few elements on the line")
			continue;
		}
		if (!(iss >> quantity)) {
			LOG_ERROR("Too few elements on the line")
			continue;
		}
		if (!iss.eof()) {
			LOG_ERROR("Too many elements on the line")
			continue;
		}


		std::istringstream ivalue(quantity);
		double amount;

		ivalue >> std::noskipws >> amount;
		if (!ivalue.eof() || ivalue.fail()) {
			LOG_ERROR("Failed to parse value as double");
			continue;
		}

		if (amount < 0) {
			LOG_ERROR("Negative numbers are not allowed");
			continue;
		}
		if (amount > 1000) {
			LOG_ERROR("Value too big (max: 1000)");
			continue;
		}
		try {
			double value = getValueAt(date, amount);

			LOG_INFO(date << " => " << amount << " = " << value)
		} catch (std::exception &e) {
			LOG_ERROR(e.what())
		}
	}
}	// BitcoinExchange::batchProc


void
BitcoinExchange::printDB() const
{
	for (std::map< std::string, double >::const_iterator it = this->_btcValues.begin();
		 it != this->_btcValues.end();
		 it++)
	{
		LOG_INFO(it->first << ": " << it->second);
	}
}	// BitcoinExchange::test


void
BitcoinExchange::updateDB(const std::string &path)
{
	std::string line;
	std::string date;
	bool first = true;
	std::ifstream ifs(path.c_str());

	if (!this->_btcValues.empty()) {
		this->_btcValues.clear();
	}

	if (!ifs.is_open()) {
		throw BitcoinExchange::FileOpenError("Failed to open file " + path);
	}
	while (std::getline(ifs, line)) {
		if (first) {
			if (line != "date,exchange_rate") {
				throw BitcoinExchange::ParseError("No header line");
			}
			first = false;
			continue;
		}
		if (line.size() < 12) {
			throw BitcoinExchange::ParseError("Line too short");
		}
		date = line.substr(0, 10);

		if (!checkDate(date)) {
			throw BitcoinExchange::ParseError(date + " is not a valid date");
		}
		if (line.at(10) != ',') {
			throw BitcoinExchange::ParseError("File is incorrectly formatted (missing ',' at pos 10)");
		}
		std::istringstream iss(line.substr(11));
		double value;

		iss >> std::noskipws >> value;
		if (!iss.eof() || iss.fail()) {
			throw BitcoinExchange::ParseError("Failed to parse value as double");
		}
		this->_btcValues.insert(std::pair< std::string, double >(date, value));
	}
	ifs.close();
}	// BitcoinExchange::updateDB


BitcoinExchange::FileOpenError::FileOpenError(const std::string &msg) :
	std::runtime_error(msg)
{}


// const std::string
// BitcoinExchange::FileOpenError::what()
// {
// return "Failed to open file";
// }	// FileOpenError::what


BitcoinExchange::ParseError::ParseError(const std::string &msg) :
	std::runtime_error(msg)
{}
