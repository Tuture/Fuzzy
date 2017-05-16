#ifndef IS_TRAPEZE_H
#define IS_TRAPEZE_H

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"
#include "../core/NullException.h"
#include "../fuzzy/Operators.h"

namespace fuzzy {
	using namespace core;

	template <class T>
	class IsTrapeze : public Is<T> {
	public :
		IsTrapeze() {};
		IsTrapeze(T _min, T _mid1, T _mid2, T _max) : min(_min), mid1(_mid1), mid2(_mid2), max(_max) {};
		virtual ~IsTrapeze() {};

		virtual T evaluate(const Expression<T>*) const;

	private :
		T min, mid1, mid2, max;
	};

	template <class T>
	T IsTrapeze<T>::evaluate(const Expression<T>* value) const {
		if (value != NULL) {
			T t = value->evaluate();
			if (t <= min || t >= max) return NULL;
			if (t < mid1) return (t - min) / (mid1 - min);
			if (t >= mid1 && t <= mid2) return 1;
			if (t > mid2) return (max - t) / (max - mid2);
		}
		throw NullException("Value is null!");
	};
}
#endif