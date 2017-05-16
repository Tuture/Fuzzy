#ifndef UNARY_EXPRESSION_MODEL_H
#define UNARY_EXPRESSION_MODEL_H

#include "NullException.h"

namespace core
{
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

	public:
		UnaryExpressionModel() {};
		UnaryExpressionModel(UnaryExpression<T>* _ope, Expression<T>* _operande) : operatoor(_ope), operande(_operande) {};
		virtual ~UnaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(const Expression*) const;

	private:
		UnaryExpression<T>* operatoor;
		Expression<T>* operande;
	};

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (operande != NULL)
			return evaluate(operande);
		throw new NullException("Operande is null!");
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(const Expression<T>* _operande) const
	{
		if (operatoor != NULL)
			return operatoor->evaluate(_operande);
		throw new NullException("Operator is null!");
	}
}

#endif