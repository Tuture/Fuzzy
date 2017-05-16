#ifndef AND_MIN_H
#define AND_MIN_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class AndMin : public And<T>
	{
	public:
		AndMin() {};
		virtual ~AndMin() {};
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		return (_left->evaluate() <= _right->evaluate()) ? _left->evaluate() : _right->evaluate();
	}
}

#endif