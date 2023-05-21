#if !defined(BITCOINEXCHANGEUT_HPP)
#define BITCOINEXCHANGEUT_HPP

#include <sstream>

#include "BitcoinExchange.hpp"
#include "Testable.tpp"

class BitcoinExchangeUT :
	public flt::Testable< BitcoinExchangeUT >, BitcoinExchange
{
private:
	std::stringstream *newbuf;
	std::basic_streambuf< char, std::char_traits< char > > *oldbuf;

public:
	BitcoinExchangeUT();

	virtual void init();
	virtual void term();

	void test_date_leap();
	void test_date_normal1();
	void test_date_normal2();
	void test_date_normal3();
	void test_date_normal4();

	void test_date_bad_day1();
	void test_date_bad_day2();
	void test_date_bad_day3();
	void test_date_bad_day4();
	void test_date_bad_month1();
	void test_date_bad_month2();
	void test_date_bad_month3();
	void test_date_bad_multi1();
	void test_date_bad_multi2();

	void test_date_bad_format1();
	void test_date_bad_format2();
	void test_date_bad_format3();
	void test_date_bad_format4();
	void test_date_bad_format5();
	void test_date_bad_format6();
	void test_date_bad_format7();
	void test_date_bad_format8();
	void test_date_bad_format9();
	void test_date_bad_format10();

	void test_getValue_past();
	void test_getValue_future();
	void test_getValue_exact1();
	void test_getValue_exact2();
	void test_getValue_middle1();
	void test_getValue_middle2();
	void test_getValue_bad1();
	void test_getValue_bad2();
	void test_getValue_bad3();

	void test_proc_subject1();
	void test_proc_subject2();
	void test_proc_subject3();
	void test_proc_subject4();
	void test_proc_subject5();
	void test_proc_subject6();
	void test_proc_subject7();
	void test_proc_subject8();
	void test_proc_subject9();

	void test_proc_extra1();
	void test_proc_extra2();
	void test_proc_extra3();
	void test_proc_extra4();
	void test_proc_extra5();
	void test_proc_extra6();
};	// class BitcoinExchangeUT

#endif // BITCOINEXCHANGEUT_HPP
