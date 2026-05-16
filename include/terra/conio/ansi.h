/*
 *  ansi.h
 *
 *  Copyright (C) 2024, 2026
 *  Terrapane Corporation
 *  All Rights Reserved
 *
 *  Author:
 *      Paul E. Jones <paulej@packetizer.com>
 *
 *  Description:
 *      This file defines functions, types, etc. to facilitate ANSI control
 *      code output, including color.  The specification for these control
 *      codes includes ECMA-48, ISO/IEC 6429, FIPS 86, ANSI X3.64, and
 *      JIS X 0211.
 *
 *      One can use the library to construct strings or directly with the
 *      iostream library like this:
 *          std::cout << Terra::ConIO::ANSI::Red << "Red Text";
 *          std::cout << Terra::ConIO::ANSI::Italics << "Italics";
 *      See the comment "Named Select Graphic Rendition functions" below.
 *
 *      See also: https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
 *
 *  Portability Issues:
 *      None.
 */

#pragma once

#include <ostream>
#include <cstdint>
#include <string>
#include <string_view>

namespace Terra::ConIO::ANSI
{

// Select Graphic Rendition (not all terminals support all modes)
enum class SGR : std::uint8_t
{
    Reset = 0,
    Bold = 1,           // Increases brightness; bold black = gray
    Faint = 2,          // Decreases brightness
    Italic = 3,
    Underline = 4,
    SlowBlink = 5,
    RapidBlink = 6,
    ReverseVideo = 7,
    Conceal = 8,
    Strike = 9,
    PrimaryFont = 10,
    AltFont1 = 11,
    AltFont2 = 12,
    AltFont3 = 13,
    AltFont4 = 14,
    AltFont5 = 15,
    AltFont6 = 16,
    AltFont7 = 17,
    AltFont8 = 18,
    AltFont9 = 19,
    Gothic = 20,
    DoubleUnderline = 21,
    NormalIntensity = 22,
    NormalFont = 23,
    NoUnderline = 24,
    NoBlink = 25,
    Proportional = 26,
    NoReverseVideo = 27,
    NoConceal = 28,
    NoStrike = 29,
    BlackFG = 30,
    RedFG = 31,
    GreenFG = 32,
    YellowFG = 33,
    BlueFG = 34,
    MagentaFG = 35,
    CyanFG = 36,
    WhiteFG = 37,
    DefaultFG = 39,
    BlackBG = 40,
    RedBG = 41,
    GreenBG = 42,
    YellowBG = 43,
    BlueBG = 44,
    MagentaBG = 45,
    CyanBG = 46,
    WhiteBG = 47,
    DefaultBG = 49,

    // The following are non-standard, but widely supported; they can be
    // produced by sending bold + color, as well, and are thus redundant
    BrightBlackFG = 90,
    BrightRedFG = 91,
    BrightGreenFG = 92,
    BrightYellowFG = 93,
    BrightBlueFG = 94,
    BrightMagentaFG = 95,
    BrightCyanFG = 96,
    BrightWhiteFG = 97,
    BrightBlackBG = 100,
    BrightRedBG = 101,
    BrightGreenBG = 102,
    BrightYellowBG = 103,
    BrightBlueBG = 104,
    BrightMagentaBG = 105,
    BrightCyanBG = 106,
    BrightWhiteBG = 107
};

// Basic color choices; while color is a subset of SGR sequences, this enum
// exists for convenience since it is used more frequently
enum class Color : std::uint8_t
{
    Black = 0,
    Red = 1,
    Green = 2,
    Yellow = 3,
    Blue = 4,
    Magenta = 5,
    Cyan = 6,
    White = 7,
    Default = 9
};

// Color and style ANSI sequences
inline constexpr std::string_view Reset = "\033[0m";
inline constexpr std::string_view Bold = "\033[1m";
inline constexpr std::string_view Faint = "\033[2m";
inline constexpr std::string_view Italic = "\033[3m";
inline constexpr std::string_view Underline = "\033[4m";
inline constexpr std::string_view SlowBlink = "\033[5m";
inline constexpr std::string_view RapidBlink = "\033[6m";
inline constexpr std::string_view ReverseVideo = "\033[7m";
inline constexpr std::string_view Conceal = "\033[8m";
inline constexpr std::string_view Strike = "\033[9m";
inline constexpr std::string_view DoubleUnderline = "\033[21m";
inline constexpr std::string_view NormalIntensity = "\033[22m";
inline constexpr std::string_view NormalFont = "\033[23m";
inline constexpr std::string_view NoUnderline = "\033[24m";
inline constexpr std::string_view NoBlink = "\033[25m";
inline constexpr std::string_view NoReverseVideo = "\033[27m";
inline constexpr std::string_view NoConceal = "\033[28m";
inline constexpr std::string_view NoStrike = "\033[29m";
inline constexpr std::string_view Black = "\033[30m";
inline constexpr std::string_view Gray = "\033[1;30m";
inline constexpr std::string_view Red = "\033[31m";
inline constexpr std::string_view Green = "\033[32m";
inline constexpr std::string_view Yellow = "\033[33m";
inline constexpr std::string_view Blue = "\033[34m";
inline constexpr std::string_view Magenta = "\033[35m";
inline constexpr std::string_view Cyan = "\033[36m";
inline constexpr std::string_view White = "\033[37m";
inline constexpr std::string_view Default = "\033[39m";
inline constexpr std::string_view BlackBackground = "\033[40m";
inline constexpr std::string_view RedBackground = "\033[41m";
inline constexpr std::string_view GreenBackground = "\033[42m";
inline constexpr std::string_view YellowBackground = "\033[43m";
inline constexpr std::string_view BlueBackground = "\033[44m";
inline constexpr std::string_view MagentaBackground = "\033[45m";
inline constexpr std::string_view CyanBackground = "\033[46m";
inline constexpr std::string_view WhiteBackground = "\033[47m";
inline constexpr std::string_view HideCursor = "\033[?25l";
inline constexpr std::string_view ShowCursor = "\033[?25h";
inline constexpr std::string_view ClearLineToEnd = "\033[0K";
inline constexpr std::string_view ClearLineAll = "\033[2K";

// Produce the given background color
std::string Background(Color color);

// Produce the given foreground color
std::string Foreground(Color color);

// Produce the desired Select Graphic Rendition (SGR) sequence
std::string SelectGraphicRendition(SGR sgr);

// Specify SGR, foreground color, and background color
std::string SGRAndColor(SGR sgr, Color background, Color Foreground);

// Specify 256-bit background color
std::string ColorBG256(std::uint8_t color);

// Specify 256-bit foreground color
std::string ColorFG256(std::uint8_t color);

// Specify background color using 24-bit RGB values
std::string ColorBG24Bit(std::uint8_t red,
                         std::uint8_t green,
                         std::uint8_t blue);

// Specify foreground color using 24-bit RGB values
std::string ColorFG24Bit(std::uint8_t red,
                         std::uint8_t green,
                         std::uint8_t blue);

} // namespace Terra::ConIO::ANSI
