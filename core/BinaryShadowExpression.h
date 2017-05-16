#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H

namespace core
{
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {

	public:
		BinaryShadowExpression() {};
		BinaryShadowExpression(BinaryExpression<T>* _target) :target(_target) {};
		virtual ~BinaryShadowExpression() {};

		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;

		BinaryExpression<T>* getTarget() const;

	private:
		BinaryExpression<T>* target;
	};

	template <class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() const {
		return target;
	}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		if (target != NULL)
			return target->evaluate(_left, _right);
		throw new NullException("Target is null!");
	}
}

#endif