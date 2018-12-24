#include <iostream>

#include "tstack.h"

TStack::TStack(int Size)
{
	if (Size < 0) throw - 1;
	this->DataCount = 0;
	this->MemSize = Size;
	if (Size == 0)
	{
		this->pMem = NULL;
		this->MemType = MEM_RENTER;
	}
	else
	{
		this->pMem = new TElem[MemSize];
		this->MemType = MEM_HOLDER;
	}
	top = -1;
}/*-------------------------------------------------------------------------*/

void TStack::Put(const TData &Val)
{
	if (this->pMem == NULL)
	{
		this->SetRetCode(DataNoMem);
		return;
	}
	if (this->IsFull())
	{
		this->SetRetCode(DataFull);
		return;
	}
	++(this->DataCount);
	this->pMem[++top] = Val;
}/*-------------------------------------------------------------------------*/

TData TStack::Get()
{
	if (this->pMem == NULL)
	{
		this->SetRetCode(DataNoMem);
		throw -1;
	}
	if (this->IsEmpty())
	{
		this->SetRetCode(DataEmpty);
		throw -1;
	}
	--(this->DataCount);
	return this->pMem[top--];
}/*-------------------------------------------------------------------------*/

TData TStack::TopElem()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
		throw - 1;
	}
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		throw - 1;
	}
	return this->pMem[top];
}/*-------------------------------------------------------------------------*/

int TStack::IsValid()
{
	return this->GetRetCode();
}/*-------------------------------------------------------------------------*/

void TStack::Print()
{
	for (int i = 0; i <= top; i++)
		std::cout << (TData)pMem[i] << ' ';
}/*-------------------------------------------------------------------------*/
