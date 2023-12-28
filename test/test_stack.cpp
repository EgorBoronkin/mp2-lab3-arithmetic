#include "stack.h"
#include <gtest.h>

TEST(stack, creating_stack_is_right)
{
	ASSERT_NO_THROW(Stack<int> stack(10));
}

TEST(stack, pushing_is_right)
{
	Stack<int> stack(10);
	ASSERT_NO_THROW(stack.push(1));
}

TEST(stack, no_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> stack(-1));
}

TEST(stack, getting_top_elem_is_right)
{
	Stack<int> stack(1);
	stack.push(1);
	EXPECT_EQ(1, stack.Top());
}

TEST(stack, over_limit_pushing_is_good)
{
	Stack<int> stack(1);
	stack.push(1);
	ASSERT_NO_THROW(stack.push(1));
}

TEST(stack, no_topping_on_empty_stack)
{
	Stack<int> stack(1);
	stack.push(1);
	stack.pop();
	ASSERT_ANY_THROW(stack.Top());
}

TEST(stack, popping_is_right)
{
	Stack<int> stack(1);
	stack.push(1);
	stack.push(2);

	stack.pop();
	EXPECT_EQ(1, stack.Top());
}

TEST(stack, popping_empty_stack)
{
	Stack<int> stack(1);
	stack.push(1);
	stack.pop();
	ASSERT_NO_THROW(stack.pop());
}

TEST(stack, empty_false_when_stack_is_full)
{
	Stack<int> stack(1);
	stack.push(1);
	EXPECT_NE(true, stack.isEmpty());
}

TEST(stack, empty_true_when_stack_is_empty)
{
	Stack<int> stack(1);
	stack.push(1);
	stack.pop();
	EXPECT_NE(false, stack.isEmpty());
}