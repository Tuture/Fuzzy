#ifndef NARY_EXPRESSION_MODEL_H
#define NARY_EXPRESSION_MODEL_H

#include "NullException.h"

namespace core
{
	using namespace std;

	template <class T>
	class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {

	public:
		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression<T>* _ope, vector<const Expression<T>*>* _operandes) :operatoor(_ope), operandes(_operandes) {};
		virtual ~NaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(std::vector<const Expression<T>*>*) const;

	private:
		NaryExpression<T>* operatoor;
		vector<const Expression<T>*>* operandes;
	};

	template <class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (!operandes->empty())
			return evaluate(operandes);
		throw new NullException("Operandes vector is empty!");
	}

	template <class T>
	T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*>* _operandes) const
	{
		if (operatoor != NULL)
			return operatoor->evaluate(_operandes);
		throw new NullException("Operator is null!");
	}
}

#endif