#if !defined(PMERGEMEUT_HPP)
#define PMERGEMEUT_HPP

#include "PmergeMe.hpp"
#include "Testable.tpp"

class PmergeMeUT :
	public flt::Testable< PmergeMeUT >, PmergeMe
{
public:
	PmergeMeUT();

	void test_empty();
	void test_single();
	void test_double1();
	void test_double2();
	void test_multi1();
	void test_multi2();
	void test_multi3();
	void test_multi4();
};	// class PmergeMeUT

#endif // PMERGEMEUT_HPP
