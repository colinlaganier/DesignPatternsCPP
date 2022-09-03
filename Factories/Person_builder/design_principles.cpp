#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <tuple>
using namespace std;
using namespace boost;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dependancy Inversion Principle

enum class Relationship {parent, child, sibling};

struct Person
{
    string name;
};

struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override {
        vector<Person> result;

        for (auto&& [first, rel, second] : relations)
        {
            if (first.name == name)
                result.push_back(second);
        }

        return result;
    }
};

struct Research //high-level
{
//    Research(Relationships& relationships)
//    {
//        auto& relations = relationships.relations;
//        for (auto&& [first, relation, second] : relations)
//        {
//            if (first.name == "John" && relation == Relationship::parent)
//                cout << "John has a child called " << second.name << endl;
//        }
//    }

    Research(RelationshipBrowser& browser) {
        for (auto& child : browser.find_all_children_of("John"))
            cout << "John has a child called " << child.name << endl;
    }

};

int main()
{
    Person parent{"John"};
    Person child1{"Bob"};
    Person child2{"Chris"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interface Segregation Principle

//struct Document;
//
//struct IPrinter
//{
//    virtual void print(Document& doc) = 0;
//};
//
//struct IScanner
//{
//    virtual void scan(Document& doc) = 0;
//};
//
//struct IFax
//{
//    virtual void fax(Document& doc) = 0;
//};
//
//struct Printer : IPrinter
//{
//    void print(Document& doc) override {
//
//    }
//};
//
//struct IMachine : IPrinter, IScanner {};
//
//struct Machine : IMachine
//{
//    IPrinter& printer;
//    IScanner& scanner;
//
//    Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {};
//
//    void print(Document &doc) override {
//        printer.print(doc);
//    }
//
//    void scan(Document &doc) override {
//        scanner.scan(doc);
//    }
//};
//
//int main()
//{
//    return 0;
//};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Liskov Substitution Principle

//class Rectangle
//{
//protected:
//    int width, height;
//
//public:
//    Rectangle(int width, int height) : width(width), height(height) {}
//
//    int getWidth() const {
//        return width;
//    }
//
//    virtual void setWidth(int width) {
//        Rectangle::width = width;
//    }
//
//    int getHeight() const {
//        return height;
//    }
//
//    virtual void setHeight(int height) {
//        Rectangle::height = height;
//    }
//
//    int area() const { return width * height; };
//};
//
//class Square : public Rectangle
//{
//public:
//    Square(int size) : Rectangle(size, size) {}
//
//    void setWidth(int width) override {
//        this->width = this->height = width;
//    }
//
//    void setHeight(int height) override {
//        this->width = this->height = height;
//    }
//};
//
//void process(Rectangle& r){
//    int w = r.getWidth();
//    r.setHeight(10);
//
//    cout << "expected area: " << (w*10) << ", got: " << r.area();
//
//}
//
//int main()
//{
//    Rectangle rectangle{3,4};
//    process(rectangle);
//    return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Open-Closed Principle

//enum class Color {red, green, blue};
//enum class Size {small, medium, large};

//struct Product
//{
//    string name;
//    Color color;
//    Size size;
//};
//
//struct ProductFilter
//{
//    vector<Product*> by_color(vector<Product*> products, Color color)
//    {
//        vector<Product*> filtered_products;
//        for (auto& item : products)
//            if (item->color == color)
//                filtered_products.push_back(item);
//        return filtered_products;
//    }
//
//    void print_products(vector<Product*> products)
//    {
//        for (auto& item : products)
//            cout << item->name << endl;
//    }
//};
//
//template <typename T> struct Specification
//{
//    virtual bool is_satisfied(T* item) = 0;
//
//};
//
//template <typename T> struct Filter
//{
//    virtual vector<T*> filter(vector<T*> items, Specification<T> &spec) = 0;
//};
//
//template <typename T> struct AndSpecification : Specification<T>
//{
//    Specification<T>& first;
//    Specification<T>& second;
//
//    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}
//
//    bool is_satisfied(T *item) override {
//        return first.is_satisfied(item) && second.is_satisfied(item);
//    }
//};
//
//struct BetterFilter : Filter<Product>
//{
//    vector<Product* > filter(vector<Product* > items, Specification<Product> &spec) override {
//        vector<Product*> result;
//        for (auto& item : items)
//        {
//            if (spec.is_satisfied(item))
//                result.push_back(item);
//        }
//        return result;
//    }
//};
//
//struct ColorSpecification : Specification<Product>
//{
//    Color color;
//    ColorSpecification(Color color) : color(color) {};
//
//    bool is_satisfied(Product *item) override {
//        return item->color == color;
//    }
//};
//
//struct SizeSpecification : Specification<Product>
//{
//    Size size;
//    SizeSpecification(const Size size) : size(size) {};
//
//    bool is_satisfied(Product *item) override {
//        return item->size == size;
//    }
//};
//
//int main()
//{
//    Product apple{"apple", Color::green, Size::small};
//    Product tree{"tree", Color::green, Size::large};
//    Product house{"house", Color::red, Size::large};
//
//
//    vector<Product*> product_range{&apple, &tree, &house};
//
//    BetterFilter bf;
//    ColorSpecification green(Color::green);
//    SizeSpecification large(Size::large);
//    AndSpecification<Product> green_and_large(green, large);
//
//    for (auto& item : bf.filter(product_range,green_and_large))
//        cout << item->name << endl;
////    filtering.print_products(green_products);
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Single Responsibility Problem

//struct Journal
//{
//    string title;
//    vector<string> entries;
//
//    Journal(const string &title) : title(title) {}
//
//    void add_entry(const string& entry)
//    {
//        static int count = 1;
//        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
//    }
//};
//
//struct PersistenceManager
//{
//    static void save(const Journal& journal, const string& file_name)
//    {
//        ofstream ofs(file_name);
//        for (auto& elem : journal.entries)
//            ofs << elem << endl;
//    }
//};
//
//int main() {
//    PersistenceManager manager;
//    Journal journal{"Dear diary"};
//    journal.add_entry("Another entry");
//    journal.add_entry("Another one");
//
//    manager.save(journal, "first_journal.txt");
//
//    return 0;
//}
