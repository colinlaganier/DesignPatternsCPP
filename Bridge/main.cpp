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

// Bridge - mechanism that decouples an interface from an implementation

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct RasterRenderer : Renderer
{
    string what_to_render_as() const override {
        return "pixels";
    }
};

struct VectorRenderer : Renderer
{
    string what_to_render_as() const override {
        return "lines";
    }
};

struct Shape
{
    const Renderer& renderer;
    string name;

    explicit Shape(const Renderer& renderer) : renderer(renderer) {};

    string str() const {
        ostringstream oss;
        oss << "Drawing " << name << " as " << renderer.what_to_render_as();
        return oss.str();
    }
};

struct Triangle : Shape
{

    explicit Triangle(const Renderer& renderer) : Shape(renderer)
    {
        name = "Triangle";
    }
};

struct Square : Shape
{
    explicit Square(const Renderer& renderer) : Shape(renderer)
    {
        name = "Square";
    }
};

//struct Renderer
//{
//    virtual string what_to_render_as() const = 0;
//};
//
//struct Shape
//{
//    string name;
//    const Renderer& renderer;
//
//    Shape(const Renderer& renderer): renderer{renderer} {
//    }
//
//    string str() const
//    {
//        ostringstream oss;
//        oss << "Drawing " << name << " as "
//            << renderer.what_to_render_as();
//        return oss.str();
//    }
//};
//
//struct Triangle : Shape
//{
//    explicit Triangle(const Renderer& renderer)
//            : Shape{renderer}
//    {
//        name = "Triangle";
//    }
//};
//
//struct Square : Shape
//{
//    explicit Square(const Renderer& renderer)
//            : Shape{renderer}
//    {
//        name = "Square";
//    }
//};
//
//struct RasterRenderer : Renderer
//{
//    string what_to_render_as() const override
//    {
//        return "pixels";
//    }
//};
//
//struct VectorRenderer : Renderer
//{
//    string what_to_render_as() const override
//    {
//        return "lines";
//    }
//};

//#include "gtest/gtest.h"

//#include "helpers/iohelper.h"

//#include "exercise.cpp"

namespace
{
    class Evaluate : public testing::Test
    {
    };

    TEST_F(Evaluate, SimpleTest)
    {
        ASSERT_EQ("Drawing Square as lines",
                  Square{VectorRenderer{}}.str());
    }

} // namespace

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//struct Renderer
//{
//    virtual void render_circle(float x, float y, float radius) = 0;
//};
//
//struct VectorRederer : Renderer
//{
//    void render_circle(float x, float y, float radius) override {
//        cout << "Rendering a vectorized circle of radius " << radius << endl;
//    }
//};
//
//struct RasterRenderer : Renderer
//{
//    void render_circle(float x, float y, float radius) override {
//        cout << "Rendering a rasterized circle of radius " << radius << endl;
//    }
//};
//
//struct Shape
//{
//protected:
//    Renderer& renderer;
//    explicit Shape(Renderer &renderer) : renderer(renderer) {}
//public:
//    virtual void draw() = 0;
//    virtual void resize(float factor) = 0;
//};
//
//struct Circle : Shape
//{
//    float x, y, radius;
//    Circle(Renderer &renderer, float x, float y, float radius) : Shape(renderer), x{x}, y{y}, radius{radius} {}
//
//    void draw() override {
//        renderer.render_circle(x,y,radius);
//    }
//
//    void resize(float factor) override {
//        radius *= factor;
//    }
//};
//
//int main()
//{
//    RasterRenderer rr;
//    Circle raster_circle{rr, 12, 3, 6};
//    raster_circle.resize(1.2);
//    raster_circle.draw();
//
//    return 0;
//}