#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <tuple>
using namespace std;
using namespace boost;

// Builder provides an API for object construction if complex

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Person.h"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main() {

    Person p = Person::create()
            .lives().at("123 road street").with_postcode("12345").in("London")
            .works().at("Company").as_a("Dev").earning(123456);

    return 0;
};

// Groovy style builder

//struct Tag
//{
//    string name, text;
//    vector<Tag> children;
//    vector<pair<string,string>> attributes;
//
//    friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
//    {
//        os << "<" << tag.name;
//
//        for (const auto& att : tag.attributes)
//            os << " " << att.first << "=\"" << att.second << "\"";
//
//        if (tag.children.size() == 0 && tag.text.length() == 0)
//        {
//            os << "/>" << std::endl;
//        }
//        else
//        {
//            os << ">" << std::endl;
//
//            if (tag.text.length())
//                os << tag.text << std::endl;
//
//            for (const auto& child : tag.children)
//                os << child;
//
//            os << "</" << tag.name << ">" << std::endl;
//        }
//
//        return os;
//    }
//
//protected:
//public:
//    Tag(const string &name, const string &text) : name(name), text(text) {}
//
//    Tag(const string &name, const vector<Tag> &children) : name(name), children(children) {}
//};
//
//struct P : Tag
//{
//    P(const string &text) : Tag("p", text) {}
//    P(initializer_list<Tag> children) : Tag("p", children) {}
//};
//
//struct IMG : Tag
//{
//    explicit IMG(const string& url) : Tag("img", "")
//    {
//        attributes.emplace_back(make_pair("src", url));
//    }
//};
//
//int main()
//{
//    cout << P { IMG { "http://www.google.com"}} << endl;
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Demo

//struct HtmlBuilder;
//
//struct HtmlElement
//{
//    string name, text;
//    vector<HtmlElement> elements;
//    const size_t indent_size = 2;
//
//    HtmlElement() {};
//
//    HtmlElement(const string &name, const string &text) : name(name), text(text) {}
//
//    string str(int indent = 0) const {
//        ostringstream oss;
//        string i(indent_size*indent, ' ');
//        oss << i << "<" << name << ">" << endl;
//        if (text.size() > 0)
//            oss << string(indent_size*(indent + 1), ' ') << text << endl;
//
//        for (const auto& e : elements)
//            oss << e.str(indent + 1);
//
//        oss << i << "</" << name << ">" << endl;
//        return oss.str();
//    }
//
////    static HtmlBuilder build(string root_name)
////    {
////        return {root_name};
////    }
//};
//
//struct HtmlBuilder
//{
//    HtmlElement root;
//
//    HtmlBuilder(string root_name)
//    {
//        root.name = root_name;
//    }
//
//    HtmlBuilder& add_child(string child_name, string child_text)
//    {
//        HtmlElement e{child_name, child_text};
//        root.elements.emplace_back(e);
//        return *this;
//    }
//
//    string str() const { return root.str(); }
//};
//
//int main()
//{
//    auto text = "hello";
//    string output;
//    output += "<p>";
//    output += text;
//    output += "</p>";
//    cout << output << endl;
//
////    string words[] = {"hello", "world"};
////    // output string stream - string buffer that contains a sequence of characters
////    ostringstream oss;
////    oss << "<ul>";
////    for (auto w : words)
////        oss << "<li>" << w << "</li>";
////    oss << "</ul>";
////    cout << oss.str() << endl;
//
//    HtmlBuilder builder{"ul"};
//    builder.add_child("li", "hello").add_child("li", "world");
//    cout << builder.str() << endl;
//
////    auto builder2 = HtmlElement::build("ul").add_child("","");
////    cout << builder2.str() << endl;
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////