#ifndef THEN_MULT_H
#define THEN_MULT_H

#include "Operators.h"

namespace fuzzy
{
	template <class T>
	class ThenMult : public Then<T>
	{
	public:
		ThenMult() {};
		virtual ~ThenMult() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T ThenMult<T>::evaluate(core::Expression<T>* _left, core::Expression<T>* _right) const
	{
		return _left->evaluate() * _right->evaluate();
	}
}

#endif