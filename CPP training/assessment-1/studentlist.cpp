#include <iostream>
#include <string>

class Student {
    const char *name;
    static std::string board;
    double marks;

public:
    Student(const char *s, double mrk) : name(new char[10]), marks(mrk)
    {
        name = s;
    }

    std::string getName()
    {
        return name;
    }
    double getMarks()
    {
        return marks;
    }
    std::string getBoard()
    {
        return board;
    }
    ~Student()
    {
        name=nullptr;
    }
};

std::string Student::board="kerala";
int main()
{
        Student student[3] = {{"Student 1", 380}, {"Student 2", 496.5}, {"Student 3", 215}};

        for(auto t : student)
                std::cout << t.getName() << " " << t.getMarks() << " " << t.getBoard() << std::endl;
                

        return 0;
}
