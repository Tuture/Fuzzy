#ifndef IS_GAUSS_H
#define IS_GAUSS_H

#include <math.h>  

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"
#include "../core/NullException.h"
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
	T IsGauss<T>::evaluate(const Expression<T>* _exp) const {
		if (_exp != NULL)
		return exp( (-1 * pow(_exp->evaluate() -c, 2)) / (2 * pow(o, 2)) );
		throw NullException("Expression is null!");
	};
}
#endif