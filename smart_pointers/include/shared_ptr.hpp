#pragma once

#include <iostream>

template <typename T>
class shared_ptr {
private:
    int* count_;
    T* ptr_;
public:
    typedef T element_type;
    explicit shared_ptr(T* ptr = nullptr) : ptr_(ptr), count_(nullptr) {
        std::cout << "New shared_ptr" << std::endl;
        if (ptr != nullptr) {
            count_ = new int{1};
        }
    }
    shared_ptr(const shared_ptr& tmp) : count_(tmp.count_), ptr_(tmp.ptr_) {
        std::cout << "Copy shared_ptr" << std::endl;
        if (count_ != nullptr) {
            (*count_)++;
        }
    }
    shared_ptr& operator=(const shared_ptr& tmp) {
        if (this != &tmp) {
            std::cout << "Copy shared_ptr" << std::endl;
            if (count_ != nullptr) {
                (*count_)--;
                if (*count_ == 0) {
                    delete ptr_;
                    delete count_;
                }
            }
            count_ = tmp.count_;
            (*count_)++;
            ptr_ = tmp.ptr_;
        }
        return *this;
    }
    T* get() const {
        return ptr_;
    }
    T& operator*() const {
        return *ptr_;
    }
    T* operator -> () const {
        return ptr_;
    }
    void reset(T* other = nullptr) {
        if (count_ != nullptr) {
            (*count_)--;
            if (*count_ == 0) {
                delete ptr_;
                delete count_;
            }
            count_ = nullptr;
        }
        if (other != nullptr) {
            count_ = new int{1};
        }
        ptr_ = other;
    }
    explicit operator bool() const {
        return ptr_ != nullptr;
    }
    ~shared_ptr() {
        std::cout << "~shared_ptr" << std::endl;
        if (count_ == nullptr) {
            return;
        }
        (*count_)--;
        if (*count_ == 0) {
            delete ptr_;
            delete count_;
        }
    }
};