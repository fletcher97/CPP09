#include <iostream>

#include "Log.hpp"

#include "BitcoinExchangeUT.hpp"

BitcoinExchangeUT::BitcoinExchangeUT() :
	flt::Testable< BitcoinExchangeUT >("BitcoinExchange"),
	BitcoinExchange("res/data.csv")
{
	REGISTER(BitcoinExchangeUT, test_date_leap)
	REGISTER(BitcoinExchangeUT, test_date_normal1)
	REGISTER(BitcoinExchangeUT, test_date_normal2)
	REGISTER(BitcoinExchangeUT, test_date_normal3)
	REGISTER(BitcoinExchangeUT, test_date_normal4)

	REGISTER(BitcoinExchangeUT, test_date_bad_day1)
	REGISTER(BitcoinExchangeUT, test_date_bad_day2)
	REGISTER(BitcoinExchangeUT, test_date_bad_day3)
	REGISTER(BitcoinExchangeUT, test_date_bad_day4)
	REGISTER(BitcoinExchangeUT, test_date_bad_month1)
	REGISTER(BitcoinExchangeUT, test_date_bad_month2)
	REGISTER(BitcoinExchangeUT, test_date_bad_month3)
	REGISTER(BitcoinExchangeUT, test_date_bad_multi1)
	REGISTER(BitcoinExchangeUT, test_date_bad_multi2)

	REGISTER(BitcoinExchangeUT, test_date_bad_format1)
	REGISTER(BitcoinExchangeUT, test_date_bad_format2)
	REGISTER(BitcoinExchangeUT, test_date_bad_format3)
	REGISTER(BitcoinExchangeUT, test_date_bad_format4)
	REGISTER(BitcoinExchangeUT, test_date_bad_format5)
	REGISTER(BitcoinExchangeUT, test_date_bad_format6)
	REGISTER(BitcoinExchangeUT, test_date_bad_format7)
	REGISTER(BitcoinExchangeUT, test_date_bad_format8)
	REGISTER(BitcoinExchangeUT, test_date_bad_format9)
	REGISTER(BitcoinExchangeUT, test_date_bad_format10)

	REGISTER(BitcoinExchangeUT, test_getValue_past)
	REGISTER(BitcoinExchangeUT, test_getValue_future)
	REGISTER(BitcoinExchangeUT, test_getValue_exact1)
	REGISTER(BitcoinExchangeUT, test_getValue_exact2)
	REGISTER(BitcoinExchangeUT, test_getValue_middle1)
	REGISTER(BitcoinExchangeUT, test_getValue_middle2)
	REGISTER(BitcoinExchangeUT, test_getValue_bad1)
	REGISTER(BitcoinExchangeUT, test_getValue_bad2)
	REGISTER(BitcoinExchangeUT, test_getValue_bad3)

	REGISTER(BitcoinExchangeUT, test_proc_subject1)
	REGISTER(BitcoinExchangeUT, test_proc_subject2)
	REGISTER(BitcoinExchangeUT, test_proc_subject3)
	REGISTER(BitcoinExchangeUT, test_proc_subject4)
	REGISTER(BitcoinExchangeUT, test_proc_subject5)
	REGISTER(BitcoinExchangeUT, test_proc_subject6)
	REGISTER(BitcoinExchangeUT, test_proc_subject7)
	REGISTER(BitcoinExchangeUT, test_proc_subject8)
	REGISTER(BitcoinExchangeUT, test_proc_subject9)

	REGISTER(BitcoinExchangeUT, test_proc_extra1)
	REGISTER(BitcoinExchangeUT, test_proc_extra2)
	REGISTER(BitcoinExchangeUT, test_proc_extra3)
	REGISTER(BitcoinExchangeUT, test_proc_extra4)
	REGISTER(BitcoinExchangeUT, test_proc_extra5)
	REGISTER(BitcoinExchangeUT, test_proc_extra6)
}


void
BitcoinExchangeUT::init(void)
{
	this->newbuf = new std::stringstream();
	this->oldbuf = std::clog.rdbuf(this->newbuf->rdbuf());
}	// LogUT::init


void
BitcoinExchangeUT::term(void)
{
	std::clog.rdbuf(this->oldbuf);
	delete this->newbuf;
	this->newbuf = NULL;
}	// LogUT::term


void
BitcoinExchangeUT::test_date_leap()
{
	bool valid_date;

	ASSERT_NOTHROW(valid_date = this->checkDate("2008-02-29"))
	ASSERT(valid_date)
}	// BitcoinExchangeUT::test_date_leap


void
BitcoinExchangeUT::test_date_normal1()
{
	bool valid_date;

	ASSERT_NOTHROW(valid_date = this->checkDate("2023-05-20"))
	ASSERT(valid_date)
}	// BitcoinExchangeUT::test_date_normal1


void
BitcoinExchangeUT::test_date_normal2()
{
	bool valid_date;

	ASSERT_NOTHROW(valid_date = this->checkDate("1999-12-31"))
	ASSERT(valid_date)
}	// BitcoinExchangeUT::test_date_normal2


void
BitcoinExchangeUT::test_date_normal3()
{
	bool valid_date;

	ASSERT_NOTHROW(valid_date = this->checkDate("1987-06-15"))
	ASSERT(valid_date)
}	// BitcoinExchangeUT::test_date_normal3


void
BitcoinExchangeUT::test_date_normal4()
{
	bool valid_date;

	ASSERT_NOTHROW(valid_date = this->checkDate("2022-11-01"))
	ASSERT(valid_date)
}	// BitcoinExchangeUT::test_date_normal4


void
BitcoinExchangeUT::test_date_bad_day1()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2008-02-30"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_day1


void
BitcoinExchangeUT::test_date_bad_day2()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2008-02-30"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_day2


void
BitcoinExchangeUT::test_date_bad_day3()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2008-02-100"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_day3


void
BitcoinExchangeUT::test_date_bad_day4()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2008-02-00"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_day4


void
BitcoinExchangeUT::test_date_bad_month1()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("1999-00-31"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_month1


void
BitcoinExchangeUT::test_date_bad_month2()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2021-13-01"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_month2


void
BitcoinExchangeUT::test_date_bad_month3()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2021-00-01"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_month3


void
BitcoinExchangeUT::test_date_bad_multi1()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2023-13-32"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_multi1


void
BitcoinExchangeUT::test_date_bad_multi2()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("1987-15-06"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_multi2


void
BitcoinExchangeUT::test_date_bad_format1()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("01/31/2023"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format1


void
BitcoinExchangeUT::test_date_bad_format2()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2023-10:15"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format2


void
BitcoinExchangeUT::test_date_bad_format3()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("15.11.2023"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format3


void
BitcoinExchangeUT::test_date_bad_format4()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2023/07/22"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format4


void
BitcoinExchangeUT::test_date_bad_format5()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("06-12-2023"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format5


void
BitcoinExchangeUT::test_date_bad_format6()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("13/31/2023"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format6


void
BitcoinExchangeUT::test_date_bad_format7()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2023:02:29"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format7


void
BitcoinExchangeUT::test_date_bad_format8()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("25.10.2023"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format8


void
BitcoinExchangeUT::test_date_bad_format9()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("2023/00/22"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format9


void
BitcoinExchangeUT::test_date_bad_format10()
{
	bool invalid_date;

	ASSERT_NOTHROW(invalid_date = this->checkDate("06-00-2023"))
	ASSERT_NOT(invalid_date)
}	// BitcoinExchangeUT::test_date_bad_format10


void
BitcoinExchangeUT::test_getValue_past()
{
	double value;

	ASSERT_NOTHROW(value = this->getValueAt("1970-01-01", 1))
	ASSERT_FEQ(value, 0, 0.000000001)
}	// BitcoinExchangeUT::test_getValue_past


void
BitcoinExchangeUT::test_getValue_future()
{
	double value;

	ASSERT_NOTHROW(value = this->getValueAt("2030-01-01", 1))
	ASSERT_FEQ(value, 47115.93, 0.000000001)
}	// BitcoinExchangeUT::test_getValue_future


void
BitcoinExchangeUT::test_getValue_exact1()
{
	double value;

	ASSERT_NOTHROW(value = this->getValueAt("2022-01-09", 1))
	ASSERT_FEQ(value, 41864.44, 0.000000001)
}	// BitcoinExchangeUT::test_getValue_exact1


void
BitcoinExchangeUT::test_getValue_exact2()
{
	double value;

	ASSERT_NOTHROW(value = this->getValueAt("2012-12-30", 1))
	ASSERT_FEQ(value, 13.57, 0.000000001)
}	// BitcoinExchangeUT::test_getValue_exact2


void
BitcoinExchangeUT::test_getValue_middle1()
{
	double value;

	ASSERT_NOTHROW(value = this->getValueAt("2010-10-15", 1))
	ASSERT_FEQ(value, 0.1, 0.000000001)
}	// BitcoinExchangeUT::test_getValue_middle1


void
BitcoinExchangeUT::test_getValue_middle2()
{
	double value;

	ASSERT_NOTHROW(value = this->getValueAt("2012-05-12", 1))
	ASSERT_FEQ(value, 5.1, 0.000000001)
}	// BitcoinExchangeUT::test_getValue_middle2


void
BitcoinExchangeUT::test_getValue_bad1()
{
	ASSERT_THROW(this->getValueAt("2012-12-32", 1), BitcoinExchange::ParseError)
}	// BitcoinExchangeUT::test_getValue_bad1


void
BitcoinExchangeUT::test_getValue_bad2()
{
	ASSERT_THROW(this->getValueAt("2012-12-30", -1), std::invalid_argument)
}	// BitcoinExchangeUT::test_getValue_bad2


void
BitcoinExchangeUT::test_getValue_bad3()
{
	ASSERT_THROW(this->getValueAt("2012-12-30", 100000), std::invalid_argument)
}	// BitcoinExchangeUT::test_getValue_bad3


void
BitcoinExchangeUT::test_proc_subject1()
{
	std::string msg = "2011-01-03 | 3";
	std::string expected = "2011-01-03 => 3 = 0.9";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_INFO_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject1


void
BitcoinExchangeUT::test_proc_subject2()
{
	std::string msg = "2011-01-03 | 2";
	std::string expected = "2011-01-03 => 2 = 0.6";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_INFO_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject2


void
BitcoinExchangeUT::test_proc_subject3()
{
	std::string msg = "2011-01-03 | 1";
	std::string expected = "2011-01-03 => 1 = 0.3";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_INFO_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject3


void
BitcoinExchangeUT::test_proc_subject4()
{
	std::string msg = "2011-01-03 | 1.2";
	std::string expected = "2011-01-03 => 1.2 = 0.36";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_INFO_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject4


void
BitcoinExchangeUT::test_proc_subject5()
{
	std::string msg = "2011-01-09 | 1";
	std::string expected = "2011-01-09 => 1 = 0.32";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_INFO_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject5


void
BitcoinExchangeUT::test_proc_subject6()
{
	std::string msg = "2012-01-11 | -1";
	std::string expected = "Negative numbers are not allowed";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject6


void
BitcoinExchangeUT::test_proc_subject7()
{
	std::string msg = "2001-42-42";
	std::string expected = "2001-42-42 is not a valid date";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject7


void
BitcoinExchangeUT::test_proc_subject8()
{
	std::string msg = "2012-01-11 | 1";
	std::string expected = "2012-01-11 => 1 = 7.1";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_INFO_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject8


void
BitcoinExchangeUT::test_proc_subject9()
{
	std::string msg = "2012-01-11 | 2147483648";
	std::string expected = "Value too big (max: 1000)";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_subject9


void
BitcoinExchangeUT::test_proc_extra1()
{
	std::string msg = "2012-01-11 | 1 1";
	std::string expected = "Too many elements on the line";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_extra1


void
BitcoinExchangeUT::test_proc_extra2()
{
	std::string msg = "2012-01-11";
	std::string expected = "Too few elements on the line";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_extra2


void
BitcoinExchangeUT::test_proc_extra3()
{
	std::string msg = "2012-01-11 |";
	std::string expected = "Too few elements on the line";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_extra3


void
BitcoinExchangeUT::test_proc_extra4()
{
	std::string msg = "2012-01-11 | ";
	std::string expected = "Too few elements on the line";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_extra4


void
BitcoinExchangeUT::test_proc_extra5()
{
	std::string msg = "\n";
	std::string expected = "Empty line";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_extra5


void
BitcoinExchangeUT::test_proc_extra6()
{
	std::string msg = "2012-01-11 | 1,1";
	std::string expected = "Failed to parse value as double";
	std::istringstream is(msg);
	std::string result;

	this->newbuf->str(std::string());

	ASSERT_NOTHROW(this->batchProc(is))
	result = this->newbuf->str();
	expected = FLT_LOG_ERROR_MSG(expected) + "\n";
	ASSERT_EQ(expected, result)
}	// BitcoinExchangeUT::test_proc_extra6
