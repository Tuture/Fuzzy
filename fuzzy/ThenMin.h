#ifndef THEN_MIN_H
#define THEN_MIN_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class ThenMin : public Then<T>
	{
	public:
		ThenMin() {};
		virtual ~ThenMin() {};
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T ThenMin<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		return (_left->evaluate() <= _right->evaluate()) ? _left->evaluate() : _right->evaluate();
	}
}

#endif