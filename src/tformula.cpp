#include "tformula.h"
#include <stdio.h>

TFormula::TFormula(char *form)                             // конструктор
{
	for (int i = 0; i < MaxLen; i++)
	{
		Formula[i] = '\0';
		PostfixForm[i] = '\0';
	}
	int i = 0;
	while (form[i] != '\0')
	{
		if (i == MaxLen) throw - 1;
		Formula[i] = form[i];
		i++;
	}
}/*-------------------------------------------------------------------------*/

int TFormula::FormulaChecker(int Brackets[], int size)      // проверка корректности скобок
{
	int err = 0, n = 1, p = 0;
	TStack st[MaxLen];
	for (int i = 0; Formula[i] != '\0'; i++)
	{
		if (Formula[i] == '(' || Formula[i] == ')')
		{
			if (Formula[i] == '(')
			{
				st->Put(n);
				n++;
			}
			else
			{
				if (st->IsEmpty())
				{
					err++;
					Brackets[p++] = 0;
					Brackets[p++] = n;
					n++;
					continue;
				}
				Brackets[p++] = st->Get();
				Brackets[p++] = n;
				n++;
			}
		}
	}
	while (!st->IsEmpty())
	{
		err++;
		Brackets[p++] = st->Get();
		Brackets[p++] = 0;
	}
	return err;
}/*-------------------------------------------------------------------------*/

int TFormula::FormulaConverter()                           // преобразование в постфиксную форму
{ 
	int Br[MaxLen];
	if (this->FormulaChecker(Br, MaxLen)) throw - 1;
	TStack st(MaxLen);
	int i = 0, j = 0;
	while (Formula[i] != '\0')
	{
		switch (Formula[i])
		{
		case '1':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '2':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '3':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '4':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '5':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '6':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '7':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '8':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '9':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '0':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '.':
		{
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '(':
		{
			st.Put('(');
			break;		
		}
		case ')':
		{
			while (st.TopElem() != '(')
			{
				PostfixForm[j++] = ' ';
				PostfixForm[j++] = st.Get();
			}
			st.Get();
			break;
		}
		case '+':
		{
			PostfixForm[j++] = ' ';
			if (st.IsEmpty() || st.TopElem() == '(')
				st.Put('+');
			else
			{
				while (!st.IsEmpty() && st.TopElem() != '(')
				{
					PostfixForm[j++] = st.Get();
				}
				st.Put('+');
			}
			break;		
		}
		case '-':
		{
			PostfixForm[j++] = ' ';
			if (st.IsEmpty() || st.TopElem() == '(')
				st.Put('-');
			else
			{
				while (!st.IsEmpty() && st.TopElem() != '(')
				{
					PostfixForm[j++] = st.Get();
				}
				st.Put('-');
			}
			break;		
		}
		case '*':
		{
			PostfixForm[j++] = ' ';
			if (st.IsEmpty() || st.TopElem() == '(' || st.TopElem() == '+' || st.TopElem() == '-')
				st.Put('*');
			else
			{
				while (!st.IsEmpty() && st.TopElem() != '(' && st.TopElem() != '+' && st.TopElem() != '-')
				{
					PostfixForm[j++] = st.Get();
				}
				st.Put('*');
			}
			break;		
		}
		case '/':
		{
			PostfixForm[j++] = ' ';
			if (st.IsEmpty() || st.TopElem() == '(' || st.TopElem() == '+' || st.TopElem() == '-')
				st.Put('/');
			else
			{
				while (!st.IsEmpty() && st.TopElem() != '(' && st.TopElem() != '+' && st.TopElem() != '-')
				{
					PostfixForm[j++] = st.Get();
				}
				st.Put('/');
			}
			break;		
		}
		case ' ':
		{
			break;
		}
		default:
		{
			throw - 1;
		}
		}
	i++;
	}
	while (!st.IsEmpty())
	{
		if (st.TopElem() != '(')
		{
			PostfixForm[j++] = ' ';
			PostfixForm[j++] = st.Get();
		}
		else st.Get();
	}
	return 0;
}/*-------------------------------------------------------------------------*/

double TFormula::FormulaCalculator()                       // вычисление формулы
{
	if (this->PostfixForm[0] == '\0') this->FormulaConverter();
	double st[MaxLen];
	for (int x = 0; x < MaxLen; x++) st[x] = NULL;
	int i = 0, s = -1;
	double result = 0.0;
	while (PostfixForm[i] != '\0')
	{
		if (PostfixForm[i] == '-' || PostfixForm[i] == '+' || PostfixForm[i] == '*' || PostfixForm[i] == '/')
		{
			if (s < 1) throw - 1;
			double op1 = st[s - 1], op2 = st[s], res;
			switch (PostfixForm[i])
			{
			case '-':
			{
				res = op1 - op2;
				break;
			}
			case '+':
			{
				res = op1 + op2;
				break;
			}
			case '*':
			{
				res = op1 * op2;
				break;
			}
			case '/':
			{
				res = op1 / op2;
				break;
			}
			default:
				break;
			}
			st[s] = 0;
			s--;
			st[s] = res;
		}
		else
		{
			if (PostfixForm[i] == ' ')
			{
				i++;
				continue;
			}
			int f = 0, j = 1;
			int r = 0, e = 0;
			s++;
			st[s] = 0;
			while (PostfixForm[i] != ' ')
			{
				if (PostfixForm[i] == '.')
				{
					if (f) throw - 1;
					f = 1;
					e = r;
					r = 0;
					j = 1;
					i++;
					continue;
				}
				r = j * r + (PostfixForm[i] - '0');
				j *= 10;
				i++;
			}
			if (f)
				st[s] = r + 0.1 * e;
			else
				st[s] = r;
		}
		i++;
	}
	if (s > 0) throw - 1;
	result = st[0];
	return result;
}/*-------------------------------------------------------------------------*/
