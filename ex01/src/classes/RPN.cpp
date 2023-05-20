#include <cctype>
#include <stdexcept>

#include "RPN.hpp"

RPN::RPN()
{}


RPN::RPN(const RPN &other) :
	_values(other._values)
{}


RPN::~RPN()
{}


RPN&
RPN::operator=(const RPN &other)
{
	this->_values = other._values;

	return *this;
}	// RPN::operator=


void
RPN::add(const std::string &op)
{
	bool num = false, neg = false, c = false;

	for (std::string::const_iterator it = op.begin(); it != op.end(); it++) {
		if (*it == ' ') {
			num = false;
			neg = false;
			c = false;
			continue;
		}
		if (num && std::isdigit(*it)) {
			throw RPN::BigNumError();
		}
		if (neg && std::isdigit(*it)) {
			throw RPN::NegativeNumError();
		}
		if (c) {
			throw RPN::MissingSpaceError();
		}

		this->add(*it);
		num = std::isdigit(*it);
		neg = *it == '-';
		c = *it != ' ';
	}
}	// RPN::add


void
RPN::add(char value)
{
	if (std::isdigit(value)) {
		this->_values.push(value - '0');

		return;
	} else {
		switch (value) {
			case '+': {
					double a, b;

					if (this->_values.size() < 2) {
						throw RPN::NotEnoughOperands();
					}
					a = this->_values.top();
					this->_values.pop();
					b = this->_values.top();
					this->_values.pop();
					this->_values.push(b + a);

					return;
				}

			case '-': {
					double a, b;

					if (this->_values.size() < 2) {
						throw RPN::NotEnoughOperands();
					}
					a = this->_values.top();
					this->_values.pop();
					b = this->_values.top();
					this->_values.pop();
					this->_values.push(b - a);

					return;
				}

			case '*': {
					double a, b;

					if (this->_values.size() < 2) {
						throw RPN::NotEnoughOperands();
					}
					a = this->_values.top();
					this->_values.pop();
					b = this->_values.top();
					this->_values.pop();
					this->_values.push(b * a);

					return;
				}

			case '/': {
					double a, b;

					if (this->_values.size() < 2) {
						throw RPN::NotEnoughOperands();
					}
					a = this->_values.top();
					this->_values.pop();
					b = this->_values.top();
					this->_values.pop();
					try {
						this->_values.push(b / a);
					} catch (std::exception &e) {
						throw RPN::DivideByZero();
					}

					return;
				}
		}	// switch
	}
	throw std::invalid_argument("Argument must be a digit or one of + - * /");
}	// RPN::add


void
RPN::clear()
{
	while (!this->_values.empty()) {
		this->_values.pop();
	}
}	// RPN::clear


double
RPN::getResult() const
{
	if (!this->_values.empty()) {
		return this->_values.top();
	}

	throw RPN::EmptyStack();
}	// RPN::getResult


/* BigNumError */
RPN::BigNumError::BigNumError()
{}


const char*
RPN::BigNumError::what()
{
	return "Only single digits may be passed";
}	// BigNumError::what


/* NegativeNumError */
RPN::NegativeNumError::NegativeNumError()
{}


const char*
RPN::NegativeNumError::what()
{
	return "Negative numbers are not allowed";
}	// NegativeNumError::what


/* MissingSpaceError */
RPN::MissingSpaceError::MissingSpaceError()
{}


const char*
RPN::MissingSpaceError::what()
{
	return "All operand and operator must be separated by at least one space";
}	// MissingSpaceError::what


/* NotEnoughOperands */
RPN::NotEnoughOperands::NotEnoughOperands()
{}


const char*
RPN::NotEnoughOperands::what()
{
	return "Not enought operands on the stack";
}	// NotEnoughOperands::what


/* DivideByZero */
RPN::DivideByZero::DivideByZero()
{}


const char*
RPN::DivideByZero::what()
{
	return "Division by zero";
}	// DivideByZero::what


/* EmptyStack */
RPN::EmptyStack::EmptyStack()
{}


const char*
RPN::EmptyStack::what()
{
	return "The stack is empty";
}	// EmptyStack::what


/* UnfinishedCalculation */
RPN::UnfinishedCalculation::UnfinishedCalculation()
{}


const char*
RPN::UnfinishedCalculation::what()
{
	return "The stack is empty";
}	// UnfinishedCalculation::what
