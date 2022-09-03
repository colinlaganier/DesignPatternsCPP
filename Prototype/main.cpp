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
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
using namespace boost;

// Ways to clone the prototype:
// Deep copy functionality for each object
// Serialize and deserialize object

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Address {
    string street, city;
    int zipcode;

    Address(){};

    Address(const string &street, const string &city, const int zipcode) : street(street), city(city), zipcode(zipcode){};

    Address(const Address &address) : street{address.street}, city{address.city}, zipcode{address.zipcode}{};

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " zipcode: " << address.zipcode;
        return os;
    }

private:
    friend class serialization::access;
    template <class archive>
    void serialize(archive &ar, const unsigned version)
    {
        ar & street;
        ar & city;
        ar & zipcode;
    }
};

struct Contact {
    string name;
//    Address address;
    Address* address;

    Contact(){};
//    Contact(const string &name, const Address &address) : name(name), address(address) {};
    Contact(const string &name, Address *address) : name(name), address(address) {};

//    Copy constructor
//    Contact(const Contact &contact) : name{contact.name}, address{new Address{contact.address->street, contact.address->city, contact.address->zipcode}} {};
    Contact(const Contact &contact) : name{contact.name}, address{new Address{ *contact.address }} {};

    ~Contact() { delete address; }

    friend ostream &operator<<(ostream &os, const Contact &contact ) {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

private:
    friend class serialization::access;
    template <class archive>
    void serialize(archive &ar, const unsigned version)
    {
        ar & name;
        ar & address;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee(const string &name, const int zipcode)
    {
        static Contact p{"", new Address{"123 Main St", "London", 0}};
        return new_employee(name, zipcode, p);
    }
    static unique_ptr<Contact> new_aux_office_employee(const string &name, const int zipcode)
    {
        static Contact p{"", new Address{"321 High St", "London", 0}};
        return new_employee(name, zipcode, p);
    }
private:
    static unique_ptr<Contact> new_employee(const string &name, const int zipcode, const Contact &prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->zipcode = zipcode;
        return result;
    };
};

int main()
{
//    Contact john{"John Doe", new Address{"123 Street", "London", 12345}};
//    Contact jane{john};
//    jane.name = "Jane Smith";
//    jane.address->street = "321 Street";

//    auto john = EmployeeFactory::new_main_office_employee("John Doe", 12345);
//    cout << *john << endl;

    auto clone = [](const Contact &c)
    {
        ostringstream oss;
        archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();

        istringstream iss(s);
        archive::text_iarchive ia(iss);
        Contact result;
        ia >> result;
        return result;
    };

    auto john = EmployeeFactory::new_main_office_employee("John Smith", 12345);
    auto jane = clone(*john);
    jane.name = "Jane Doe";
    cout << * john << endl << jane << endl;

    return 0;
};