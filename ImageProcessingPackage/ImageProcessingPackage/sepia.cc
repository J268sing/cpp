#include "sepia.h"
#include "ppm.h"
#include "abstractDecorator.h"


 


sepia::sepia(Image* img): abstractDecorator{img}{}

void sepia::render(PPM &ppm){
    int len = ppm.getPixels().size();
    for(int i = 0; i < len; ++i){
        ppm.getPixels().at(i).r = ppm.getPixels().at(i).r*(.393)  + ppm.getPixels().at(i).b*(.189)
         + ppm.getPixels().at(i).g* (.769 );

        ppm.getPixels().at(i).g = ppm.getPixels().at(i).r*(.349)  + ppm.getPixels().at(i).b*(.168)
         + ppm.getPixels().at(i).g* (.686);

        ppm.getPixels().at(i).b = ppm.getPixels().at(i).r*(.272)  + ppm.getPixels().at(i).b*(.131)
         + ppm.getPixels().at(i).g* (.534);


         if(ppm.getPixels().at(i).r > 255){
             ppm.getPixels().at(i).r = 255;
         }
         if(ppm.getPixels().at(i).g > 255){
             ppm.getPixels().at(i).g = 255;
         }
         if(ppm.getPixels().at(i).b > 255){
             ppm.getPixels().at(i).b = 255;
         }

    }
}


