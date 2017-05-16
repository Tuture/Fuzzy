#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

namespace core
{
	template <class T>
	class BinaryExpression {
	public:
		BinaryExpression() {};
		virtual ~BinaryExpression() {};

		virtual T evaluate(const Expression<T>*, const Expression<T>*) const = 0;
	};

}

#endif