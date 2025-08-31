#include <iostream>
#include "Date.h"

int main() {

	using project::Date;

	const char p[15] = "25/12/2020";

	Date d1{ p };

	Date d2{ std::time(nullptr) };

	std::cout << "Day of year : " << d2.get_year_day() << '\n';

	std::cout << "Day of week : " << static_cast<int>(d2.get_week_day()) << '\n';

	return 0;
}
