#ifndef ORMAX_H
#define ORMAX_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;

	template <class T>
	class OrMax : public Or<T>
	{
	public:
		OrMax() {};
		virtual ~OrMax() {};
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T OrMax<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		return (_left->evaluate() >= _right->evaluate()) ? _left->evaluate() : _right->evaluate();
	}
}

#endif