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

		BinaryShadowExpression<T>* getOpe() const { return operatoor; };

	private:
		BinaryExpression<T>* operatoor;
		Expression<T>* left;
		Expression<T>* right;
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		if (operatoor != NULL)
			return operatoor->evaluate(_left, _right);
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
