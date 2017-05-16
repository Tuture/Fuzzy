#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class SugenoThen : public Then<T>
	{
	public:
		SugenoThen() :premiseValue(0) {};
		virtual ~SugenoThen() {};

		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
		virtual T getPremiseValue();

	public:
		mutable T premiseValue;
	};

	template <class T>
	T SugenoThen<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		premiseValue = _left->evaluate();
		return premiseValue * _right->evaluate();
	}

	template <class T>
	T SugenoThen<T>::getPremiseValue()
	{
		return premiseValue;
	}
}

#endif
