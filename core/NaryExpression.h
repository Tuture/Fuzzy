#ifndef NARY_EXPRESSION_H
#define NARY_EXPRESSION_H

namespace core
{
	template <class T>
	class NaryExpression {
	public:
		NaryExpression() {};
		virtual ~NaryExpression() {};

		virtual T evaluate(std::vector<const Expression<T>*>*) const = 0;
	};
}

#endif