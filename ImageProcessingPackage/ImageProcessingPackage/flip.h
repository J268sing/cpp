#ifndef _flip_
#define _flip
#include "abstractDecorator.h"


class flip : public abstractDecorator{
    public:
    flip(Image *  img);
    void render(PPM &ppm) override;
};

#endif 


