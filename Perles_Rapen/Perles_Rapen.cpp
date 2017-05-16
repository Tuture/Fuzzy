#include "stdafx.h"

#include "../core/Expression.h"
#include "../fuzzy/AggMax.h"
#include "../fuzzy/AggPlus.h"
#include "../fuzzy/AndMin.h"
#include "../fuzzy/AndMult.h"
#include "../fuzzy/NotMinus1.h"
#include "../fuzzy/OrMax.h"
#include "../fuzzy/OrPlus.h"
#include "../fuzzy/ThenMin.h"
#include "../fuzzy/ThenMult.h"
#include "../fuzzy/IsTriangle.h"
#include "../core/ValueModel.h"

#include "../fuzzy/CogDefuzz.h"
#include "../fuzzy/SugenoDefuzz.h"
#include "../fuzzy/SugenoConclusion.h"
#include "../fuzzy/SugenoThen.h"

#include "../fuzzy/FuzzyFactory.h"

#include <iostream>

void cogDefuzz()
{
	//operators
	fuzzy::NotMinus1<float>  opNot;
	fuzzy::AndMin<float> opAnd;
	fuzzy::OrMax<float> opOr;
	fuzzy::ThenMin<float> opThen;
	fuzzy::AggPlus<float>  opAgg;
	fuzzy::CogDefuzz<float>  opDefuzz;

	//fuzzy expression factory
	fuzzy::FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);


	//service
	fuzzy::IsTriangle<float> poor(-5, 0, 5);
	fuzzy::IsTriangle<float> good(0, 5, 10);
	fuzzy::IsTriangle<float> excellent(5, 10, 15);
	//food
	fuzzy::IsTriangle<float> rancid(-5, 0, 5);
	fuzzy::IsTriangle<float> delicious(5, 10, 15);
	//tips
	fuzzy::IsTriangle<float> cheap(0, 5, 10);
	fuzzy::IsTriangle<float> average(10, 15, 20);
	fuzzy::IsTriangle<float> generous(20, 25, 30);

	//values
	core::ValueModel<float> service(0);
	core::ValueModel<float> food(0);
	core::ValueModel<float> tips(0);

	core::Expression<float> *r =
		f.newAgg(
			f.newAgg(
				f.newThen(
					f.newOr(
						f.newIs(&poor, &service),
						f.newIs(&rancid, &food)
						),
					f.newIs(&cheap, &tips)
					),
				f.newThen(
					f.newIs(&good, &service),
					f.newIs(&average, &tips)
					)
				),
			f.newThen(
				f.newOr(
					f.newIs(&excellent, &service),
					f.newIs(&delicious, &food)
					),
				f.newIs(&generous, &tips)
				)
			);

	//defuzzification
	core::Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

	//apply input
	float s, foo;

	while (true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.setValue(s);
		std::cout << "food : ";
		std::cin >> foo;
		food.setValue(foo);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	cogDefuzz();
	return 0;
}