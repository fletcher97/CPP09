#if !defined(BITCOINEXCHANGE_HPP)
#define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
private:
	std::map< std::string, double > _btcValues;

protected:
	bool checkDate(const std::string &date) const;

public:
	BitcoinExchange(const std::string &path);
	BitcoinExchange(const BitcoinExchange &other);
	virtual ~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange &other);

	double getValueAt(const std::string &date, double quantity) const;
	void batchProc(const std::string &path) const;
	void batchProc(std::istream &is) const;

	void printDB() const;
	void updateDB(const std::string &path);


	class FileOpenError :
		public std::runtime_error
	{
public:
		FileOpenError(const std::string &msg);
	};	// class FileOpenError

	class ParseError :
		public std::runtime_error
	{
public:
		ParseError(const std::string &msg);
	};	// class ParseError
};	// class BitcoinExchange

#endif // BITCOINEXCHANGE_HPP
