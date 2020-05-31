#pragma once

#include <iostream>

template <typename T>
class scoped_ptr {
private:
    T* ptr_;
public:
    typedef T element_type;

    explicit scoped_ptr(T* ptr = nullptr) : ptr_(ptr) {
        std::cout << "New scoped_ptr" << std::endl;
    }

    scoped_ptr(const scoped_ptr&) = delete;

    scoped_ptr& operator=(const scoped_ptr&) = delete;

    scoped_ptr(scoped_ptr&&) = delete;

    scoped_ptr& operator=(scoped_ptr&&) = delete;

    T* get() const {
        return ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    T* release() {
        auto a = ptr_;
        ptr_ = nullptr;
        return a;
    }

    explicit operator bool() const {
        return ptr_!= nullptr;
    }

    ~scoped_ptr() {
        std::cout << "~scoped_ptr" << std::endl;
        delete ptr_;
    }
};