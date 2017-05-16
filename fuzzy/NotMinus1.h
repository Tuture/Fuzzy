#ifndef NOTMINUS_H
#define NOTMINUS_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;

	template <class T>
	class NotMinus1 : public Not<T>
	{
	public:
		NotMinus1() {};
		virtual ~NotMinus1() {};
		virtual T evaluate(const Expression<T>*) const;
	};

	template <class T>
	T NotMinus1<T>::evaluate(const Expression<T>* o) const
	{
		T m = -(o->evaluate());
		return m;
	}
}

#endif