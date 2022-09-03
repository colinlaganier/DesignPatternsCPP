#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <tuple>
#include <memory>
#include <cmath>
#include <map>
#include "gtest/gtest.h"

using namespace std;
//using namespace boost;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Composite - mechanism for treating individual objects and compositions of objects in a uniform manner

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//CRTP - curiously recurring template pattern
template <typename Self>
struct SomeNeuron
{
    template <typename T> void connect_to(T&  other)
    {

    }
};

struct Neuron
{
    vector<Neuron*> in, out;
    unsigned int id;

    Neuron()
    {
        static int id{1};
        this->id = id++;
    }

    void connect_to(Neuron& other)
    {
        out.push_back(&other);
        other.in.push_back(this);
    }

    friend ostream &operator<<(ostream &os, const Neuron &obj) {
        for (Neuron* n : obj.in) {
            os << n->id << "\t-->\t[" << obj.id << "]" << endl;
        }
        for (Neuron* n : obj.out) {
            os << "[" << obj.id << "]\t-->\t" << n->id << endl;
        }
        return os;
    }
};

struct NeuronLayer : vector<Neuron>
{
    NeuronLayer(int count)
    {
        while (count --> 0)
            emplace_back(Neuron{});
    }

    friend ostream &operator<<(ostream &os, const NeuronLayer &obj) {
        for (auto& n : obj) os  << n;
        return os;
    }
};

int main()
{
    Neuron n1, n2;
    n1.connect_to(n2);
    cout << n1 << n2  << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//struct GraphicObject
//{
//    virtual void draw() = 0;
//};
//
//struct Circle : GraphicObject
//{
//    void draw() override {
//        cout << "Drawing a circle" << endl;
//    }
//};
//
//struct Group : GraphicObject
//{
//    string name;
//    vector<GraphicObject*> objects;
//
//    Group(const string &name) : name(name) {}
//
//    void draw() override {
//        cout << "Group " << name.c_str() << "  contains: " << endl;
//        for (auto&& o : objects)
//            o->draw();
//    }
//};
//
//int main()
//{
//    Group root("root");
//    Circle c1, c2;
//    root.objects.push_back(&c1);
//    root.objects.push_back(&c2);
//
//    Group subgroup("sub");
//    subgroup.objects.push_back(&c1);
//
//    root.objects.push_back(&subgroup);
//    root.draw();
//    return 0;
//}