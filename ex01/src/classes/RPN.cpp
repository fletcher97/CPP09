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


RPN::BigNumError::BigNumError() :
	std::runtime_error("Only single digits may be passed")
{}


RPN::NegativeNumError::NegativeNumError() :
	std::runtime_error("Negative numbers are not allowed")
{}


RPN::MissingSpaceError::MissingSpaceError() :
	std::runtime_error("All operand and operator must be separated by at least one space")
{}


RPN::NotEnoughOperands::NotEnoughOperands() :
	std::runtime_error("Not enought operands on the stack")
{}


RPN::DivideByZero::DivideByZero() :
	std::runtime_error("Division by zero")
{}


RPN::EmptyStack::EmptyStack() :
	std::runtime_error("The stack is empty")
{}


RPN::UnfinishedCalculation::UnfinishedCalculation() :
	std::runtime_error("The stack is empty")
{}
