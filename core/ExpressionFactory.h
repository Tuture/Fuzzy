#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"
#include <set>

namespace core
{
	using namespace std;
	template <class T>
	class ExpressionFactory {

	public:
		ExpressionFactory() {};
		virtual ~ExpressionFactory();

		Expression<T>* hold(Expression<T>*);
		UnaryExpressionModel<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		
	private:
		set<Expression<T>*> ensemble;
	};

	template <class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		// supression des éléments de l'ensemble
		for (set<Expression<T>*>::iterator it = ensemble.begin(); it != ensemble.end(); it++)
			delete *it;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* e)
	{
		ensemble.insert(e);
		return e;
	}

	template <class T>
	UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* _ope, Expression<T>* _operande)
	{
		return (UnaryExpressionModel<T>*) hold(new UnaryExpressionModel<T>(_ope, _operande));
	}

	template <class T>
	BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* _ope, Expression<T>* _left, Expression<T>* _right)
	{
		return (BinaryExpressionModel<T>*) hold(new BinaryExpressionModel<T>(_ope, _left, _right));
	}
}

#endif