#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include <cstdio>
#include <cstdlib>

namespace fuzzy
{
	using namespace core;
	using namespace std;

	template <class T>
	class Evaluator
	{
	public:
		typedef pair<vector<T>, vector<T>> Shape;

		Shape BuildShape(const T&, const T&, const T&, ValueModel<T>*,const Expression<T>*) const;
		ostream& PrintShape(const Shape&, ostream&) const;
	};

	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, ValueModel<T>* v, const Expression<T>* e) const
	{
		vector<T> x, y;
		T mem = v->evaluate();

		for (T i = min; i <= max; i += step)
		{
			v->setValue(i);
			x.push_back(i);
			y.push_back(e->evaluate());
		}

		v->setValue(mem);

		return Shape(x, y);
	}

	template <class T>
	typename ostream& Evaluator<T>::PrintShape(const Shape& s, ostream& os) const
	{
		for (vector<T>::const_iterator ity = s.second.begin(); ity != s.second.end(); ity++)
		{
			unsigned count = (unsigned)((*ity) * 10);

			while (count != 0)
			{
				os << "-";
				count--;
			}

			os << "*" << endl;
		}

		return os;
	}
}

#endif