//--------------------------------------
//! \file vector_class.h
//! \brief Contains declarations of vector class functions
//! \author theSonOfMan, 2017
//--------------------------------------

#pragma once
#include <iostream>

class Vector{
public:

    typedef int value_type; //<type of the value stored in Vector

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
    const Vector& operator = (const Vector&that);

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
    //! Returns the pointer on the data
    //! \return the pointer on the data
    //--------------------------------------
    value_type* data_pointer() const;

    //--------------------------------------
    //! Prints the data of the vector in console
    //--------------------------------------
    void print_data();

    //--------------------------------------
    //! Returns information about the vector
    //! \return a string, which contains the information
    //--------------------------------------
    std::string dump();

private:

    size_t size_;
    value_type *data_;

    void*operator new (size_t size, void* where_to_create);

};