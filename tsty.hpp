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
typedef Emphasis emphasis;

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

//! Turns off any emphasis that may have been set previously
void emphasis_off();

/*!
 *  Returns a string representing an ANSI escape sequence that may be printed
 *  in the future to set the emphasis.
 *
 *  Example usage:
 *  @code
 *      std::string str = ansi_emphasis(ITALIC | BOLD);
 *      std::cout << str << "Styled text!" << std::endl;
 *  @endcode
 *
 *  @param flags    A bit flag specifying the emphasis
 *
 *  @return A string representing an ANSI escape sequence that may be pinted in
 *          the future to set the text emphasis.
!*/
std::string ansi_emphasis(unsigned int flags);

/*!
 *  Returns a string representing an ANSI escape sequence that may be printed
 *  in the future to set the emphasis.
 *
 *  Example usage:
 *  @code
 *      std::string str = ansi_emphasis(ITALIC, BOLD);
 *      std::cout << str << "Styled text!" << std::endl;
 *  @endcode
 *  
 *  @param n    A variadic list specifying the emphasis
 *
 *  @return A string representing an ANSI escape sequence that may be printed
 *          in the future to set the text emphasis.
!*/
std::string ansi_emphasis(Emphasis n...);

/*!
 *  Sets the background and foreground colors of all subsequent outputted text
 *  to correspond to the values specified by fg and bg, respectively.
 * 
 *  Example usage:
 *  @code
 *      color_on(rgb(127, 127, 255), rgb(255, 127, 127));
 *  @endcode
 *
 *  @param fg   A rgb color value specifying the desired foreground color
 *  @param bg   A rgb color value specifying the desired background color
!*/
void color_on(rgb fg, rgb bg);

//! Turns off any color that may have been set previously
void color_off();

/*!
 *  Returns a string representing an ANSI escape sequence that may be printed
 *  in the future to set the text color.
 *  
 *  Example usage:
 *  @code
 *      std::string str = ansi_color(rgb(0, 0, 0), rgb(255, 255, 255));
 *      std::cout << str << "Black text on a white background!" << std::endl;
 *  @endcode
 *
 *  @param fg   A rgb color value specifying the desired foreground color
 *  @param bg   A rgb color value specifying the desired background color
 *
 *  @return A string representing an ANSI escape sequence that may be printed
 *          in the future to set the text color.
!*/
ansi_color(rgb fg, rgb bg);

/*!
 *  Sets the foreground color of all subsequent outputted text to correspond to
 *  the value specified by fg
 * 
 *  Example usage:
 *  @code
 *      fg_color_on(rgb(127, 127, 255));
 *  @endcode
 *
 *  @param fg   A rgb color value specifying the desired foreground color
!*/
void fg_color_on(rgb fg);

/*!
 *  Returns a string representing an ANSI escape sequence that may be printed
 *  in the future to set the text foreground color.
 * 
 *  Example usage:
 *  @code
 *      std::string str = ansi_fg_color(rgb(255, 255, 255));
 *      std::cout << str << "White text!" << std::endl;
 *  @endcode
 *
 *  @param fg   A rgb color value specifying the desired foreground color
!*/
void ansi_fg_color(rgb fg);

/*!
 *  Sets the background color of all subsequent outputted text to correspond to
 *  the value specified by bg
 * 
 *  Example usage:
 *  @code
 *      bg_color_on(rgb(127, 127, 255));
 *  @endcode
 *
 *  @param bg   A rgb color value specifying the desired background color
!*/
void bg_color_on(rgb bg);

/*!
 *  Returns a string representing an ANSI escape sequence that may be printed
 *  in the future to set the text background color.
 * 
 *  Example usage:
 *  @code
 *      std::string str = ansi_bg_color(rgb(0, 0, 0));
 *      std::cout << str << "Text on a black background!" << std::endl;
 *  @endcode
 *
 *  @param bg   A rgb color value specifying the desired background color
!*/
void ansi_bg_color(rgb bg);
}

#endif
