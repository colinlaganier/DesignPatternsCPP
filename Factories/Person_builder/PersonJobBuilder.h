//
// Created by Colin Laganier on 03/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_PERSONJOBBUILDER_H
#define UDEMY_DESIGN_PATTERS_PERSONJOBBUILDER_H

#include "PersonBuilder.hpp"
#include <string>

class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder Self;
public:
    explicit PersonJobBuilder(Person &person) : PersonBuilderBase(person) {};

    Self& at(std::string company_name)
    {
        person.company_name = company_name;
        return *this;
    }

    Self& as_a(std::string position)
    {
        person.position = position;
        return *this;
    }

    Self& earning(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }

};


#endif //UDEMY_DESIGN_PATTERS_PERSONJOBBUILDER_H
