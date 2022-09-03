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
#include <boost/lexical_cast.hpp>
//#include <boost/serialization/serialization.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include "di.hpp"

using namespace std;
//using namespace boost;

// Singleton - a component that is instantiated only once - for objects that you only want to load once ie expensive constructor code

// Industry standard is a Dependancy Injection container - create dependencies and inject them automatically when required

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum class Importance
{
    primary,
    secondary,
    tertiary
};

template <typename T, typename Key = std::string>
class Multiton
{

public:

    static std::shared_ptr<T> get(const Key& key) {
        const auto it = instances.find(key);
        if (it != instances.end())
        { return it->second; }

        auto instance = make_shared<T>();
        instances[key] = instance;
        return instance;
    }

protected:
    Multiton() = default;
    virtual ~Multiton() = default;

private:
    static map<Key, shared_ptr<T>> instances;

};

class Printer {
public:
    Printer() {
        ++Printer::total_instance_count;
        cout << "A total of " << Printer::total_instance_count << " created" << endl;
    }

    string print_val() { return std::to_string(total_instance_count); }

private:
    static int total_instance_count;
};

// Variables counters init
template <typename T, typename Key>
map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;
int Printer::total_instance_count = 0;

int main() {
    typedef Multiton<Printer, Importance> mt;

    auto main = mt::get(Importance::primary);
    auto aux = mt::get(Importance::secondary);
    auto aux2 = mt::get(Importance::secondary);

//    cout << "main: " << main->print_val() << ", aux: " << aux->print_val() << ", aux2: " << aux2->print_val() << endl;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//struct IFoo
//{
//    virtual string name() = 0;
//};
//
//struct Foo : IFoo
//{
//    static int id;
//
//    Foo() { ++id; }
//
//    string name() override {
//        return "foo "s + lexical_cast<string>(id);
//    }
//};
//
//int Foo::id = 0;
//
//struct Bar
//{
//    std::shared_ptr<IFoo> foo;
//};
//
//int main()
//{
//    auto injector = di::make_injector(
//            di::bind<IFoo>().to<Foo>().in(di::singleton));
//
//    auto bar1 = injector.create<std::shared_ptr<Bar>>();
//    auto bar2 = injector.create<std::shared_ptr<Bar>>();
//
//    cout << bar1->foo->name() << endl;
//    cout << bar2->foo->name() << endl;
//
//    cout << boolalpha << (bar1->foo.get() == bar2->foo.get()) << endl;
//
//    return 0;
//};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//class Database
//{
//public:
//    virtual int get_population(const string &name) = 0;
//
//};
//
//class SingletonDatabase : public Database
//{
//
//    map<string, int> capitals;
//
//    SingletonDatabase()
//    {
//        cout << "Initializing Database" << endl;
//        ifstream ifs("capitals.txt");
//
//        string s, s2;
//
//        while(getline(ifs, s))
//        {
//            getline(ifs, s2);
//            int pop = lexical_cast<int>(s2);
//            capitals[s] = pop;
//        }
//    }
//
//
//public:
//    SingletonDatabase(SingletonDatabase const&) = delete;
//    void operator=(SingletonDatabase const&) = delete;
//
//    static SingletonDatabase& get()
//    {
//        static SingletonDatabase db;
//        return db;
//    }
//
//    int get_population(const string &city)
//    {
//        if (capitals.count(city))
//            return capitals[city];
//        return -1;
//    }
//};
//
//class DummyDatabase : public Database
//{
//    map<string, int> capitals;
//
//public:
//    DummyDatabase()
//    {
//        capitals["alpha"] = 1;
//        capitals["beta"] = 1;
//        capitals["gamma"] = 1;
//    }
//
//    int get_population(const string &name) override {
//        return capitals[name];
//    }
//};
//
//struct SingletonRecordFinder
//{
//    int total_population(vector<string> names)
//    {
//        int result{0};
//        for (auto& name : names)
//        {
//            result += SingletonDatabase::get().get_population(name);
//        }
//        return result;
//    }
//};
//
//struct ConfigurableRecordFinder
//{
//    Database &db;
//
//    ConfigurableRecordFinder(Database &db) : db(db) {}
//
//    int total_population(vector<string> names)
//    {
//        int result{0};
//        for (auto& name : names)
//        {
//            result += db.get_population(name);
//        }
//        return result;
//    }
//};
//
//TEST(RecordFinderTests, SingletonTotalPopulationTest)
//{
//    SingletonRecordFinder rf;
//    vector<string> names {"Paris","New York"};
//    int tp = rf.total_population(names);
//    EXPECT_EQ(1231345+124314, tp);
//}
//
//TEST(RecordFinderTests, DependantTotalPopulationTest)
//{
//    DummyDatabase db;
//    ConfigurableRecordFinder rf{db};
//    EXPECT_EQ(2, rf.total_population(vector<string>{"alpha", "gamma"}));
//}
//
//int main(int ac, char* av[])
//{
////    cout << SingletonDatabase::get().get_population("Tokyo") << endl;
//    testing::InitGoogleTest(&ac, av);
//    return RUN_ALL_TESTS();
//}