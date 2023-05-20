#if !defined(RPNUT_HPP)
#define RPNUT_HPP

#include "RPN.hpp"
#include "Testable.tpp"

class RPNUT :
	public flt::Testable< RPNUT >, RPN
{
public:
	RPNUT();

	void test_empty();

	void test_single_0();
	void test_single_1();
	void test_single_2();
	void test_single_3();
	void test_single_4();
	void test_single_5();
	void test_single_6();
	void test_single_7();
	void test_single_8();
	void test_single_9();

	void test_double_digits();
	void test_add_neo();
	void test_sub_neo();
	void test_mul_neo();
	void test_div_neo();

	void test_add_single();
	void test_add_double1();
	void test_add_double2();
	void test_sub_single();
	void test_sub_double1();
	void test_sub_double2();
	void test_mul_single();
	void test_mul_double1();
	void test_mul_double2();
	void test_div_single();
	void test_div_double1();
	void test_div_double2();

	void test_subject1();
	void test_subject2();
	void test_subject3();
	void test_subject4();

	void test_easy1();
	void test_easy2();
	void test_easy3();
	void test_easy4();
	void test_easy5();
	void test_easy6();
	void test_easy7();
	void test_easy8();
	void test_easy9();
	void test_easy10();

	void test_medium1();
	void test_medium2();
	void test_medium3();
	void test_medium4();
	void test_medium5();
	void test_medium6();
	void test_medium7();
	void test_medium8();
	void test_medium9();
	void test_medium10();

	void test_hard1();
	void test_hard2();
	void test_hard3();
	void test_hard4();
	void test_hard5();
	void test_hard6();
	void test_hard7();
	void test_hard8();
	void test_hard9();
	void test_hard10();
};	// class RPNUT

#endif // RPNUT_HPP
