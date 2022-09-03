//
// Created by Colin Laganier on 03/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_PERSON_H
#define UDEMY_DESIGN_PATTERS_PERSON_H
#include <string>
#include <ostream>

//#include "PersonBuilder.hpp"
class PersonBuilder;

class Person {
    // Address
    std::string street_address, post_code, city;
    // Employment
    std::string company_name, position;
    int annual_income {0};
public:
    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

//    std::ostream &operator<<(std::ostream &os, const Person &person);

};


#endif //UDEMY_DESIGN_PATTERS_PERSON_H
