#ifndef OPERATORS_H
#define OPERATORS_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy {
	using namespace core;

	template <class T>
	class And : public BinaryExpression<T> {};

	template <class T>
	class Agg : public BinaryExpression<T> {};

	template <class T>
	class Is : public UnaryExpression<T> {};

	template <class T>
	class Not : public UnaryExpression<T> {};

	template <class T>
	class Or : public BinaryExpression<T> {};

	template <class T>
	class Then : public BinaryExpression<T> {};
}
#endif