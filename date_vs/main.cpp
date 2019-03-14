#include "Employee.h"
#include "Date/Date.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    Date today(2019, 2, 21);

    Employee t;
    Employee trainee("Daniel", "White", "Programmer", "Head ", "IT Specialist", Date(1998, 12, 18), Date(2016, 12, 18), 15);
    Employee test(trainee);
    Employee economist("Garry", "Hanson", "Accountant", "", "Economics", Date(1993, 5, 3), Date(2003, 9, 8), 12);
    Employee scientist("Melody", "Brook", "Scientist", "Junior ", "Physics", Date(1995, 10, 15), Date(2017, 4, 11), 18);

    Employee arr[4]{economist, trainee, scientist, test};

	t = economist;
	t.print_info();

    //arr[1].print_info();
    
//    test.print_info();
    cout << arr[1].compute_experience(today) << endl;
    cout << scientist.compute_age(today) << endl;
    economist.set_salary_by_exp(today);
    scientist.print_info(); cout << endl;

    scientist.set_salary_by_rank();
    scientist.print_info();

    sort_by_birth(arr, 4);

	//system("pause");
    return 0;
}
