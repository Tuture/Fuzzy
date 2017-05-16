#ifndef IS_GAUSS_H
#define IS_GAUSS_H

#include <math.h>  

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"
#include "../fuzzy/Operators.h"

namespace fuzzy {
	using namespace core;

	template <class T>
	class IsGauss : public Is<T> {

	public:
		IsGauss() {};
		IsGauss(T _o, T _c) : o(_o), c(_c) {};
		virtual ~IsGauss() {};

		virtual T evaluate(const Expression<T>*) const;

	private:
		T o, c; // o : teta, c : center
	};

	template <class T>
	T IsGauss<T>::evaluate(const Expression<T>* xExp) const {
		if (xExp == NULL) throw NullException("Null expression !!!");
		T x = xExp->evaluate();
		return exp( (-1 * pow(x-c, 2)) / (2 * pow(o, 2)) );
	};
}
#endif