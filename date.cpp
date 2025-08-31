#include "Date.h"

namespace project {

	Date::Date() : m_day(1), m_month(1), m_year(year_base) {};

	Date::Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y) {};

	Date::Date(const char* p) {

		std::string temp_date{ p };

		size_t pos = temp_date.find('/');
		size_t next_pos = temp_date.find('/', pos + 1);

		m_day = std::stoi(temp_date.substr(0, pos));
		m_month = std::stoi(temp_date.substr(pos + 1, next_pos - pos - 1));
		m_year = std::stoi(temp_date.substr(next_pos + 1));

		std::cout << "Date created from char*: " << m_day << "/" << m_month << "/" << m_year << '\n';
	}

	Date::Date(const std::time_t timer) {

		std::tm timeinfo{};

#if defined(_WIN32) || defined(_WIN64)

		localtime_s(&timeinfo, &timer);
#else
		localtime_r(&timer, &timeinfo);
#endif

		m_day = timeinfo.tm_mday;
		m_month = timeinfo.tm_mon + 1;
		m_year = timeinfo.tm_year + year_base;

		std::cout << "Date created from time_t: " << m_day << "/" << m_month << "/" << m_year << '\n';
	}

	int Date::get_month_day()const { return m_day; }

	int Date::get_month()const { return m_month; }

	int Date::get_year()const { return m_year; }

	int Date::get_year_day()const {

		int day_of_year = 0;

		for (int i = 0; i < m_month; ++i) {

			day_of_year += DaysInMonth[i];
		}

		if (Date::isleap(m_year)) {

			day_of_year += 1;
		}

		day_of_year += m_day;


		return day_of_year;
	}

	constexpr bool Date::isleap(int y) {

		return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
	}

	Date::Weekday Date::get_week_day()const {

		int month = m_month;
		int year = m_year;

		if (m_month < 3) {

			month += 12;
			--year;
		}

		int k = year % 100;
		int j = year / 100;

		int h = (m_day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;

		return static_cast<Weekday>((h));
	}

	Date& Date::set_month_day(int day) {

		if (day > 1 || day < DaysInMonth[m_month] + (m_month == 2 && isleap(m_year) ? 1 : 0)) {

			m_day = day;
		}

		return *this;
	}

	Date& Date::set_month(int month) {

		if (month >= 1 || month <= 12) {

			m_month = month;
		}

		return *this;
	}

	Date& Date::set_year(int year) {

		if (year >= year_base) {

			m_year = year;
		}

		return *this;
	}

	Date& Date::set(int day, int mon, int year) {

		set_year(year);
		set_month(mon);
		set_month_day(day);

		return *this;
	}


	Date& Date::operator-=(const int day) {

		m_day -= day;

		while (m_day < 1) {

			--m_month;

			if (m_month < 1) {

				m_month = 12;
				--m_year;
			}

			m_day = m_day + DaysInMonth[m_month] + (m_month == 2 && isleap(m_year) ? 1 : 0);
		}

		return *this;
	}


	Date& Date::operator+=(const int day) {

		m_day += day;

		while (m_day > DaysInMonth[m_month] + (m_month == 2 && isleap(m_year) ? 1 : 0)) {

			m_month++;

			if (m_month > 12) {

				m_month = 1;
				++m_year;
			}

			m_day = m_day - DaysInMonth[m_month] - (m_month == 2 && isleap(m_year) ? 1 : 0);
		}

		return *this;
	}

	Date Date::operator-(int day)const {

		Date temp{ *this };
		temp -= day;

		return temp;
	}

	Date& Date::operator++() {

		*this += 1;
		return *this;
	}

	Date& Date::operator--() {

		*this -= 1;

		return *this;
	}

	Date Date::operator++(int) {

		Date temp{ *this };
		++(*this);

		return temp;
	}

	Date Date::operator--(int) {

		Date temp{ *this };
		--(*this);

		return temp;
	}

	Date Date::random_date() {

		int year = rand() % (random_max_year - random_min_year + 1) + random_min_year;
		int month = rand() % 12 + 1;
		int day = rand() % (DaysInMonth[month] + (month == 2 && isleap(year) ? 1 : 0)) + 1;
		return Date{ day, month, year };
	}

	[[nodiscard]] bool operator<=(const Date& lhs, const Date& rhs) {

		return (lhs < rhs || lhs == rhs);
	}

	[[nodiscard]] bool operator>(const Date& lhs, const Date& rhs) {

		return !(lhs <= rhs);
	}

	[[nodiscard]] bool operator>=(const Date& lhs, const Date& rhs) {

		return !(lhs < rhs);
	}

	[[nodiscard]] bool operator!=(const Date& lhs, const Date& rhs) {

		return !(lhs == rhs);
	}

	[[nodiscard]] int operator-(const Date& lhs, const Date& rhs) {

		int days = 0;

		Date start = lhs < rhs ? lhs : rhs;
		Date end = lhs < rhs ? rhs : lhs;

		while (start != end) {
			++days;
			++start;
		}
		return lhs < rhs ? -days : days;
	}

	[[nodiscard]] Date operator+(const Date& date, int n) {

		Date temp{ date };

		temp += n;

		return temp;
	}

	[[nodiscard]] Date operator+(int n, const Date& date) {

		return date + n;
	}

	bool operator==(const Date& lhs, const Date& rhs) {

		return (lhs.m_year == rhs.m_year && lhs.m_month == rhs.m_month && lhs.m_day == rhs.m_day);
	}

	bool operator<(const Date& lhs, const Date& rhs) {

		if (lhs.m_year < rhs.m_year) return true;
		if (lhs.m_year == rhs.m_year && lhs.m_month < rhs.m_month) return true;
		if (lhs.m_year == rhs.m_year && lhs.m_month == rhs.m_month && lhs.m_day < rhs.m_day) return true;
		return false;
	}

}




