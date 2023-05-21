#include <cctype>
#include <sstream>
#include <stdexcept>

#include "Log.hpp"
#include "Timer.hpp"

#include "PmergeMe.hpp"


void
PmergeMe::sortVec(size_t start, size_t end, size_t k)
{
	if (end - start + 1 <= k) {
		this->insertVec(start, end);
	} else if (end - start > 1) {
		this->sortVec(start, start + ((end - start) / 2));
		this->sortVec(start + ((end - start) / 2) + 1, end);
		this->mergeVec(start, end);
	}
}	// PmergeMe::sortVec


void
PmergeMe::insertVec(size_t start, size_t end)
{
	unsigned int tmp;

	for (size_t i = start + 1; i <= end; i++) {
		for (size_t j = i; j > start; j--) {
			if (this->_vec[j - 1] > this->_vec[j]) {
				tmp = this->_vec[j];
				this->_vec[j] = this->_vec[j - 1];
				this->_vec[j - 1] = tmp;
			} else {
				break;
			}
		}
	}
}	// PmergeMe::insertVec


void
PmergeMe::mergeVec(size_t start, size_t end)
{
	std::vector< unsigned int > tmp;
	size_t split = start + ((end - start) / 2) + 1;
	size_t small = start, big = split, i = 0;


	// merge
	while (small < split && big <= end) {
		if (this->_vec[small] < this->_vec[big]) {
			tmp.push_back(this->_vec[small++]);
		} else {
			tmp.push_back(this->_vec[big++]);
		}
	}
	// move unmerged to tmp
	while (small < split) {
		tmp.push_back(this->_vec[small++]);
	}
	while (big <= end) {
		tmp.push_back(this->_vec[big++]);
	}
	// move tmp to vec
	while (i < end - start + 1) {
		this->_vec[start + i] = tmp[i];
		i++;
	}
}	// PmergeMe::mergeVec


void
PmergeMe::sortDeq(size_t start, size_t end, size_t k)
{
	if (end - start + 1 <= k) {
		this->insertDeq(start, end);
	} else if (end - start > 1) {
		this->sortDeq(start, start + ((end - start) / 2));
		this->sortDeq(start + ((end - start) / 2) + 1, end);
		this->mergeDeq(start, end);
	}
}	// PmergeMe::sortDeq


void
PmergeMe::insertDeq(size_t start, size_t end)
{
	unsigned int tmp;

	for (size_t i = start + 1; i <= end; i++) {
		for (size_t j = i; j > start; j--) {
			if (this->_deq[j - 1] > this->_deq[j]) {
				tmp = this->_deq[j];
				this->_deq[j] = this->_deq[j - 1];
				this->_deq[j - 1] = tmp;
			} else {
				break;
			}
		}
	}
}	// PmergeMe::insertVec


void
PmergeMe::mergeDeq(size_t start, size_t end)
{
	std::deque< unsigned int > tmp;
	size_t split = start + ((end - start) / 2) + 1;
	size_t small = start, big = split, i = 0;


	// merge
	while (small < split && big <= end) {
		if (this->_deq[small] < this->_deq[big]) {
			tmp.push_back(this->_deq[small++]);
		} else {
			tmp.push_back(this->_deq[big++]);
		}
	}
	// move unmerged to tmp
	while (small < split) {
		tmp.push_back(this->_deq[small++]);
	}
	while (big <= end) {
		tmp.push_back(this->_deq[big++]);
	}
	// move tmp to vec
	while (i < end - start + 1) {
		this->_deq[start + i] = tmp[i];
		i++;
	}
}	// PmergeMe::mergeVec


PmergeMe::PmergeMe() :
	_vec(),
	_deq()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe&
PmergeMe::operator=(const PmergeMe &other)
{
	this->_vec = other._vec;

	this->_deq = other._deq;

	return *this;
}	// PmergeMe::operator=


void
PmergeMe::addElement(unsigned int elem)
{
	this->_vec.push_back(elem);
	this->_deq.push_back(elem);
}	// PmergeMe::addElement


void
PmergeMe::addElement(const std::string &list)
{
	std::istringstream iss(list);
	int elem;

	while (!iss.eof()) {
		iss >> elem;
		if (iss.fail()) {
			throw std::runtime_error("Failed to extract int");
		}
		if (elem < 0) {
			throw std::runtime_error("Negative int encountered");
		}
		this->addElement(elem);
	}
}	// PmergeMe::addElement


void
PmergeMe::clear()
{
	this->_vec.clear();
	this->_deq.clear();
}	// PmergeMe::clear


std::string
PmergeMe::getData() const
{
	std::stringstream ss;

	for (PmergeMe::const_veciter it = this->_vec.begin(); it != this->_vec.end(); it++) {
		ss << *it;
		ss << " ";
	}

	return ss.str();
}	// PmergeMe::printVec


void
PmergeMe::printVec() const
{
	std::stringstream ss;

	for (PmergeMe::const_veciter it = this->_vec.begin(); it != this->_vec.end(); it++) {
		ss << *it;
		ss << " ";
	}

	LOG_INFO("Vec: " << ss.str());
}	// PmergeMe::printVec


void
PmergeMe::printDeq() const
{
	std::stringstream ss;

	for (PmergeMe::const_deqiter it = this->_deq.begin(); it != this->_deq.end(); it++) {
		ss << *it;
		ss << " ";
	}

	LOG_INFO("Vec: " << ss.str());
}	// PmergeMe::printVec


void
PmergeMe::sort()
{
	{
		FLT_TIME("Vector sorting:")
		if (this->_vec.size() > 1) {
			this->sortVec(0, this->_vec.size() - 1);
		}
	}
	{
		FLT_TIME("Deque sorting: ")
		if (this->_deq.size() > 1) {
			this->sortDeq(0, this->_deq.size() - 1);
		}
	}
}	// PmergeMe::sort
