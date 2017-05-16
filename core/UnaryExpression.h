#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

namespace core
{
	template <class T>
	class UnaryExpression {

	public:
		UnaryExpression() {};
		virtual ~UnaryExpression() {};

		virtual T evaluate(const Expression<T>*) const = 0;
	};
}

#endif