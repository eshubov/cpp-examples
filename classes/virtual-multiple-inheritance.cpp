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









// ANSWER:
// -------
// Use virtual multiple inheritance:
//
//    struct Student: Person {
//        virtual void learn() {}
//    };
//
//    struct Worker: Person {
//        virtual void work() {}
//    };





// EXPLANATION:
// ------------
//
// A call to aTeachingAssistant.speak() is ambiguous because there are two Person (indirect) base classes in TeachingAssistant, 
// so any TeachingAssistant object has two different Person base class subobjects.
//
// To disambiguate, we would need to explicitly convert ta to any of the two base class subobjects:
//    TeachingAssistant ta;
//    Person& student = static_cast<Student&>(ta); 
//    Person& worker = static_cast<Worker&>(ta);
// Or use virtual multiple inheritance:
//    struct Student: virtual Person {
//       virtual void learn() {}
//    };
//
//    struct Worker: virtual Person {
//        virtual void work() {}
//    };