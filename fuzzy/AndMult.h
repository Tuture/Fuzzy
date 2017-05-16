#ifndef AND_MULT_H
#define AND_MULT_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class AndMult : public And<T> {

	public:
		AndMult() {};
		virtual ~AndMult() {};
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T AndMult<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		return _left->evaluate()*_right->evaluate();
	}
}

#endif