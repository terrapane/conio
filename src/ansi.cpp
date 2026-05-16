/*
 *  ansi.cpp
 *
 *  Copyright (C) 2024, 2026
 *  Terrapane Corporation
 *  All Rights Reserved
 *
 *  Author:
 *      Paul E. Jones <paulej@packetizer.com>
 *
 *  Description:
 *      This module implements the function to produce the various ANSI
 *      escape sequences to reset the terminal and produce color output.
 *
 *  Portability Issues:
 *      None.
 */

#include <cstdint>
#include <string>
#include <string_view>
#include <terra/conio/ansi.h>

namespace Terra::ConIO::ANSI
{

namespace
{

inline constexpr std::string_view CSI = "\033[";
inline constexpr std::string_view SGRT = "m";

}

/*
 *  Foreground()
 *
 *  Description:
 *      Function to return a string to facilitate selection of the specified
 *      foreground color.
 *
 *  Parameters:
 *      color [in]
 *          The selected foreground color.
 *
 *  Returns:
 *      String containing the ANSI sequence to produce the desired foreground
 *      color.
 *
 *  Comments:
 *      None.
 */
std::string Foreground(Color color)
{
    std::string result;

    switch (color)
    {
        case Color::Black:
            result = Black;
            break;
        case Color::Red:
            result = Red;
            break;
        case Color::Green:
            result = Green;
            break;
        case Color::Yellow:
            result = Yellow;
            break;
        case Color::Blue:
            result = Blue;
            break;
        case Color::Magenta:
            result = Magenta;
            break;
        case Color::Cyan:
            result = Cyan;
            break;
        case Color::White:
            result = White;
            break;
        default:
            result = Reset;
            break;
    };

    return result;
}

/*
 *  Background()
 *
 *  Description:
 *      Function to return a string to facilitate selection of the specified
 *      background color.
 *
 *  Parameters:
 *      color [in]
 *          The selected foreground color.
 *
 *  Returns:
 *      String containing the ANSI sequence to produce the desired foreground
 *      color.
 *
 *  Comments:
 *      None.
 */
std::string Background(Color color)
{
    std::string result;

    switch (color)
    {
        case Color::Black:
            result = BlackBackground;
            break;
        case Color::Red:
            result = RedBackground;
            break;
        case Color::Green:
            result = GreenBackground;
            break;
        case Color::Yellow:
            result = YellowBackground;
            break;
        case Color::Blue:
            result = BlueBackground;
            break;
        case Color::Magenta:
            result = MagentaBackground;
            break;
        case Color::Cyan:
            result = CyanBackground;
            break;
        case Color::White:
            result = WhiteBackground;
            break;
        default:
            result = Reset;
            break;
    };

    return result;
}

/*
 *  SelectGraphicRendition()
 *
 *  Description:
 *      Function to produce the Select Graphic Rendition sequence.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      ANSI sequence for the Select Graphic Rendition (SGR).
 *
 *  Comments:
 *      None.
 */
std::string SelectGraphicRendition(SGR sgr)
{
    return std::string(CSI) + std::to_string(static_cast<std::uint8_t>(sgr)) +
           std::string(SGRT);
}

/*
 *  SGRAndColor()
 *
 *  Description:
 *      Function to produce the character sequence to select the specified
 *      Select Graphic Rendition (SGR), foreground color, and background color.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      String containing the ANSI sequence to produce the foreground color.
 *
 *  Comments:
 *      None.
 */
std::string SGRAndColor(SGR sgr, Color background, Color foreground)
{
    return SelectGraphicRendition(sgr) + Background(background) +
           Foreground(foreground);
}

/*
 *  ColorBG256()
 *
 *  Description:
 *      Select the 256-bit background color using the specified color.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      A color table is viewable here:
 *      https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
 */
std::string ColorBG256(std::uint8_t color)
{
    return std::string(CSI) + "48;5;" + std::to_string(color) +
           std::string(SGRT);
}

/*
 *  ColorFG256()
 *
 *  Description:
 *      Select the 256-bit foreground color using the specified color.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      A color table is viewable here:
 *      https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
 */
std::string ColorFG256(std::uint8_t color)
{
    return std::string(CSI) + "38;5;" + std::to_string(color) +
           std::string(SGRT);
}

/*
 *  ColorBG256()
 *
 *  Description:
 *      Select the 256-bit background color using the specified RGB color.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      These are not widely supported by terminals, though it does appear to
 *      work with Windows Terminal.
 */
std::string ColorBG24Bit(std::uint8_t red,
                         std::uint8_t green,
                         std::uint8_t blue)
{
    return std::string(CSI) + "48;2;" + std::to_string(red) + ";" +
           std::to_string(green) + ";" + std::to_string(blue) +
           std::string(SGRT);
}

/*
 *  ColorFG256()
 *
 *  Description:
 *      Select the 256-bit foreground color using the specified RGB color.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      These are not widely supported by terminals, though it does appear to
 *      work with Windows Terminal.
 */
std::string ColorFG24Bit(std::uint8_t red,
                         std::uint8_t green,
                         std::uint8_t blue)
{
    return std::string(CSI) + "38;2;" + std::to_string(red) + ";" +
           std::to_string(green) + ";" + std::to_string(blue) +
           std::string(SGRT);
}

} // namespace Terra::ConIO::ANSI
