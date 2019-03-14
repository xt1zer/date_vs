//РЕАЛИЗАЦИЯ КЛАССА DATE - ОПИСАНИЕ МЕТОДОВ

#include "Date.h"
#include <iostream>
#include <algorithm>
//using std::abs;

Date::Date() : m_year(1901), m_month(1), m_day(1) {}

Date::Date(const short int &year, const short int &month, const short int &day) : m_year(year), m_month(month),
                                                                                  m_day(day) {}

Date::Date(const Date &copy) : m_year(copy.m_year), m_month(copy.m_month), m_day(copy.m_day) {}

const bool Date::operator<(const Date &d2) const {
    return m_year < d2.m_year || m_month < d2.m_month
           || (m_year == d2.m_year && m_month == d2.m_month && m_day < d2.m_day);
}

const bool Date::operator>(const Date &d2) const {
    return (m_year > d2.m_year) || (m_year == d2.m_year && m_month > d2.m_month)
           || (m_year == d2.m_year && m_month == d2.m_month && m_day > d2.m_day);
}

const bool Date::operator<=(const Date &d2) const {
    return !(*this > d2);
}

const bool Date::operator>=(const Date &d2) const {
    return !(*this < d2);
}

const bool Date::operator==(const Date &d2) const {
    return this->m_year == d2.m_year && this->m_month == d2.m_month && this->m_day == d2.m_day;
}

const bool Date::operator!=(const Date &d2) const {
    return !(*this == d2);
}

void Date::print_date() const {
    std::cout << m_year << '/' << m_month << '/' << m_day << std::endl;
}

void Date::set_date(const short int &year, const short int &month, const short int &day) {
    m_year = year;
    m_month = month;
    m_day = day;
}

const bool Date::is_leap_year() const {
    return m_year % 400 == 0
           || (m_year % 100 != 0
               && m_year % 4 == 0);
}

const bool Date::is_leap_year(const short int &year) const {
    return year % 400 == 0
           || (year % 100 != 0
               && year % 4 == 0);
}

const short int Date::days_in_year() const {
    if (is_leap_year())
        return 366;
    return 365;
}

const short int Date::days_in_year(const short int &year) const {
    if (is_leap_year(year))
        return 366;
    return 365;
}

const short int Date::days_in_month() const {
    if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)
        return 30;
    if (m_month == 2) {
        if (is_leap_year())
            return 29;
        else
            return 28;
    }
    return 31;
}

const short int Date::days_in_month(const short int &year, const short int &month) const {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if (month == 2) {
        if (is_leap_year(year))
            return 29;
        else
            return 28;
    }
    return 31;
}

const bool Date::correct_date() const {
    return m_year >= 1901
           && m_month >= 1 && m_month <= 12
           && m_day >= 1 && m_day <= days_in_month();
}

Date Date::next_day() const {
    if (correct_date()) {

        Date date(*this);
        if (m_day < days_in_month())
            ++date.m_day;
        else {
            date.m_day = 1;
            ++date.m_month;
        }

        if (date.m_month == 13) {
            date.m_month = 1;
            ++date.m_year;
        }

        return date;
    }

    else {
        std::cout << "wrong data!";
    }
}

Date Date::previous_day() const {
    if (correct_date()) {

        Date date(*this);
        if (date.m_day > 1)
            --date.m_day;
        else {
            --date.m_month;

            if (date.m_month == 0) {
                date.m_month = 12;
                --date.m_year;
            }

            date.m_day = days_in_month(date.m_year, date.m_month);
        }

        return date;
    }

    else {
        std::cout << "wrong data!";
    }
}

const unsigned long int Date::count_days() const {
    unsigned long int s(0);
    short int y;
    for (y = m_firstYear; y < m_year; ++y)
        s += days_in_year(y);

    for (short int m = 1; m < m_month; ++m)
        s += days_in_month(y, m);

    s += m_day;

    return s;
}

Date Date::define_date(long int days) const {
    Date date(0, 1, 0);

    while (days > days_in_year(m_firstYear + date.m_year))
        days -= days_in_year(m_firstYear + date.m_year++);
    date.m_year += m_firstYear;

    while (days > days_in_month(date.m_year, date.m_month))
        days -= days_in_month(date.m_year, date.m_month++);

    date.m_day = (short int) days;

    return date;
}

Date Date::future_date(long int days) const {
    days += count_days();
    return define_date(days);
}

Date Date::past_date(long int days) const {
    days = count_days() - days;
    return define_date(days);
}

const unsigned long int count_days_between_dates(const Date &d1, const Date &d2) {
    return abs(d1.count_days() - d2.count_days());
}

int compare(const void *a, const void *b) {
	return *((const Date*)a) > *((const Date*)b);
	/*if (*(Date*)a <  *(Date*)b) return -1;
	if (*(Date*)a == *(Date*)b) return 0;
	if (*(Date*)a >  *(Date*)b) return 1;*/
}

void sort_dates(Date * dates, const int &num) {
	std::qsort(dates, num, sizeof(dates[0]), compare);
	//std::sort(dates, dates + (num-1));
}

void print_array_dates(const Date * dates, const int &num){
    for(int i=0; i<num; ++i)
        dates[i].print_date();
}
