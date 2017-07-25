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
#include <string>

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


//! Enum containing flags representing various ANSI-Supported text emphasis
enum Emphasis {
    NORMAL          = 0x000001,
    BOLD            = 0x000002,
    FAINT           = 0x000004,
    ITALIC          = 0x000008,
    UNDERLINE       = 0x000010,
    SLOW_BLINK      = 0x000020,
    FAST_BLINK      = 0x000040,
    NEGATIVE        = 0x000080,
    CONCEAL         = 0x000100,
    CROSS_OUT       = 0x000200,
    FRAKTUR         = 0x000400,
    NO_BOLD         = 0x000800,
    NO_COLOR        = 0x001000,
    NO_ITALIC       = 0x002000,
    NO_UNDERLINE    = 0x004000,
    POSITIVE        = 0x008000,
    REVEAL          = 0x010000,
    NO_CROSS_OUT    = 0x020000,
    FRAME           = 0x040000,
    ENCIRCLE        = 0x080000,
    OVERLINE        = 0x100000,
    NO_FRAME        = 0x200000,
    NO_OVERLINE     = 0x400000
};

/*!
 *  Sets the current emphasis of all subsequent outputted text to correspond to
 *  the emphasis specified by flags.
 *
 *  Example usage:
 *  @code
 *      emphasis(ITALIC | NEGATIVE | FRAME);
 *  @endcode
 *
 *  @param flags    A bit flag specifying the emphasis
!*/
void emphasis_on(unsigned int flags);

/*!
 *  Sets the current emphasis of all subsequent outputted text to correspond to
 *  the emphasis specified by a variadic list of elements n.
 *
 *  Example usage:
 *  @code
 *      emphasis(ITALIC, NEGATIVE, FRAME);
 *  @endcode
 *
 *  @param n    A variadic list specifying the emphasis
!*/
void emphasis_on(Emphasis n...);

//! Turns off any emphasis that may have been set previously using emphasis_on().
void emphasis_off();
}

#endif
