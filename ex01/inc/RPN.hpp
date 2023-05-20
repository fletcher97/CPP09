#if !defined(RPN_HPP)
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
private:
	enum sign
	{
		ADD,
		SUB,
		MUL,
		DIV
	};

private:
	std::stack< double > _values;

public:
	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN& operator=(const RPN &other);

	void add(const std::string &op);
	void add(char value);
	void clear();

	double getResult() const;


	class BigNumError :
		public std::exception
	{
public:
		BigNumError();

		virtual const char* what();
	};	// class BigNumError


	class NegativeNumError :
		public std::exception
	{
public:
		NegativeNumError();

		virtual const char* what();
	};	// class NegativeNumError


	class MissingSpaceError :
		public std::exception
	{
public:
		MissingSpaceError();

		virtual const char* what();
	};	// class MissingSpaceError


	class NotEnoughOperands :
		public std::exception
	{
public:
		NotEnoughOperands();

		virtual const char* what();
	};	// class NotEnoughOperands


	class DivideByZero :
		public std::exception
	{
public:
		DivideByZero();

		virtual const char* what();
	};	// class DivideByZero


	class EmptyStack :
		public std::exception
	{
public:
		EmptyStack();

		virtual const char* what();
	};	// class EmptyStack

	class UnfinishedCalculation :
		public std::exception
	{
public:
		UnfinishedCalculation();

		virtual const char* what();
	};	// class UnfinishedCalculation
};	// class RPN

#endif // RPN_HPP
