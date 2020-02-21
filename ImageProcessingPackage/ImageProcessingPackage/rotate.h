#ifndef _rotate_
#define _rotate_
#include "abstractDecorator.h"


class rotate : public abstractDecorator{
    public:
    rotate(Image * img);
    void render(PPM &ppm) override;
};

#endif

