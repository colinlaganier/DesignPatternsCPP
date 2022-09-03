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
using namespace std;
using namespace boost;

enum class Language {
    CPP,
    C,
    Rust,
    Javascript
};

enum class Stack {
    frontend,
    backend,
    fullstack
};

class Coder {
    Coder(string name, Stack stack) : name(name), stack(stack) {}
    string name;
    Stack stack;
    Language languages[];

private:

    class CoderFactory {
        CoderFactory() {};
    public:
        static Coder NewFrontendDev(string name, Stack stack) {
            return {}
        }
    };


};