#ifndef HEAP_INT_HPP
#define HEAP_INT_HPP

#include <iostream>

class HeapInt
{
	private:

		int * inteiro_;

	public:

		HeapInt ();
		HeapInt (HeapInt & i);
		HeapInt (int i);

		~HeapInt ();

		int * inteiro ();

		HeapInt & operator =  (int i);
		HeapInt & operator =  (HeapInt & i);
};

std::ostream & operator << (std::ostream & saida, HeapInt & i);
std::istream & operator >> (std::istream & entrada, HeapInt & i);
int            operator +  (HeapInt & a, HeapInt & b);
int            operator +  (HeapInt & a, const int b);
int            operator +  (const int a, HeapInt & b);
int            operator -  (HeapInt & a, HeapInt & b);
int            operator -  (HeapInt & a, const int b);
int            operator -  (const int a, HeapInt & b);
bool           operator == (HeapInt & a, HeapInt & b);

#endif

