#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H

namespace core
{
	template <class T>
	class ValueModel : public Expression<T> {

	public:
		ValueModel() {};
		ValueModel(const T& _v) : value(_v) {};
		virtual ~ValueModel() {};

		virtual T evaluate() const;
		void setValue(const T& v);

	private:
		T value;
	};

	template <class T>
	void ValueModel<T>::setValue(const T& _v)
	{
		value = _v;
	}

	template <class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}
}

#endif