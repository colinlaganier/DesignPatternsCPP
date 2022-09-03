//
// Created by Colin Laganier on 03/08/2022.
//

#include "Person.h"
#include "PersonBuilder.hpp"

PersonBuilder Person::create() {
    return PersonBuilder();
}

//std::ostream &operator<<(std::ostream &os, const Person &person) {
//    os << "street_address: " << person.street_address << " post_code: " << person.post_code << " city: " << person.city << " company_name: " << person.company_name << " position: " << person.position << " income: " << person.annual_income << std::endl;
//}