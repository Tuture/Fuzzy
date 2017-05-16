#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "Evaluator.h"

namespace fuzzy
{
	using namespace core;
	using namespace std;

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {

	public:
		typedef pair<vector<T>, vector<T>> Shape;

		MamdaniDefuzz() : min(0), max(0), step(0) {};
		MamdaniDefuzz(const T& _min, const T& _max, const T& _step) : min(_min), max(_max), step(_step) {};
		~MamdaniDefuzz() {};

		virtual void setMin(const T& _min) { min = _min; }
		virtual void setMax(const T& _max) { max = _max; }
		virtual void setStep(const T& _step) { step = _step; }

		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;

		virtual T defuzz(const Shape&) const = 0;

	private:
		T min, max, step;
	};

	template <class T>
	T MamdaniDefuzz<T>::evaluate(const Expression<T>* _left, const Expression<T>* _right) const
	{
		Evaluator<T> e;
		Evaluator<T>::Shape s = e.BuildShape(min, max, step, (ValueModel<T>*) _left, _right);
		return defuzz(s);
	}
}

#endif