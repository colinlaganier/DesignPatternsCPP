//
// Created by Colin Laganier on 17/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_HOTDRINKFACTORY_H
#define UDEMY_DESIGN_PATTERS_HOTDRINKFACTORY_H

#pragma once
#include "HotDrink.h"

struct HotDrinkFactory { //abstract factory from which we inherit
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory:HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory:HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};

#endif //UDEMY_DESIGN_PATTERS_HOTDRINKFACTORY_H
