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

// Adapter - getting the interface you want from the interface give by the system


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//struct Square
//{
//    int side{ 0 };
//
//
//    explicit Square(const int side)
//            : side(side)
//    {
//    }
//};
//
//struct Rectangle
//{
//    virtual int width() const = 0;
//    virtual int height() const = 0;
//
//    int area() const
//    {
//        return width() * height();
//    }
//};
//
//struct SquareToRectangleAdapter : Rectangle
//{
//    int rect_width, rect_height;
//
//    SquareToRectangleAdapter(const Square& square)
//            : rect_width(square.side), rect_height(square.side){};
//
//    int height() const override{
//        return SquareToRectangleAdapter::rect_height;
//    }
//    int width() const override{
//        return SquareToRectangleAdapter::rect_width;
//    }
//
//    int area() const
//    {
//        return width() * height();
//    }
//};


struct Square
{
    int side{ 0 };


    explicit Square(const int side)
            : side(side)
    {}
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    SquareToRectangleAdapter(const Square& square)
            : square(square) {}

    int width() const override
    {
        return square.side;
    }

    int height() const override
    {
        return square.side;
    }

    const Square& square;
};
