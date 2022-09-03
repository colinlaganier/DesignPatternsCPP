#ifndef UDEMY_DESIGN_PATTERS_PERSON_H
#define UDEMY_DESIGN_PATTERS_PERSON_H
#include <string>
#include <iostream>

class Person {
public:
    std::string name;

    class PersonImpl;
    PersonImpl* impl;

    Person();
    virtual ~Person();

    void greet();
};


#endif //UDEMY_DESIGN_PATTERS_PERSON_H
