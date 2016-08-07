//
//  MainMenuScene.h
//  HasakiCocos
//
//  Created by 罗忆 on 16/4/14.
//
//

#ifndef MainMenuScene_h
#define MainMenuScene_h

#include "Headers.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);//调用构造函数create的同时调用init方法
private:
    void startGameCallBack(cocos2d::Ref* pSender);
};


#endif /* MainMenuScene_h */
