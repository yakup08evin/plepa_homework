#include <iostream>
#include "Date.h"

int main() {

	using project::Date;

	const char p[15] = "25/12/2020";

	Date d1{ p };

	Date d2{ std::time(nullptr) };

	std::cout << "Day of year : " << d2.get_year_day() << '\n';

	std::cout << "Day of week : " << static_cast<int>(d2.get_week_day()) << '\n';

	std::cout << "d1 : " << d1 << '\n';

	std::cin >> d1;

	std::cout << "d1 : " << d1 << '\n';

	return 0;
}
