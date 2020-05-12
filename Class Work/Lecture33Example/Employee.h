// Boston KJ
// Employee struct

struct Employee
{
    int id;
    double payRate;
    int hoursWorked;
};

Employee *setValues(Employee *pE, int id, double payRate, int hoursWorked);
double weeklyPay(Employee *pE);