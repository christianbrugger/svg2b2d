
#include "svg.h"

#include "svgshapes.h"
#include "bspanutil.h"


#include <vector>
#include <memory>

//using namespace svg2b2d;



bool parseSVG(const void* bytes, const size_t sz, BLImage& outImage)
{
    svg2b2d::ByteSpan inChunk(bytes, sz);   // = svg2b2d::chunk_from_data_size(bytes, sz);
    
    // Create a new document
    svg2b2d::SVGDocument doc;

    // Load the document from the data
    doc.readFromData(inChunk);
    
    
    // Draw the document into a IRender
    outImage.create(doc.width(), doc.height(), BL_FORMAT_PRGB32);
    SVGRenderer ctx(outImage);
    doc.draw(ctx);
    ctx.end();
    
    return true;
}