//
// Created by Colin Laganier on 03/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_PERSONADDRESSBUILDER_H
#define UDEMY_DESIGN_PATTERS_PERSONADDRESSBUILDER_H

#include "PersonBuilder.hpp"
#include <string>

class PersonAddressBuilder : public PersonBuilderBase {
    typedef PersonAddressBuilder Self;
public:
    PersonAddressBuilder(Person &person) : PersonBuilderBase(person) {}

    Self& at(std::string street_address)
    {
        person.street_address = street_address;
        return *this;
    }

    Self& with_postcode(std::string post_code)
    {
        person.post_code = post_code;
        return *this;
    }

    Self& in(std::string city)
    {
        person.city = city;
        return *this;
    }
};


#endif //UDEMY_DESIGN_PATTERS_PERSONADDRESSBUILDER_H
