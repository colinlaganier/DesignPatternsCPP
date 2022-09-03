//
// Created by Colin Laganier on 03/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_PERSONBUILDER_H
#define UDEMY_DESIGN_PATTERS_PERSONBUILDER_H

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected:
    Person& person;
public:
    PersonBuilderBase(Person &person);

    // Need explanation
    explicit operator Person() const {
        return std::move(person);
    }

    PersonAddressBuilder lives () const;
    PersonJobBuilder works () const;

};

class PersonBuilder : public PersonBuilderBase
{
private:
    Person p;

public:
    PersonBuilder();
};


#endif //UDEMY_DESIGN_PATTERS_PERSONBUILDER_H
