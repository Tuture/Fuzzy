#ifndef NARY_SHADOW_EXPRESSION_H
#define NARY_SHADOW_EXPRESSION_H

namespace core
{
	using namespace std;
	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {

	public:
		NaryShadowExpression() {};
		NaryShadowExpression(const NaryExpression<T>* _target) : target(_target) {};
		virtual ~NaryShadowExpression() {};

		T evaluate(vector<const Expression<T>*>*) const;

	private:
		NaryExpression<T>* target;
	};

	template <class T>
	T NaryShadowExpression<T>::evaluate(std::vector<const Expression<T>*>* _operandes) const
	{
		if (target != NULL)
			return target->evaluate(_operandes);
		throw new NullException("Target is null!");
	}

}

#endif