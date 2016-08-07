//
//  GestureRecognizer.h
//  HasakiCocos
//
//  Created by 罗忆 on 16/8/5.
//
//
#ifndef GestureRecognizer_h
#define GestureRecognizer_h

#include "Headers.h"
#include "GeometricRecognizer.h"

class GestureRecognizer
{
public:
    GestureRecognizer();
    ~GestureRecognizer();
    
    void init();
    void clearPoints();
    void pushBackPoints(cocos2d::Vec2);
    void pushBackPoints(double x,double y);
    void calculate();
    string getResultName();
    double getResultScore();
    
private:
    DollarRecognizer::GeometricRecognizer* ptrGeoRec;
    DollarRecognizer::Path2D mPoints;
    DollarRecognizer::RecognitionResult result;
};

#endif /* GestureRecognizer_h */
