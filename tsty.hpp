/*!
 *  @author Richard Everhart
 *  @date   July 2017
 *
 *  Declarations and template definitions for all tsty library 
 *  functions
!*/

#ifndef TSTY_HPP__
#define TSTY_HPP__

#include <type_traits>

namespace tsty {

//! Rudimentary structure for storing RGB color values.
struct Rgb {
    unsigned char r = 0, g = 0, b = 0;

    //! Constructor for initializing r, g, b values from a hexadecimal
    explicit Rgb(unsigned int hex);

    /*! 
     *  Method for acquiring a hexadecimal representation of the rgb color 
     *  data.
     *
     *  @return An unsigned integer that is the hexadecimal representation
    !*/
    unsigned int hex();
};
typedef Rgb rgb;

}

#endif
