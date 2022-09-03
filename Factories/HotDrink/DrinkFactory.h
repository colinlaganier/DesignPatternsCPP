//
// Created by Colin Laganier on 17/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_DRINKFACTORY_H
#define UDEMY_DESIGN_PATTERS_DRINKFACTORY_H
#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include <map>
#include <functional>

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory() {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};

class DrinkWithVolumeFactory
{
    map<string, function<unique_ptr<HotDrink>>()> factories;
public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = [] {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        return factories[name]();
    }
};

#endif //UDEMY_DESIGN_PATTERS_DRINKFACTORY_H
