#include "rotate.h"
#include "ppm.h"
#include "abstractDecorator.h"
#include <vector>
void rotate::render(PPM &ppm){
    std::vector<Pixel> p (ppm.getHeight()*ppm.getWidth());
    for(int i = 0; i < ppm.getHeight()*ppm.getWidth(); ++i){
        p.at(i) = ppm.getPixels().at(i);
    }
    for (int j = 0; j < ppm.getHeight(); ++j){
        for (int i = 0; i < ppm.getWidth(); ++i){
            p.at(i*ppm.getHeight() + j) = ppm.getPixels().at(ppm.getWidth()*(ppm.getHeight() - j - 1) + i) ;
        }
     }
    int h = ppm.getHeight();
    ppm.getHeight() = ppm.getWidth();
    ppm.getWidth() = h;
    ppm.getPixels() = p;
}

rotate::rotate(Image *  img): abstractDecorator{img}{}   







