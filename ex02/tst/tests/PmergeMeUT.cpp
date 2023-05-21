#include "Log.hpp"

#include "PmergeMeUT.hpp"

PmergeMeUT::PmergeMeUT() :
	flt::Testable< PmergeMeUT >("PmergeMe"),
	PmergeMe()
{
	REGISTER(PmergeMeUT, test_empty)
	REGISTER(PmergeMeUT, test_single)
	REGISTER(PmergeMeUT, test_double1)
	REGISTER(PmergeMeUT, test_double2)
	REGISTER(PmergeMeUT, test_multi1)
	REGISTER(PmergeMeUT, test_multi2)
	REGISTER(PmergeMeUT, test_multi3)
	REGISTER(PmergeMeUT, test_multi4)
}


void
PmergeMeUT::test_empty()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_empty


void
PmergeMeUT::test_single()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement(1))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_single


void
PmergeMeUT::test_double1()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement("1 2"))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_double1


void
PmergeMeUT::test_double2()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement("2 1"))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_double2


void
PmergeMeUT::test_multi1()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement("2 1 3 5 8 7"))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_multi1


void
PmergeMeUT::test_multi2()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement("3 8 7 6 10 4 5 9 2 1"))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_multi2


void
PmergeMeUT::test_multi3()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement("7 5 17 15 9 18 4 8 16 6 2 1 3 14 20 11 10 12 13 19"))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_multi3


void
PmergeMeUT::test_multi4()
{
	ASSERT_NOTHROW(this->clear())
	ASSERT_NOTHROW(this->addElement(
		"35 38 14 36 13 41 40 31 48 1 34 26 24 37 22 32 23 50 2 9 25 5 46 30 15 19 45 21 12 27 8 42 44 11 17 7 47 3 43 39 20 29 6 16 4 33 28 10 49 18"))
	ASSERT_NOTHROW(this->sort())
	for (size_t i = 1; i < this->_vec.size(); i++) {
		ASSERT(this->_vec[i - 1] <= this->_vec[i])
	}
	for (size_t i = 1; i < this->_deq.size(); i++) {
		ASSERT(this->_deq[i - 1] <= this->_deq[i])
	}
}	// PmergeMeUT::test_multi4
