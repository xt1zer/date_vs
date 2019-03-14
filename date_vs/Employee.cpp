#include "Employee.h"
#include <iostream>
#include <algorithm>
using std::cout, std::endl;

Employee::Employee() {
    this->name = new String(""); // prolly same as String()
    this->surname = new String("");
    this->position = new String("");
    this->education = new String("");
}

Employee::Employee(const String & name, const String & surname, const String & position, const String & rank, const String & education, const Date & birthDate, const Date & employmentDate, const float & salary) {
    this->name = new String(name);
    this->surname = new String(surname);
    this->position = new String(position);
    this->rank = new String(rank);
    this->education = new String(education);

    this->birthDate = birthDate;
    this->employmentDate = employmentDate;

    this->salary = salary;
}

Employee::Employee(const Employee & copy) {
    this->name = new String(*copy.name);
    this->surname = new String(*copy.surname);
    this->position = new String(*copy.position);
    this->rank = new String(*copy.rank);
    this->education = new String(*copy.education);

    this->birthDate = copy.birthDate;
    this->employmentDate = copy.employmentDate;

    this->salary = copy.salary;
}

Employee::~Employee() {
    delete name; delete surname; delete position; delete rank; delete education;
    name = surname = position = education = nullptr;
    birthDate = Date();
    employmentDate = Date();
    salary = 0.0;
}

void Employee::print_info() const {
    cout << "\t Full name: "; name->print(); cout << " "; surname->print(); cout << " \n";
    cout << "\t Position: "; rank->print(); position->print(); cout << endl;
    cout << "\t Education: "; education->print(); cout << endl;
    cout << "\t Date of birth: "; birthDate.print_date();
    cout << "\t Date of employment: "; employmentDate.print_date();
    cout << "\t Salary: " << salary << endl;
}

void Employee::set_position(const String & position) { *this->position = position; }

void Employee::set_education(const String & education) { *this->education = education; }

void Employee::set_salary(const float & salary) { this->salary = salary; }

const short int Employee::compute_age(const Date & today) const {
    if (today.correct_date() && today > birthDate) {
        return (unsigned short int)(count_days_between_dates(birthDate, today) / 365);
    }

    else {
        std::cout << "\t Wrong current date! \n";
        return -1;
    }
}

const short int Employee::compute_experience(const Date & today) const {
    if (today.correct_date() && today > employmentDate) {
        return (unsigned short int)(count_days_between_dates(employmentDate, today) / 365);
    }

    else {
        std::cout << "\t Wrong current date! \n";
        return -1;
    }
}

void Employee::set_salary_by_exp(const Date & today) {
    const short int experience = compute_experience(today);

    if (experience == -1)
        return;

    if(experience >= 15 && experience < 20)
        salary += salary / 100 * 3;

    else if (experience >= 20 && experience < 25)
        salary += salary / 100 * 5;

    else if (experience >= 25 && experience < 30)
        salary += salary / 100 * 10;

    else if (experience >= 30)
        salary += salary / 100 * 15;
}

void Employee::set_salary_by_rank() {
    if (*rank == "Head ")
        salary += salary / 100 * 20;

    else if (*rank == "Junior ")
        salary -= salary / 100 * 2;
}

void sort_by_birth(Employee * array, const int & num) {
    std::sort(array, array + (num - 1), [](const Employee & a, const Employee & b) -> bool { return a.birthDate < b.birthDate; });
}

void sort_by_hiring(Employee * array, const int & num) {
    std::sort(array, array + (num - 1), [](const Employee & a, const Employee & b) -> bool { return a.employmentDate < b.employmentDate; });
}
