#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H

namespace core
{
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {

	public:
		UnaryShadowExpression() {};
		UnaryShadowExpression(UnaryExpression<T>* _target) : target(_target) {};
		virtual ~UnaryShadowExpression() {};

		T evaluate(const Expression<T>*) const;

	private:
		UnaryExpression<T>* target;
	};

	template <class T>
	T UnaryShadowExpression<T>::evaluate(const Expression<T>* _operande) const
	{
		if (target != NULL)
			return target->evaluate(_operande);
		throw new NullException("Target is null!");
	}
}

#endif