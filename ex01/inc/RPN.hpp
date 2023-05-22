#if !defined(RPN_HPP)
#define RPN_HPP

#include <stack>
#include <stdexcept>
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
		public std::runtime_error
	{
public:
		BigNumError();
	};	// class BigNumError


	class NegativeNumError :
		public std::runtime_error
	{
public:
		NegativeNumError();
	};	// class NegativeNumError


	class MissingSpaceError :
		public std::runtime_error
	{
public:
		MissingSpaceError();
	};	// class MissingSpaceError


	class NotEnoughOperands :
		public std::runtime_error
	{
public:
		NotEnoughOperands();
	};	// class NotEnoughOperands


	class DivideByZero :
		public std::runtime_error
	{
public:
		DivideByZero();
	};	// class DivideByZero


	class EmptyStack :
		public std::runtime_error
	{
public:
		EmptyStack();
	};	// class EmptyStack

	class UnfinishedCalculation :
		public std::runtime_error
	{
public:
		UnfinishedCalculation();
	};	// class UnfinishedCalculation
};	// class RPN

#endif // RPN_HPP
