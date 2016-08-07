#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "Headers.h"
//#include "GestureRecognizer.h"
#include "GeometricRecognizer.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    
    CREATE_FUNC(HelloWorld);
private:
    
    Sprite* mySprite;
    
    bool onTouchBegan(Touch * _touch,Event* _event);
    void onTouchMoved(Touch* _touch,Event* _event);
    void onTouchEnded(Touch* _touch,Event* _event);
    //to draw
    DrawNode *_drawNode ;
    //to play animation
    Node *_aniNode;
    ActionTimeline *_actionTimeline;
    
    //GestureRecognizer gesRec;
    DollarRecognizer::GeometricRecognizer* ptrGeoRec;
    DollarRecognizer::Path2D mPoints;
};

#endif // __HELLOWORLD_SCENE_H__
