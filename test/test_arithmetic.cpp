#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, can_do_arithnetic)
{
	Arithmetic A("2+3*4");
	EXPECT_EQ(A.Execution().first, 14);
}

TEST(arithmetic, brackets_change_priority)
{
	Arithmetic A("(2+3)*4");
	EXPECT_EQ(A.Execution().first, 20);
}

TEST(arithmetic, can_add_negative_number)
{
	Arithmetic A("-2+3*4");
	EXPECT_EQ(A.Execution().first, 10);
}

TEST(arithmetic, can_multiply_negative_number)
{
	Arithmetic A("2+(-3)*4");
	EXPECT_EQ(A.Execution().first, -10);
}

TEST(arithmetic, can_add_float_number)
{
	Arithmetic A("2.1+3*4");
	EXPECT_EQ(A.Execution().first, 14.1);
}

TEST(arithmetic, can_multiply_float_number)
{
	Arithmetic A("2+3.1*4");
	EXPECT_EQ(A.Execution().first, 14.4);
}

TEST(arithmetic, can_divide_number)
{
	Arithmetic A("2+3/4");
	double a = 2;
	double b = 3;
	double c = 4;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, x);
}

TEST(arithmetic, can_divide_float_number)
{
	Arithmetic A("2+3.1/4");
	double a = 2;
	double b = 3.1;
	double c = 4;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, x);
}

TEST(arithmetic, can_divide_negative_number)
{
	Arithmetic A("2+(-3)/4");
	double a = 2;
	double b = -3;
	double c = 4;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, x);
}

TEST(arithmetic, ULTRAPRIMER)
{
	Arithmetic A("((3+4)*2+7)*8+(7*3-2.1)/15");
	double a = 2;
	double b = -3;
	double c = 4;
	double x = a + b / c;
	EXPECT_EQ(A.Execution().first, ((3 + 4) * 2 + 7) * 8 + (7 * 3 - 2.1) / 15);
}

TEST(arithmetic, error_then_too_many_open_brackets)
{
	Arithmetic A("(((3+4)*2+7)*8(+(7*3-2.1)/15");

	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, error_then_too_many_close_brackets)
{
	Arithmetic A("((3+4)*2)+7)*8+(7*3-2.1)/15))");

	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, error_then_wrong_lexema)
{
	Arithmetic A("((3+4)_2+7)*8+(7_3-2.1)/15");
	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, error_then_lexems_without_numbers)
{
	Arithmetic A("((3+4)*2+7)*8+2++(7*3-2.1)/15");
	EXPECT_EQ(A.Execution().second, -1);
}

TEST(arithmetic, error_then_divide_by_zero)
{
	Arithmetic A("2+3/0");
	EXPECT_EQ(A.Execution().second, -1);
}