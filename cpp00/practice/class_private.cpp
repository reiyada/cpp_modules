#include <iostream>
#include <string>

class Employee
{
public:
    std::string name;

    void set_salary(double potential_salary)
    {
        if (potential_salary < 0)
            salary = 0;
        else
            salary = potential_salary;
    }
    double get_salary()
    {
        return (salary);
    }
    void print_salary()
    {
        std::cout << "Salary: " << get_salary() << std::endl;
    }
    void print_bonus()
    {
        std::cout << "Bonus: " << calculate_bonus() << std::endl;
    }

private://->setter, getter
    double salary;
    double calculate_bonus()
    {
        return (salary * 0.1);
    }
};

int main()
{
    Employee employee1;
    employee1.name = "Rei";
    std::cout << employee1.name << std::endl;

    employee1.set_salary(50000);
    employee1.print_salary();
    employee1.print_bonus();

    return  (0);
}