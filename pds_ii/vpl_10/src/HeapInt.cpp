#include "../include/HeapInt.hpp"
#include <iostream>

HeapInt::HeapInt() : inteiro_( new int(0) ) {}

HeapInt::HeapInt(HeapInt & i) : inteiro_( new int(*i.inteiro()) ) {}

HeapInt::HeapInt(int i) : inteiro_( new int(i) ) {}

HeapInt::~HeapInt() { delete inteiro_; }

HeapInt & HeapInt::operator = (int i) { delete inteiro_; inteiro_ = new int(i); return *this; }

HeapInt & HeapInt::operator = (HeapInt & i) { *inteiro_ = *i.inteiro(); return *this; }

int * HeapInt::inteiro()
{
	return inteiro_;
}

std::ostream & operator << (std::ostream & saida, HeapInt & i)   { return saida << *i.inteiro(); }
std::istream & operator >> (std::istream & entrada, HeapInt & i) { return entrada >> *i.inteiro(); }
int            operator +  (HeapInt & a, HeapInt & b)            { return *a.inteiro() + *b.inteiro(); }
int            operator +  (HeapInt & a, const int b)            { return *a.inteiro() + b; }
int            operator +  (const int a, HeapInt & b)            { return a + *b.inteiro(); }
bool           operator == (HeapInt & a, HeapInt & b)            { return *a.inteiro() == *b.inteiro(); }
int            operator -  (HeapInt & a, HeapInt & b)            { return *a.inteiro() - *b.inteiro(); }
int            operator -  (HeapInt & a, const int b)            { return *a.inteiro() - b; }
int            operator -  (const int a, HeapInt & b)            { return a - *b.inteiro(); }

