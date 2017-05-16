#ifndef IS_SIGMF_H
#define IS_SIGMF_H

#include <math.h>  

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"
#include "../core/NullException.h"
#include "../fuzzy/Operators.h"

namespace fuzzy {
	using namespace core;

	template <class T>
	class IsSigmf : public Is<T> {
	public:
		IsSigmf() {};
		IsSigmf(T _a, T _c) : a(_a), c(_c) {};
		virtual ~IsSigmf() {};

		virtual T evaluate(const Expression<T>*) const;

	private:
		T a, c; // a : alpha, c : center
	};

	template <class T>
	T IsSigmf<T>::evaluate(const Expression<T>* _exp) const {
		if (_exp != NULL)
			return 1 / (1 + exp( (-1 * a * (_exp->evaluate() - c))));
		throw NullException("Expression is null!");
	};
}
#endif