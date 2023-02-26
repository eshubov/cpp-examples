// Which change should be done to fix compilation error?

struct Person {
    virtual ~Person() = default;
    virtual void speak() {}
};

struct Student: Person {
    virtual void learn() {}
};

struct Worker: Person {
    virtual void work() {}
};

// A teaching assistant is both a worker and a student
struct TeachingAssistant: Student, Worker {};

int main()
{
    TeachingAssistant ta;
    Person& a = ta;
    Person& student = static_cast<Student&>(ta); 
    Person& worker = static_cast<Worker&>(ta);
}    