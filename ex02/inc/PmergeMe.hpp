#if !defined(PMERGEME_HPP)
#define PMERGEME_HPP

#include <deque>
#include <vector>

#include <string>

// vec
// deque
class PmergeMe
{
protected:
	typedef std::vector< unsigned int >::iterator veciter;
	typedef std::vector< unsigned int >::const_iterator const_veciter;
	typedef std::deque< unsigned int >::iterator deqiter;
	typedef std::deque< unsigned int >::const_iterator const_deqiter;

protected:
	std::vector< unsigned int > _vec;
	std::deque< unsigned int > _deq;

protected:
	void sortVec(size_t start, size_t end, size_t k = 2);
	void insertVec(size_t start, size_t end);
	void mergeVec(size_t start, size_t end);

	void sortDeq(size_t start, size_t end, size_t k = 2);
	void insertDeq(size_t start, size_t end);
	void mergeDeq(size_t start, size_t end);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe &other);

	void addElement(unsigned int);
	void addElement(const std::string &list);

	void clear();

	std::string getData() const;
	void printVec() const;
	void printDeq() const;

	void sort();
};	// class PmergeMe

#endif // PMERGEME_HPP
