#include "flip.h"
#include "ppm.h"
#include "abstractDecorator.h"
void flip::render(PPM &ppm){
     for(int i = 0; i < ppm.getHeight(); ++i){
        for(int j = 0; j < ppm.getWidth()/2; ++j){
            Pixel p = ppm.getPixels().at(ppm.getWidth()*i + j);
            ppm.getPixels().at(ppm.getWidth()*i + j) = ppm.getPixels().at((i+1)*ppm.getWidth() - j - 1);
            ppm.getPixels().at((i+1)*ppm.getWidth() - j - 1) = p;
        }
        
    }
}



flip::flip(Image *  img): abstractDecorator{img}{}

