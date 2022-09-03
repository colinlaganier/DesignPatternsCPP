//
// Created by Colin Laganier on 03/08/2022.
//

#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"


PersonBuilderBase::PersonBuilderBase(Person &person) : person(person) {}

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder{person};
}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {}
