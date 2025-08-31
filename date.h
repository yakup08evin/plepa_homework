#ifndef DATE_H
#define DATE_H

#include <iosfwd>
#include <ctime>
#include <string>
#include <iostream>
#include <array>
#include <cstdlib>

namespace project {
	class Date {
		int m_day;
		int m_month;
		int m_year;
	public:
		static constexpr int year_base = 1900;
		static constexpr int random_min_year = 1940;
		static constexpr int random_max_year = 2020;
		enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
		static constexpr int DaysInMonth[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		Date();
		Date(int d, int m, int y);
		explicit Date(const char* p);
		explicit Date(const std::time_t timer);
		[[nodiscard]] int get_month_day()const;
		[[nodiscard]] int get_month()const;
		[[nodiscard]] int get_year()const;
		[[nodiscard]] int get_year_day()const;
		[[nodiscard]] Weekday get_week_day()const;

		Date& set_month_day(int day);
		Date& set_month(int month);
		Date& set_year(int year);
		Date& set(int day, int mon, int year);
		[[nodiscard]] Date operator-(int day)const;
		Date& operator+=(const int day);
		Date& operator-=(const int day);
		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);

		friend bool operator<(const Date&, const Date&);
		friend bool operator==(const Date&, const Date&);
		[[nodiscard]] static Date random_date();
		static constexpr bool isleap(int y);

		friend std::ostream& operator<<(std::ostream& os, const Date& date); //31
		friend std::istream& operator>>(std::istream& is, Date& date); //32
	};

	[[nodiscard]] bool operator<=(const Date&, const Date&);
	[[nodiscard]] bool operator>(const Date&, const Date&);
	[[nodiscard]] bool operator>=(const Date&, const Date&);
	[[nodiscard]] bool operator!=(const Date&, const Date&);

	[[nodiscard]] int operator-(const Date& lhs, const Date& rhs);
	[[nodiscard]] Date operator+(const Date& date, int n);
	[[nodiscard]] Date operator+(int n, const Date& date);
	Date::Weekday& operator++(Date::Weekday& r); //30
	Date::Weekday operator++(Date::Weekday& r, int); //30
	Date::Weekday& operator--(Date::Weekday& r); //30
	Date::Weekday operator--(Date::Weekday& r, int); //30}


};

#endif