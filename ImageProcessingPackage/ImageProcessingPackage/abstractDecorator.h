#ifndef _abstractDecorator_
#define _abstractDecorator_
#include "image.h"

class abstractDecorator : public Image{
    Image* i;
    public:
    abstractDecorator(Image* i);
};

#endif  

