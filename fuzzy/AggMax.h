#ifndef AGG_MAX_H
#define AGG_MAX_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class AggMax : public Agg<T> {

	public:
		AggMax() {};
		virtual ~AggMax() {};
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T AggMax<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		return (_left->evaluate() >= _right->evaluate()) ? _left->evaluate() : _right->evaluate();
	}
}

#endif