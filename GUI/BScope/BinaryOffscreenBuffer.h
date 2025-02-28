#ifndef SIDECAR_GUI_BSCOPE_BINARYOFFSCREENBUFFER_H // -*- C++ -*-
#define SIDECAR_GUI_BSCOPE_BINARYOFFSCREENBUFFER_H

#include "OffscreenBuffer.h"

namespace Logger {
class Log;
}

namespace SideCar {
namespace GUI {
namespace BScope {

/** Derivation of OffscreenBuffer that understands how to generate OpenGL point data from Messages::BinaryVideo
    sample data. A true value in a Messages::BinaryVideo message will draw with the color held by BinaryImaging,
    while a false will draw with black (with an alpha of 0.0).

    Supports decimation of the incoming data. The value from
    SampleImaging::getDecimation() controls the amount of decimation that
    occurs.
*/
class BinaryOffscreenBuffer : public OffscreenBuffer {
    using Super = OffscreenBuffer;

public:
    /** Constructor.

        \param points

        \param imaging
    */
    BinaryOffscreenBuffer(int width, int height, int textureType = -1);

    /** Add data points to render in OffscreenBuffer::renderPoints().

        \param msg message containing the data to render
    */
    void addPoints(const Messages::PRIMessage::Ref& msg);
};

} // end namespace BScope
} // end namespace GUI
} // end namespace SideCar

/** \file
 */

#endif
