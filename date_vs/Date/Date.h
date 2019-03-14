//ОБЪЯВЛЕНИЕ КЛАССА DATE - ЧЛЕНЫ КЛАССА И ПРОТОТИПЫ МЕТОДОВ

#pragma once

class Date {
	
    friend const unsigned long int count_days_between_dates(const Date & lhs, const Date & rhs); //посчитать разницу в днях между датами
	friend void sort_dates(Date *, const int &); //сортировка массива дат, принимает сам массив и кол-во элементов
	friend void print_array_dates(const Date *, const int &);

private:

    static const short int m_firstYear = 1901; //начало времён
    short int m_year, m_month, m_day;

    const bool is_leap_year(const short int & year) const; //перегрузка с параметром
    const short int days_in_year(const short int & year) const; //перегрузка с параметром
    const short int days_in_month(const short int & year, const short int & month) const; //перегрузка с параметрами
    Date define_date(long int) const; //определение даты по кол-ву дней, начиная с 1901, вывод на экран
    const unsigned long int count_days() const; //подсчёт дней от "начала времён"

public:

    Date(); //инициализация со значениями 1901, 1, 1
    Date(const short int & year, const short int & month, const short int & day); //принимает параметры год, месяц, дата
    Date(const Date & copy); //копирует значения в новый объект из старого
    ~Date() = default;

	//перегруженные операторы сравнения:
    const bool operator<(const Date &) const;
    const bool operator>(const Date &) const;
    const bool operator<=(const Date &) const;
    const bool operator>=(const Date &) const;
    const bool operator==(const Date &) const;
    const bool operator!=(const Date &) const;

    void print_date() const; //вывод даты на экран
    void set_date(const short int & year, const short int & month, const short int & day); //изменение даты на новые значения из параметров
    const bool is_leap_year() const; //идентификация високосного года, возвращает ИСТИНА/ЛОЖЬ
    const short int days_in_year() const; //подсчёт дней в году
    const short int days_in_month() const; //подсчёт дней в месяце
    const bool correct_date() const; //проверка правильности введёной даты, возвращает ИСТИНА/ЛОЖЬ
    Date next_day() const; //определение следующего дня, вывод даты на экран
    Date previous_day() const; //определение предыдущего дня, вывод даты на экран
    Date future_date(long int) const; //определение будущей даты через n дней от данной даты, вывод даты на экран
    Date past_date(long int) const; //определение прошлой даты за n дней от данной даты, вывод даты на экран
 
};
