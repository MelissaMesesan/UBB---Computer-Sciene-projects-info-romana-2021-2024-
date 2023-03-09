#pragma once

#include "Truck.h"
#include <assert.h>

void test_truck()
{
	Truck t{ 1,"Mercedes",12000,2007,120000 };

	assert(t.get_brand() == std::string("Mercedes"));
	assert(t.get_id() == 1);
	assert(t.get_mileage() == 12000);
	assert(t.get_price() == 120000);
	assert(t.get_year() == 2007);
}

void test_all()
{
	test_truck();
}