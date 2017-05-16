#ifndef FUZZY_FACTORY_H
#define FUZZY_FACTORY_H

#include "../core/ExpressionFactory.h"
#include "Operators.h"
#include "MamdaniDefuzz.h"
#include "SugenoDefuzz.h"
#include "SugenoConclusion.h"
#include "../core/UnaryShadowExpression.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/NaryShadowExpression.h"

namespace fuzzy
{
	using namespace core;
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {

	public:
		FuzzyFactory() {};
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*);
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, SugenoDefuzz<T>*, SugenoConclusion<T>*);
		virtual ~FuzzyFactory();

		Expression<T>* newNot(Expression<T>*);
		Expression<T>* newIs(Is<T>*, Expression<T>*);
		Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		Expression<T>* newOr(Expression<T>*, Expression<T>*);
		Expression<T>* newThen(Expression<T>*, Expression<T>*);
		Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T&, const T&, const T&);
		Expression<T>* newSugeno(std::vector<const Expression<T>*>*);
		Expression<T>* newNConclusion(std::vector<const Expression<T>*>*);

		void changeNot(Not<T>*);
		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeDefuzz(MamdaniDefuzz<T>*);
		void changeSugeno(SugenoDefuzz<T>*);
		void changeConclusion(SugenoConclusion<T>*);

	private:
		UnaryShadowExpression<T>*  not;
		BinaryShadowExpression<T>* and;
		BinaryShadowExpression<T>* or ;
		BinaryShadowExpression<T>* then;
		BinaryShadowExpression<T>* agg;
		BinaryShadowExpression<T>* defuzz;
		NaryShadowExpression<T>*   sugeno;
		NaryShadowExpression<T>*   conclusion;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, MamdaniDefuzz<T>* _defuzz) {
		not = new UnaryShadowExpression<T>(_not);
		and = new BinaryShadowExpression<T>(_and);
		or = new BinaryShadowExpression<T>(_or);
		then = new BinaryShadowExpression<T>(_then);
		agg = new BinaryShadowExpression<T>(_agg);
		defuzz = new BinaryShadowExpression<T>(_defuzz);
	}

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, SugenoDefuzz<T>* _sugeno, SugenoConclusion<T>* _conclusion) {
		not = new UnaryShadowExpression<T>(_not);
		and = new BinaryShadowExpression<T>(_and);
		or = new BinaryShadowExpression<T>(_or);
		then = new BinaryShadowExpression<T>(_then);
		agg = new BinaryShadowExpression<T>(_agg);
		sugeno = new NaryShadowExpression<T>(_sugeno);
		conclusion = new NaryShadowExpression<T>(_conclusion);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o)
	{
		return newUnary(not, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newIs(Is<T>* s, Expression<T>* o)
	{
		return newUnary(s, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(and, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(or , l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(then, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(agg, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step)
	{
		MamdaniDefuzz<T>* target = (MamdaniDefuzz<T>*) defuzz->getTarget();
		target->setMin(min);
		target->setMax(max);
		target->setStep(step);

		return newBinary(defuzz, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newSugeno(std::vector<const Expression<T>*>* operands)
	{
		return newNary(sugeno, operands);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newNConclusion(std::vector<const Expression<T>*>* operands)
	{
		return newNary(conclusion, operands);
	}

	template <class T>
	void FuzzyFactory<T>::changeNot(Not<T>* o)
	{
		not->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o)
	{
		and->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o)
	{
		or ->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeThen(Then<T>* o)
	{
		then->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* o)
	{
		agg->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T>* o)
	{
		defuzz->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeSugeno(SugenoDefuzz<T>* o)
	{
		sugeno->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeConclusion(SugenoConclusion<T>* o)
	{
		conclusion->setTarget(o);
	}

	template <class T>
	FuzzyFactory<T>::~FuzzyFactory()
	{
		delete not;
		delete and;
		delete or ;
		delete then;
		delete agg;
		delete defuzz;
		delete sugeno;
		delete conclusion;
	}
}

#endif
