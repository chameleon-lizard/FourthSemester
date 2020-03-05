#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class Student
{
    char *name;
    char *surname;
    char *fathername;
    unsigned long stud;
    unsigned int fives;
    unsigned int fours;
    unsigned int threes;

public:
    // Constructors
    Student();
    Student(
        const char *name_i, const char *surname_i, const char *fathername_i,
        unsigned long stud_i, unsigned int fives_i, unsigned int fours_i,
        unsigned int threes_i);
    Student(const Student &X);

    // Destructor
    ~Student();

    // Methods
    Student operator=(const Student &);
    Student &operator++();
    const Student operator++(int);
    double median() const;
    char *get_name() const;
    char *get_surname() const;
    char *get_fathername() const;
    unsigned get_fives() const;
    unsigned get_fours() const;
    unsigned get_threes() const;
    unsigned long get_stud() const;
    void set_name(const char *a);
    void set_surname(const char *a);
    void set_fathername(const char *a);
    void set_fives(int a);
    void set_fours(int a);
    void set_threes(int a);
    void set_stud(int a);
    void print() const;
};

Student::Student()
{
    name = 0;
    surname = 0;
    fathername = 0;
    stud = 0;
    fives = 0;
    fours = 0;
    threes = 0;
}

Student::Student(
    const char *name_i, const char *surname_i, const char *fathername_i,
    unsigned long stud_i, unsigned int fives_i, unsigned int fours_i,
    unsigned int threes_i)
{
    name = 0;
    surname = 0;
    fathername = 0;
    stud = 0;
    fives = 0;
    fours = 0;
    threes = 0;
    set_name(name_i);
    set_surname(surname_i);
    set_fathername(fathername_i);
    set_stud(stud_i);
    set_fives(fives_i);
    set_fours(fours_i);
    set_threes(threes_i);
}

Student::Student(const Student &X)
{
    *this = X;
}

Student::~Student()
{
    if (name != 0)
    {
        free(name);
    }

    if (surname != 0)
    {
        free(surname);
    }

    if (fathername != 0)
    {
        free(fathername);
    }
}

Student
Student::operator=(const Student &X)
{
    set_threes(X.get_threes());
    set_name(X.get_name());
    set_stud(X.get_stud());
    set_fives(X.get_fives());
    set_fours(X.get_fours());
    set_surname(X.get_surname());
    set_fathername(X.get_fathername());

    return *this;
}

Student &Student::operator++()
{
    set_stud(this->stud + 1);
    return *this;
}

const Student Student::operator++(int)
{
    Student temp(*this);
    set_stud(this->stud + 1);
    return temp;
}

double
Student::median() const
{
    if ((fives + fours + threes) == 0)
    {
        return 0;
    }

    return (double)(fives * 5 + fours * 4 + threes * 3) / (fives + fours + threes);
}

char *
Student::get_name() const
{
    return name;
}

char *
Student::get_surname() const
{
    return surname;
}

char *
Student::get_fathername() const
{
    return fathername;
}

unsigned
Student::get_fives() const
{
    return fives;
}

unsigned
Student::get_fours() const
{
    return fours;
}

unsigned
Student::get_threes() const
{
    return threes;
}

unsigned long
Student::get_stud() const
{
    return stud;
}

void Student::set_threes(int a)
{
    threes = a;
}

void Student::set_stud(int a)
{
    stud = a;
}

void Student::set_fives(int a)
{
    fives = a;
}

void Student::set_fours(int a)
{
    fours = a;
}

void Student::set_name(const char *a)
{
    if (name != 0)
    {
        free(name);
    }

    if (a == 0)
    {
        name = 0;
    }
    else
    {
        name = (char *)calloc(strlen(a) + 1, sizeof(*name));
        strncpy(name, a, strlen(a) + 1);
    }
}

void Student::set_surname(const char *a)
{
    if (surname != 0)
    {
        free(surname);
    }

    if (a == 0)
    {
        surname = 0;
    }
    else
    {
        surname = (char *)calloc(strlen(a) + 1, sizeof(*surname));
        strncpy(surname, a, strlen(a) + 1);
    }
}

void Student::set_fathername(const char *a)
{
    if (fathername != 0)
    {
        free(fathername);
    }

    if (a == 0)
    {
        fathername = 0;
    }
    else
    {
        fathername = (char *)calloc(strlen(a) + 1, sizeof(*fathername));
        strncpy(fathername, a, strlen(a) + 1);
    }
}

void Student::print() const
{
    printf("%s\n%s\n%s\n%lu\n%u\n%u\n%u\n%lf\n",
           get_name(), get_surname(), get_fathername(),
           get_stud(), get_fives(), get_fours(),
           get_threes(), median());
}

void exceptfunc(Student *a)
{
    if (
        a[0].get_stud() == a[1].get_stud() &&
        (strcmp(a[0].get_name(), a[1].get_name()) != 0 ||
         strcmp(a[0].get_surname(), a[1].get_surname()) != 0 ||
         strcmp(a[0].get_fathername(), a[1].get_fathername()) != 0))
    {
        throw a;
    }
    else
    {
        char *first_fullname = (char *)calloc(
            strlen(a[0].get_name()) +
                strlen(a[0].get_surname()) +
                strlen(a[0].get_fathername()) +
                1,
            sizeof(*first_fullname));

        char *second_fullname = (char *)calloc(
            strlen(a[0].get_name()) +
                strlen(a[0].get_surname()) +
                strlen(a[0].get_fathername()) +
                1,
            sizeof(*first_fullname));

        if (
            strcmp(a[0].get_name(), a[1].get_name()) +
                strcmp(a[0].get_surname(), a[1].get_surname()) +
                strcmp(a[0].get_fathername(), a[1].get_fathername()) >
            0)
        {
            Student b(a[0]);
            a[0] = a[1];
            a[1] = b;
        }
    }
}

int main(void)
{
    Student Hans = Student("Hans", "Von", "Friedrich", 1, 5, 4, 3);
    Hans.print();

    return 0;
}
