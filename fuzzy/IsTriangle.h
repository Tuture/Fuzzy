#ifndef IS_TRIANGLE_H
#define IS_TRIANGLE_H

#include "Operators.h"

namespace fuzzy
{
	using namespace core;

	template <class T>
	class IsTriangle : public Is<T>
	{
	public:
		IsTriangle() {};
		IsTriangle(T _min, T _mid, T _max) : min(_min), mid(_mid), max(_max) {};
		virtual ~IsTriangle() {};
		virtual T evaluate(const Expression<T>*) const;

	private:
		T min, mid, max;
	};

	template <class T>
	T IsTriangle<T>::evaluate(const Expression<T>* _value) const
	{
		T v = _value->evaluate();

		if (v <= min || v >= max)
			return NULL;

		return v <= mid ? (v - min) / (mid - min) : (max - v) / (max - mid);
	}
}

#endif