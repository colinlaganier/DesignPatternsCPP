//#define _USE_MATH_DEFINES
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdio>
//#include <fstream>
//#include <boost/lexical_cast.hpp>
//#include <tuple>
//#include <memory>
//#include <cmath>
//#include <map>
//#include "gtest/gtest.h"
//
//using namespace std;
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//struct Renderer
//{
//    virtual string what_to_render_as() const = 0;
//};
//
//struct RasterRenderer : Renderer
//{
//    string what_to_render_as() const override {
//        return "pixels";
//    }
//};
//
//struct VectorRenderer : Renderer
//{
//    string what_to_render_as() const override {
//        return "lines";
//    }
//};
//
//struct Shape
//{
//    const Renderer& renderer;
//    string name;
//
//    explicit Shape(const Renderer& renderer) : renderer(renderer) {};
//
//    string str() const {
//        ostringstream oss;
//        oss << "Drawing" << name << " as " << renderer.what_to_render_as();
//        return oss.str();
//    }
//};
//
//struct Triangle : Shape
//{
//
//    explicit Triangle(const Renderer& renderer) : Shape(renderer)
//    {
//        name = "Triangle";
//    }
//};
//
//struct Square : Shape
//{
//    explicit Square(const Renderer& renderer) : Shape(renderer)
//    {
//        name = "Square";
//    }
//    virtual string str() const = 0;
//};
//
////struct VectorSquare : Square
////{
////    string str() const
////    {
////        // return "Drawing " + name + " as lines";
////        return "Drawing " + name + " as " + renderer.what_to_render_as();
////    }
////};
////
////struct RasterSquare : Square
////{
////    string str() const
////    {
////        return "Drawing " + name + " as " + renderer.what_to_render_as();
////    }
////};
