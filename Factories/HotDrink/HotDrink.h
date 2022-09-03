//
// Created by Colin Laganier on 13/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_HOTDRINK_H
#define UDEMY_DESIGN_PATTERS_HOTDRINK_H

#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct HotDrink {
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
    int test = 0;
};

struct Tea : HotDrink {
    void prepare(int volume) override {
        cout << "Tea bag, pour :"  << volume << "liters" << endl;
    }
    int test = 3;

};

struct Coffee : HotDrink {
    void prepare(int volume) override {
        cout << "Ground coffee, pour :"  << volume << "liters" << endl;
    }
};


#endif //UDEMY_DESIGN_PATTERS_HOTDRINK_H
