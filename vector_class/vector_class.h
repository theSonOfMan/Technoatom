//--------------------------------------
//! \file vector_class.h
//! \brief Contains declarations of vector class functions
//! \author theSonOfMan, 2017
//--------------------------------------

#pragma once
#include <iostream>
// FIXME: Есть такое внегласное правило: сначала все системные инклюды, а потом - свои. Смысл в том, что если ты сделаешь
// что-то не так в своем инклюде (к примеру, не поставишь ; после объявления класса), то ошибки ты будешь видить в системном
// файле и они будут странными. В итоге потратишь время на отладку. Гораздо большая проблема - если будут неявные конфликты имен,
// например в передефайненных макросах.
#include "../my_dump.h"
#include <stdlib.h>
#include <fstream>

template <typename T>
class Vector{
public:

    typedef T value_type; //<type of the value stored in Vector

    // FYI: скорее дефолт, а не стандард.
    //--------------------------------------
    //! Constructor, standard constructor for Vector class
    //--------------------------------------
    Vector();

    //--------------------------------------
    //! Constructor, creates a vector of a particular size
    //! \param vector_size - a size_t value
    //--------------------------------------
    explicit Vector(size_t vector_size);

    //--------------------------------------
    //! Constructor, creates a copy of a Vector
    //! \param that - Vector to be copied
    //--------------------------------------
    Vector(const Vector& that);

    //--------------------------------------
    //! Destructor, default destructor for Vector class
    //--------------------------------------
    ~Vector();

    //--------------------------------------
    //! Swaps a Vector with another Vector
    //! \param that - Vector to be swapped with
    //--------------------------------------
    void swap(Vector& that);

    //--------------------------------------
    //! A copy operator
    //! \param that - a vector to be copied
    //! \return a copied vector
    //--------------------------------------
    const Vector<T>& operator = (const Vector<T>&that);

    // FIXME: В целом, у тебя много документации. Я бы даже скзаал, больше, чем нужно. А то, что будет,
    // если элемента с данным индексом нету - не задокументированно. А это важно.
    //--------------------------------------
    //! A copy operator for a constant vector object
    //! \param index - index of an element to return
    //! \return the element
    //--------------------------------------
    const value_type& operator [] (size_t index) const;

    //--------------------------------------
    //! A operator, which returns a particular element of a vector
    //! \param index - index of an element to return
    //! \return the element
    //--------------------------------------
    value_type& operator [] (size_t index);

    //--------------------------------------
    //! Returns the size of the vector
    //! \return the size of the vector
    //--------------------------------------
    size_t size() const;

    //--------------------------------------
    //! Returns the pointer on the data // FIXME: pointer to
    //! \return the pointer on the data
    //--------------------------------------
    value_type* data_pointer() const;

    //--------------------------------------
    //! Prints the data of the vector in console // FIXME: to console
    //--------------------------------------
    void print_data() const;

    //--------------------------------------
    //! Returns information about the vector
    //! \return a string, which contains the information
    //--------------------------------------
    std::string dump();

    //--------------------------------------
    //! Returns information about the constant vector object
    //! \return a string, which contains the information
    //--------------------------------------
    const std::string dump() const;

private:

    size_t size_;
    value_type *data_;

    std::string print_data_filename() const;

    void*operator new (size_t size, void* where_to_create);

};

#include "vector_class.hpp"
