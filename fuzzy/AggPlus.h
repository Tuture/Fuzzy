#ifndef AGG_PLUS_H
#define AGG_PLUS_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class AggPlus : public Agg<T> {

	public:
		AggPlus() {};
		virtual ~AggPlus() {};
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T AggPlus<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		return _left->evaluate() + _right->evaluate();
	}
}

#endif