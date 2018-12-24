#include "tstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_size)
{
	EXPECT_NO_THROW(TStack s(5));
}

TEST(TStack, can_create_stack_with_zero_size)
{
	EXPECT_NO_THROW(TStack s(0));
}

TEST(TStack, cant_create_stack_with_negative_size)
{
	EXPECT_ANY_THROW(TStack s(-5));
}

TEST(TStack, can_create_stack_without_size)
{
	EXPECT_NO_THROW(TStack s());
}

TEST(TStack, can_put_value_to_stack)
{
	TStack s(5);
	EXPECT_NO_THROW(s.Put(5));
}

TEST(TStack, cant_put_value_if_stack_is_full)
{
	TStack s(2);
	s.Put(1);
	s.Put(2);
	s.Put(3);
	EXPECT_NE(DataOK, s.GetRetCode());
}

TEST(TStack, can_get_value_from_stack)
{
	TStack s(5);
	s.Put(1);
	s.Put(2);
	s.Put(3);
	EXPECT_NO_THROW(s.Get());
}

TEST(TStack, get_value_from_stack_right)
{
	TStack s(5);
	s.Put(1);
	s.Put(2);
	s.Put(3);
	EXPECT_EQ(s.Get(), 3);
}

TEST(TStack, cant_get_value_from_stack_with_zero_size)
{
	TStack s(0);
	EXPECT_ANY_THROW(s.Get());
}

TEST(TStack, cant_get_value_from_empty_stack)
{
	TStack s(5);
	EXPECT_ANY_THROW(s.Get());
}

TEST(TStack, can_know_top_element)
{
	TStack s(5);
	s.Put(1);
	s.Put(2);
	s.Put(3);
	EXPECT_NO_THROW(s.TopElem());
}

TEST(TStack, cant_know_top_element_from_empty_stack)
{
	TStack s(5);
	EXPECT_ANY_THROW(s.TopElem());
}

TEST(TStack, cant_know_top_element_from_stack_with_zero_size)
{
	TStack s(0);
	EXPECT_ANY_THROW(s.TopElem());
}

TEST(TStack, top_element_give_right_value)
{
	TStack s(5);
	s.Put(1);
	s.Put(2);
	s.Put(3);
	EXPECT_EQ(s.TopElem(), 3);
}

TEST(TStack, top_element_not_delete_value_from_stack)
{
	TStack s(5);
	s.Put(1);
	s.Put(2);
	s.Put(3);
	s.TopElem();
	EXPECT_EQ(s.Get(), 3);
}

/*-----------------------------------15--------------------------------------*/