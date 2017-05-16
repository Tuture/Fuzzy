#ifndef SUGENO_CONCLUSION_H
#define SUGENO_CONCLUSION_H

#include "../core/NaryExpression.h"

namespace fuzzy
{
	using namespace core;
	using namespace std;

	template <class T>
	class SugenoConclusion : public NaryExpression<T> {

	public:
		SugenoConclusion(vector<T>* coeff) : coeff(coeff) {};
		virtual ~SugenoConclusion() {};

		virtual T evaluate(vector<const Expression<T>*>*) const;

	private:
		const vector<T> *coeff;
	};

	template <class T>
	T SugenoConclusion<T>::evaluate(vector<const Expression<T>*>* _operands) const
	{
		vector<T>::const_iterator itcoef = coeff->begin();
		vector<const core::Expression<T>*>::const_iterator itexpr = _operands->begin();
		T z = 0;

		// calcul de la somme des Zi
		for (; itexpr != _operands->end() && itcoef != coeff->end(); itexpr++, itcoef++)
		{
			// evaluation de la règle courante
			T eval = (*itexpr)->evaluate();

			// multiplication par le coefficient associé à cette règle
			z += (*itcoef) * eval;
		}

		return z;
	};
}

#endif
