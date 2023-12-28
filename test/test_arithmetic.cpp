#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, is_working)
{
	Arithmetic A("5+5*5");
	EXPECT_EQ(A.Execution().first, 30);
}

TEST(arithmetic, changing_priority_is_right)
{
	Arithmetic A("(5+6)*4");
	EXPECT_EQ(A.Execution().first, 44);

}

TEST(arithmetic, can_work_with_float)
{
	Arithmetic A("5.5+5*5");
	EXPECT_EQ(A.Execution().first, 30.5);
}

TEST(arithmetic, can_work_with_negative)
{
	Arithmetic A("-5+5*5");
	EXPECT_EQ(A.Execution().first, 20);
}

TEST(arithmetic, float_multiplication_is_right)
{
	Arithmetic A("5+5.5*6");
	EXPECT_EQ(A.Execution().first, 38);
}

TEST(arithmetic, negative_multiplication_is_right)
{
	Arithmetic A("5+(-5)*5");
	EXPECT_EQ(A.Execution().first, -10);
}

TEST(arithmetic, not_too_many_openning_brackets)
{
	Arithmetic A("(((((10+5)*15+13)*78(+(15*5-5.5)/10");

	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, not_too_many_closing_brackets)
{
	Arithmetic A("(5+10)*5)+15)*10+(10*10-5.5)/70))");

	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, no_dividing_by_0)
{
	Arithmetic A("5+5/0");
	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, no_wrong_lexem)
{
	Arithmetic A("((5+10)_15+10)*15+(75_15-5.5)/10");
	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, no_lexem_without_numbers)
{
	Arithmetic A("((5+20)*15+5)*10+5++(25*15-5.5)/10");
	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, dividing_is_rigt)
{
	Arithmetic A("15+25/5");
	double a = 15;
	double b = 25;
	double c = 5;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, x);
}

TEST(arithmetic, can_work_with_float)
{
	Arithmetic A("2+3.1/4");
	double a = 2;
	double b = 3.1;
	double c = 4;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, x);
}

TEST(arithmetic, dividing_by_negative_is_right)
{
	Arithmetic A("2+(-3)/4");
	double a = 2;
	double b = -3;
	double c = 4;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, x);
}

