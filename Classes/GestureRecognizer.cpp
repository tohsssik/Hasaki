//
//  GestureRecognizer.cpp
//  HasakiCocos
//
//  Created by 罗忆 on 16/8/5.
//
//

#include "GestureRecognizer.h"
#include "Headers.h"

GestureRecognizer::GestureRecognizer()
:result("null",-1)
{
    this->ptrGeoRec = new DollarRecognizer::GeometricRecognizer();
    ptrGeoRec->loadTemplates();
}

GestureRecognizer::~GestureRecognizer()
{
    delete this->ptrGeoRec;
    
}

void GestureRecognizer::init()
{
    //this->result = DollarRecognizer::RecognitionResult();
    clearPoints();
}

void GestureRecognizer::clearPoints()
{
    this->mPoints.clear();
    this->result = DollarRecognizer::RecognitionResult("null",-1);
}

void GestureRecognizer::pushBackPoints(cocos2d::Vec2 vec2_location)
{
    this->pushBackPoints(static_cast<double>(vec2_location.x), static_cast<double>(vec2_location.y));
}

void GestureRecognizer::pushBackPoints(double x,double y)
{
    DollarRecognizer::Point2D point(x,y);
    this->mPoints.push_back(point);
}

void GestureRecognizer::calculate()
{
    DollarRecognizer::RecognitionResult r = this->ptrGeoRec->recognize(mPoints);
    this->result = r;
}

string GestureRecognizer::getResultName()
{
    return result.name;
}

double GestureRecognizer::getResultScore()
{
    return result.score;
}


