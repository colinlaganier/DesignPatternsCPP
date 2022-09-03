//
// Created by Colin Laganier on 31/08/2022.
//

#ifndef UDEMY_DESIGN_PATTERS_PIMPL_H
#define UDEMY_DESIGN_PATTERS_PIMPL_H

#endif //UDEMY_DESIGN_PATTERS_PIMPL_H

#include <memory>

template<typename T> class pimpl {
private:
    std::unique_ptr<T> impl;
public:
    pimpl();

    ~pimpl();

//    Forwarding constructor
    template<typename ...Args> pimpl(Args&& ...args);
//    template<typename ...Args>
//    pimpl(Args &&...args) : impl(new T{std::forward<Args>(args)...}) {};

    T* operator->();
    T& operator*();


};

