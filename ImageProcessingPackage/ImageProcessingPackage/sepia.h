#ifndef _sepia_
#define _sepia_
#include "abstractDecorator.h"


class sepia : public abstractDecorator{
    public:
    sepia(Image* img);
    void render(PPM &ppm) override;
};

#endif

