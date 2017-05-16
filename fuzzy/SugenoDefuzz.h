#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "../core/NaryExpression.h"

namespace fuzzy
{
	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T>
	{
	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};

		virtual T evaluate(std::vector<const core::Expression<T>*>*) const;
	};

	template <class T>
	T SugenoDefuzz<T>::evaluate(std::vector<const core::Expression<T>*>* _operands) const
	{
		std::vector<const core::Expression<T>*>::const_iterator it;

		T num = 0;
		T denum = 0;

		// calcul somme des wi
		for (it = _operands->begin(); it != _operands->end(); it++)
		{
			num += (*it)->evaluate();

			core::BinaryExpressionModel<T>*  bem = (core::BinaryExpressionModel<T>*)  (*it);
			core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOpe();
			SugenoThen<T>*                   sth = (SugenoThen<T>*)                   bse->getTarget();


			denum += sth->getPremiseValue();
		}

		if (denum != 0)
			return num / denum;
		else
			return 0;
	}
}

#endif
