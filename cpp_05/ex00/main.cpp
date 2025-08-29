#include "Bureaucrat.hpp"
#include "cstdlib"

static void tryGradeChange(Bureaucrat& b, bool increment);
static void tryGradeChange(Bureaucrat& b, bool increment);

static void tryCreateBureaucrat(const std::string& name, int grade)
{
    try {
        std::cout << "Trying to create Bureaucrat: " << name
                  << " with grade " << grade << "..." << std::endl;
        Bureaucrat b(name, grade);
        std::cout << "Success! " << b.getName()
                  << " has grade " << b.getGrade() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Failed to create Bureaucrat: " << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

static void tryGradeChange(Bureaucrat& b, bool increment)
{
    try
    {
        std::cout << "Trying to " << (increment ? "increment" : "decrement")
                  << " grade of " << b.getName() << " (current: " << b.getGrade() << ")..." << std::endl;
        if (increment)
            b.incrementGrade();
        else
            b.decrementGrade();
        std::cout << "New grade: " << b.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Failed to change grade: " << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

int main() 
{
    // Invalid Bureaucrat creations
    tryCreateBureaucrat("Umut", 0);
    tryCreateBureaucrat("Can", 200);

    // Valid Bureaucrat
    Bureaucrat a("Ayşe", 2);
    std::cout << "Created " << a.getName() << " with grade " << a.getGrade() << std::endl;
    std::cout << "--------------------------" << std::endl;

    tryGradeChange(a, true);

    tryGradeChange(a, true);

    tryGradeChange(a, false);

    return (EXIT_SUCCESS);
}
