#ifndef COG_DEFUZZ_H
#define COG_DEFUZZ_H

#include "MamdaniDefuzz.h"
#include <numeric>

namespace fuzzy
{
	using namespace std;
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {

	public:
		CogDefuzz() {};
		~CogDefuzz() {};

		virtual T defuzz(const Shape&) const;
	};

	template <class T>
	T CogDefuzz<T>::defuzz(const Shape& _shape) const
	{
		vector<T> product;
		vector<T>::const_iterator itX = _shape.first.begin();
		vector<T>::const_iterator itY = _shape.second.begin();

		for (; itY != _shape.second.end(); ++itY, ++itX) {
			T x = (*itX);
			T y = (*itY);
			product.push_back(x * y);
		}

		T sumProduct = 0;
		T sumY = 0;

		// (somme des xi*yi) / (somme des yi) (center of gravity)
		return accumulate(product.begin(), product.end(), sumProduct)
			/ accumulate(_shape.second.begin(), _shape.second.end(), sumY);
	}
}

#endif