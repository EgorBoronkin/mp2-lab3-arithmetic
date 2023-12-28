#include "stack.h"
#include <gtest.h>

TEST(stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> st(10));
}

TEST(stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-1));
}

TEST(stack, can_push_element)
{
	Stack<int> st(10);
	ASSERT_NO_THROW(st.push(1));
}

TEST(stack, can_push_element_over_limit)
{
	Stack<int> st(1);
	st.push(1);
	ASSERT_NO_THROW(st.push(1));
}

TEST(stack, can_get_top_element)
{
	Stack<int> st(1);
	st.push(1);
	EXPECT_EQ(1, st.Top());
}

TEST(stack, cant_top_on_empty_stack)
{
	Stack<int> st(1);
	st.push(1);
	st.pop();
	ASSERT_ANY_THROW(st.Top());
}

TEST(stack, can_pop_element)
{
	Stack<int> st(1);
	st.push(1);
	st.push(2);

	st.pop();
	EXPECT_EQ(1, st.Top());
}

TEST(stack, can_pop_empty_stack)
{
	Stack<int> st(1);
	st.push(1);
	st.pop();
	ASSERT_NO_THROW(st.pop());
}

TEST(stack, empty_show_flase_on_full_stack)
{
	Stack<int> st(1);
	st.push(1);
	EXPECT_NE(true, st.isEmpty());
}

TEST(stack, empty_show_true_on_empty_stack)
{
	Stack<int> st(1);
	st.push(1);
	st.pop();
	EXPECT_NE(false, st.isEmpty());
}