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
#include "DrinkFactory.h"
#include "HotDrinkFactory.h"

// Factory Method Pattern - A component responsible for the wholesale (not piecewise) creation of object - create everything in one call

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Abstract Factory

//Factory method
//unique_ptr<HotDrink> make_drink(string type)
//{
//    unique_ptr<HotDrink> drink;
//
//    Factory
//
//    return drink;
//}

// Non factory approach
//unique_ptr<HotDrink> make_drink(string type)
//{
//    unique_ptr<HotDrink> drink;
//
//    if (type == "tea"){
//        drink = make_unique<Tea>();
//        drink->prepare(50);
//    }
//
//    else {
//        drink = make_unique<Coffee>();
//        drink->prepare(300);
//    }
//    return drink;
//}

int main()
{
//    auto drink = make_drink("tea");
    DrinkFactory df;
    auto drink = df.make_drink("tea");
    cout << drink->test << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inner Factory
//
//enum class PointType
//{
//    cartesian,
//    polar
//};
//
//class Point {
//    Point(float x, float y) : x(x), y(y) {}
//    float x, y;
//
//private:
//    class PointFactory
//    {
//        PointFactory() {}
//    public:
//        static Point NewCartesian(float x, float y)
//        {
//            return {x, y};
//        }
//
//        static Point NewPolar(float rho, float theta)
//        {
//            return {rho*cos(theta), theta*cos(theta)};
//        }
//    };
//
//public:
//    static PointFactory Factory;
//
//    friend ostream &operator<<(ostream &os, const Point &point)
//    {
//        os << "x: " << point.x << ", y: " << point.y;
//        return os;
//    }
//};
//
//
//
//
//int main() {
//    auto p = Point::Factory.NewPolar(5, M_PI_4);
//    cout << p << endl;
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Factory

//enum class PointType
//{
//    cartesian,
//    polar
//};
//
//class Point {
//    friend class PointFactory; // Open Close Principle broken
//    Point(float x, float y) : x(x), y(y) {}
//public:
//    float x, y;
//
//    friend ostream &operator<<(ostream &os, const Point &point)
//    {
//        os << "x: " << point.x << ", y: " << point.y;
//        return os;
//    }
//};
//
//// "concrete Factory"
//struct PointFactory
//{
//    static Point NewCartesian(float x, float y)
//    {
//        return {x, y};
//    }
//
//    static Point NewPolar(float rho, float theta)
//    {
//        return {rho*cos(theta), theta*cos(theta)};
//    }
//};
//
//
//int main() {
//    auto p = PointFactory::NewPolar(5, M_PI_4);
//    cout << p << endl;
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Factory Method

//enum class PointType
//{
//    cartesian,
//    polar
//};
//
//class Point {
//    Point(float x, float y) : x(x), y(y) {}
//public:
//    float x, y;
//
//    static Point NewCartesian(float x, float y)
//    {
//        return {x, y};
//    }
//
//    static Point NewPolar(float rho, float theta)
//    {
//        return {rho*cos(theta), theta*cos(theta)};
//    }
//
//    friend ostream &operator<<(ostream &os, const Point &point)
//    {
//        os << "x: " << point.x << ", y: " << point.y;
//        return os;
//    }
//};
//
//int main() {
//    auto p = Point::NewPolar(5, M_PI_4);
//    cout << p << endl;
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//enum class PointType
//{
//    cartesian,
//    polar
//};
//
//struct Point {
////    Point(float x, float y) : x(x), y(y) {}
//
//    Point(float a, float b, PointType type = PointType::cartesian)
//    {
//        if (type == PointType::cartesian){
//            x = a;
//            y = b;
//        }
//        else {
//            x = a * cos(b);
//            y = b * cos(b);
//        }
//    }
//
//    float x, y;
//};
//
//
//int main() {
//
//
//    return 0;
//}
