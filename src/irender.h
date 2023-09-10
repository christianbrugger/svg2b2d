#pragma once

#include "blend2d.h"

using IRender = BLContext;

// IDrawable
// Base interface for anything that might have an effect
// on a drawing context.
// 
struct IDrawable
{
    virtual ~IDrawable() {}

    virtual void draw(IRender& ctx) const = 0;
};

struct SVGRenderer : public IRender
{
	SVGRenderer(BLImage& img) : IRender(img) {}
};