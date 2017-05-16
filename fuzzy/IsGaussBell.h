#ifndef IS_GAUSSBELL_H
#define IS_GAUSSBELL_H

#include <math.h>  
#include <cmath>

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"
#include "../core/NullException.h"
#include "../fuzzy/Operators.h"

namespace fuzzy {
	using namespace core;

	template <class T>
	class IsGaussBell : public Is<T> {
	public:
		IsGaussBell() {};
		IsGaussBell(T _a, T _b, T _c) : a(_a), b(_b), c(_c) {};
		virtual ~IsGaussBell() {};

		virtual T evaluate(const Expression<T>*) const;

	private:
		T a, b, c;
	};

	template <class T>
	T IsGaussBell<T>::evaluate(const Expression<T>* _exp) const {
		if (_exp != NULL)
			return 1 / (1 + pow( abs( (_exp->evaluate() - c) / a ), 2 * b));
		throw NullException("Expression is null!");
	};
}
#endif