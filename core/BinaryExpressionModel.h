#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H

#include "NullException.h"

namespace core
{
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	public:
		BinaryExpressionModel() {};
		BinaryExpressionModel(BinaryExpression<T>* _operatoor, Expression<T>* _left, Expression<T>* _right) : operatoor(_operatoor), left(_left), right(_right) {};
		virtual ~BinaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;

	private:
		BinaryExpression<T>* operatoor;
		Expression<T>* left;
		Expression<T>* right;
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const
	{
		if (operatoor != NULL)
			return operatoor->evaluate(l, r);
		throw new NullException("Operatoor is null!");
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if (left != NULL && right != NULL)
			return evaluate(left, right);
		throw new NullException("Left or Right expression is null!");
	}
}

#endif
