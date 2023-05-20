#include <limits>

#include "Log.hpp"

#include "RPNUT.hpp"

RPNUT::RPNUT() :
	flt::Testable< RPNUT >("RPN"),
	RPN()
{
	REGISTER(RPNUT, test_empty)

	REGISTER(RPNUT, test_single_0)
	REGISTER(RPNUT, test_single_1)
	REGISTER(RPNUT, test_single_2)
	REGISTER(RPNUT, test_single_3)
	REGISTER(RPNUT, test_single_4)
	REGISTER(RPNUT, test_single_5)
	REGISTER(RPNUT, test_single_6)
	REGISTER(RPNUT, test_single_7)
	REGISTER(RPNUT, test_single_8)
	REGISTER(RPNUT, test_single_9)

	REGISTER(RPNUT, test_double_digits)
	REGISTER(RPNUT, test_add_neo)
	REGISTER(RPNUT, test_sub_neo)
	REGISTER(RPNUT, test_mul_neo)
	REGISTER(RPNUT, test_div_neo)

	REGISTER(RPNUT, test_add_single)
	REGISTER(RPNUT, test_add_double1)
	REGISTER(RPNUT, test_add_double2)
	REGISTER(RPNUT, test_sub_single)
	REGISTER(RPNUT, test_sub_double1)
	REGISTER(RPNUT, test_sub_double2)
	REGISTER(RPNUT, test_mul_single)
	REGISTER(RPNUT, test_mul_double1)
	REGISTER(RPNUT, test_mul_double2)
	REGISTER(RPNUT, test_div_single)
	REGISTER(RPNUT, test_div_double1)
	REGISTER(RPNUT, test_div_double2)

	REGISTER(RPNUT, test_subject1)
	REGISTER(RPNUT, test_subject2)
	REGISTER(RPNUT, test_subject3)
	REGISTER(RPNUT, test_subject4)

	REGISTER(RPNUT, test_easy1)
	REGISTER(RPNUT, test_easy2)
	REGISTER(RPNUT, test_easy3)
	REGISTER(RPNUT, test_easy4)
	REGISTER(RPNUT, test_easy5)
	REGISTER(RPNUT, test_easy6)
	REGISTER(RPNUT, test_easy7)
	REGISTER(RPNUT, test_easy8)
	REGISTER(RPNUT, test_easy9)
	REGISTER(RPNUT, test_easy10)

	REGISTER(RPNUT, test_medium1)
	REGISTER(RPNUT, test_medium2)
	REGISTER(RPNUT, test_medium3)
	REGISTER(RPNUT, test_medium4)
	REGISTER(RPNUT, test_medium5)
	REGISTER(RPNUT, test_medium6)
	REGISTER(RPNUT, test_medium7)
	REGISTER(RPNUT, test_medium8)
	REGISTER(RPNUT, test_medium9)
	REGISTER(RPNUT, test_medium10)

	REGISTER(RPNUT, test_hard1)
	REGISTER(RPNUT, test_hard2)
	REGISTER(RPNUT, test_hard3)
	REGISTER(RPNUT, test_hard4)
	REGISTER(RPNUT, test_hard5)
	REGISTER(RPNUT, test_hard6)
	REGISTER(RPNUT, test_hard7)
	REGISTER(RPNUT, test_hard8)
	REGISTER(RPNUT, test_hard9)
	REGISTER(RPNUT, test_hard10)
}


void
RPNUT::test_empty()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add(""));
	ASSERT_THROW(this->getResult(), RPN::EmptyStack);
}	// RPNUT::test_empty


void
RPNUT::test_single_0()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("0"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 0, 0.000000001)
}	// RPNUT::test_single_0


void
RPNUT::test_single_1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("1"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 1, 0.000000001)
}	// RPNUT::test_single_1


void
RPNUT::test_single_2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("2"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 2, 0.000000001)
}	// RPNUT::test_single_2


void
RPNUT::test_single_3()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("3"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 3, 0.000000001)
}	// RPNUT::test_single_3


void
RPNUT::test_single_4()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 4, 0.000000001)
}	// RPNUT::test_single_4


void
RPNUT::test_single_5()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("5"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 5, 0.000000001)
}	// RPNUT::test_single_5


void
RPNUT::test_single_6()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("6"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 6, 0.000000001)
}	// RPNUT::test_single_6


void
RPNUT::test_single_7()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("7"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 7, 0.000000001)
}	// RPNUT::test_single_7


void
RPNUT::test_single_8()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 8, 0.000000001)
}	// RPNUT::test_single_8


void
RPNUT::test_single_9()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("9"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 9, 0.000000001)
}	// RPNUT::test_single_9


void
RPNUT::test_double_digits()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_THROW(this->add("42"), RPN::BigNumError);
}	// RPNUT::test_double_digits


void
RPNUT::test_add_neo()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_THROW(this->add("1 +"), RPN::NotEnoughOperands);
}	// RPNUT::test_add_neo


void
RPNUT::test_sub_neo()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_THROW(this->add("1 -"), RPN::NotEnoughOperands);
}	// RPNUT::test_sub_neo


void
RPNUT::test_mul_neo()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_THROW(this->add("1 *"), RPN::NotEnoughOperands);
}	// RPNUT::test_mul_neo


void
RPNUT::test_div_neo()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_THROW(this->add("1 /"), RPN::NotEnoughOperands);
}	// RPNUT::test_div_neo


void
RPNUT::test_add_single()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 9, 0.000000001)
}	// RPNUT::test_add_single


void
RPNUT::test_add_double1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 + 3 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 12, 0.000000001)
}	// RPNUT::test_add_double1


void
RPNUT::test_add_double2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 3 + +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 12, 0.000000001)
}	// RPNUT::test_add_double2


void
RPNUT::test_sub_single()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -1, 0.000000001)
}	// RPNUT::test_sub_single


void
RPNUT::test_sub_double1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 - 3 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -4, 0.000000001)
}	// RPNUT::test_sub_double1


void
RPNUT::test_sub_double2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 3 - -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 2, 0.000000001)
}	// RPNUT::test_sub_double2


void
RPNUT::test_mul_single()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 20, 0.000000001)
}	// RPNUT::test_mul_single


void
RPNUT::test_mul_double1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 * 3 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 60, 0.000000001)
}	// RPNUT::test_mul_double1


void
RPNUT::test_mul_double2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 5 3 * *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 60, 0.000000001)
}	// RPNUT::test_mul_double2


void
RPNUT::test_div_single()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 2 /"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 4, 0.000000001)
}	// RPNUT::test_div_single


void
RPNUT::test_div_double1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 2 / 2 /"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 2, 0.000000001)
}	// RPNUT::test_div_double1


void
RPNUT::test_div_double2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 2 2 / /"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 8, 0.000000001)
}	// RPNUT::test_div_double2


void
RPNUT::test_subject1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 9 * 9 - 9 - 9 - 4 - 1 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 42, 0.000000001)
}	// RPNUT::test_subject1


void
RPNUT::test_subject2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("7 7 * 7 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 42, 0.000000001)
}	// RPNUT::test_subject2


void
RPNUT::test_subject3()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("1 2 * 2 / 2 * 2 4 - +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 0, 0.000000001)
}	// RPNUT::test_subject3


void
RPNUT::test_subject4()
{
	ASSERT_NOTHROW(this->clear());
	ASSERT_THROW(this->add("(1 + 1)"), std::invalid_argument);
}	// RPNUT::test_subject4


void
RPNUT::test_easy1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("5 2 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 7, 0.000000001)
}	// RPNUT::test_easy1


void
RPNUT::test_easy2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("3 4 + 2 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 14, 0.000000001)
}	// RPNUT::test_easy2


void
RPNUT::test_easy3()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 2 / 4 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 16, 0.000000001)
}	// RPNUT::test_easy3


void
RPNUT::test_easy4()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("9 1 - 3 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 24, 0.000000001)
}	// RPNUT::test_easy4


void
RPNUT::test_easy5()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("7 2 + 3 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 6, 0.000000001)
}	// RPNUT::test_easy5


void
RPNUT::test_easy6()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 2 * 5 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 13, 0.000000001)
}	// RPNUT::test_easy6


void
RPNUT::test_easy7()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("6 3 / 2 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 4, 0.000000001)
}	// RPNUT::test_easy7


void
RPNUT::test_easy8()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("9 5 - 2 /"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 2, 0.000000001)
}	// RPNUT::test_easy8


void
RPNUT::test_easy9()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("3 1 + 4 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 16, 0.000000001)
}	// RPNUT::test_easy9


void
RPNUT::test_easy10()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 2 / 4 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 8, 0.000000001)
}	// RPNUT::test_easy10


void
RPNUT::test_medium1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 4 2 / 1 5 * + -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 1, 0.000000001)
}	// RPNUT::test_medium1


void
RPNUT::test_medium2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("3 2 1 + 4 * + 5 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 10, 0.000000001)
}	// RPNUT::test_medium2


void
RPNUT::test_medium3()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("9 2 7 * 3 / - 6 1 - *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 65 / 3.0, 0.000000001)
}	// RPNUT::test_medium3


void
RPNUT::test_medium4()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("5 7 4 3 - * + 6 1 - /"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 12 / 5.0, 0.000000001)
}	// RPNUT::test_medium4


void
RPNUT::test_medium5()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("2 3 6 * 1 - + 4 2 + / 5 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -11 / 6.0, 0.000000001)
}	// RPNUT::test_medium5


void
RPNUT::test_medium6()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 8 3 * 2 / 1 5 + * - 7 +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -61, 0.000000001)
}	// RPNUT::test_medium6


void
RPNUT::test_medium7()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("9 5 3 2 + * 4 - 1 6 + * -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -138, 0.000000001)
}	// RPNUT::test_medium7


void
RPNUT::test_medium8()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("7 3 9 2 * 1 - / + 8 - 5 *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -70 / 17.0, 0.000000001)
}	// RPNUT::test_medium8


void
RPNUT::test_medium9()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("6 1 + 2 8 3 - * + 4 / 7 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -11 / 4.0, 0.000000001)
}	// RPNUT::test_medium9


void
RPNUT::test_medium10()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("2 3 + 4 5 + * 6 7 + / 8 -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -59 / 13.0, 0.000000001)
}	// RPNUT::test_medium10


void
RPNUT::test_hard1()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("5 3 1 8 * + 4 - 6 2 9 + * - 7 1 - 3 / 5 + 2 * - 4 8 2 + - + +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -74, 0.000000001)
}	// RPNUT::test_hard1


void
RPNUT::test_hard2()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("7 2 * 4 8 + 1 - 3 5 6 + * - 9 4 - 3 3 / 5 + 2 * - 1 3 7 + * + + +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -5, 0.000000001)
}	// RPNUT::test_hard2


void
RPNUT::test_hard3()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("9 2 + 3 6 4 * + 1 - 8 2 5 + * - 7 4 - 3 / 5 + 2 * - 1 8 2 + * - *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -572, 0.000000001)
}	// RPNUT::test_hard3


void
RPNUT::test_hard4()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("3 8 4 * 7 + 2 - 5 1 9 + * - 6 1 - 3 / 5 + 2 * - 4 5 7 + * + *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 65, 0.000000001)
}	// RPNUT::test_hard4


void
RPNUT::test_hard5()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("6 3 * 2 7 + 5 - 1 + 4 2 8 + * - 9 5 - 3 / 5 + 2 * - 1 7 3 + * - *"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -1038, 0.000000001)
}	// RPNUT::test_hard5


void
RPNUT::test_hard6()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("8 4 + 1 9 * 2 - 3 6 7 + * - 5 2 - 3 / 5 + 2 * - 7 2 6 + * + -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 0, 0.000000001)
}	// RPNUT::test_hard6


void
RPNUT::test_hard7()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("2 6 7 + 4 - 9 3 * 8 + 5 1 2 + * - 7 4 - 3 / 5 + 2 * - 1 9 6 + * + - -"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 16, 0.000000001)
}	// RPNUT::test_hard7


void
RPNUT::test_hard8()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("1 9 3 * 7 + 2 - 5 8 4 + * - 6 1 - 3 / 5 + 2 * - 4 2 9 + * + /"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 3.0 / 8.0, 0.000000001)
}	// RPNUT::test_hard8


void
RPNUT::test_hard9()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("4 2 9 + 1 - 7 3 * 5 + 8 6 2 + * - 9 4 - 3 / 5 + 2 * - 1 5 3 + * - / +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, 341.0 / 89.0, 0.000000001)
}	// RPNUT::test_hard9


void
RPNUT::test_hard10()
{
	double ret;

	ASSERT_NOTHROW(this->clear());
	ASSERT_NOTHROW(this->add("5 1 2 + 6 - 3 7 9 + * 4 - 8 2 5 + * - 6 4 - 3 / 5 + 2 * - 9 2 1 + * + * +"));
	ASSERT_NOTHROW(ret = this->getResult());
	ASSERT_FEQ(ret, -6, 0.000000001)
}	// RPNUT::test_hard10
