#include "tformula.h"

#include <gtest.h>

TEST(TFormula, can_create_formula_with_size_less_than_255)
{
	EXPECT_NO_THROW(TFormula f("2-7+(5*2)"));
}

TEST(TFormula, cant_create_formula_with_size_greater_than_255)
{
	EXPECT_ANY_THROW(TFormula f("2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)*2-7+(5*2)"));
}

TEST(TFormula, can_check_formula)
{
	TFormula f("2-7+(5*2)");
	int arr[MaxLen];
	EXPECT_NO_THROW(f.FormulaChecker(arr, MaxLen));
}

TEST(TFormula, brackets_is_correct)
{
	TFormula f("(())()()(()(()))");
	int arr[MaxLen];
	EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(TFormula, brackets_in_formula_is_correct)
{
	TFormula f("((8-3)-5/((7+8)*9)-8)+25*7");
	int arr[MaxLen];
	EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(TFormula, brackets_is_uncorrect)
{
	TFormula f("(())()()(((()(()))");
	int arr[MaxLen];
	EXPECT_NE(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(TFormula, brackets_in_formula_is_uncorrect)
{
	TFormula f("(((8-3)-5/((7+8)*9)-8)+25*7");
	int arr[MaxLen];
	EXPECT_NE(f.FormulaChecker(arr, MaxLen), 0);
}

TEST(TFormula, number_of_errors_is_correct_1)
{
	TFormula f("(())()()(((()(()))");
	int arr[MaxLen];
	EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 2);
}

TEST(TFormula, number_of_errors_is_correct_2)
{
	TFormula f("(((8-3)-5/((7+8)*9)-8)+25*7");
	int arr[MaxLen];
	EXPECT_EQ(f.FormulaChecker(arr, MaxLen), 1);
}

TEST(TFormula, can_convert_correct_formula)
{
	TFormula f("((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_NO_THROW(f.FormulaConverter());
}

TEST(TFormula, cant_convert_uncorrect_formula)
{
	TFormula f("(((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_ANY_THROW(f.FormulaConverter());
}

TEST(TFormula, can_calculate_correct_formula)
{
	TFormula f("((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_NO_THROW(f.FormulaCalculator());
}

TEST(TFormula, cant_calculate_uncorrect_formula)
{
	TFormula f("(((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_ANY_THROW(f.FormulaCalculator());
}

TEST(TFormula, calculator_works_right)
{
	TFormula f("((8-3)-5/((7+8)*9)-8)+25*7");
	EXPECT_EQ((int)f.FormulaCalculator(), 171);
}
/*-----------------------------------14--------------------------------------*/
