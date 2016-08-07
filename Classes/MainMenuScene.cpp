//
//  MainMenuScene.cpp
//  HasakiCocos
//
//  Created by 罗忆 on 16/4/14.
//
//

#include "Headers.h"

Scene* MainMenu::createScene()//scene包含了layer，此方法相当于创建一个有特定儿子的爸爸
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getWinSize();
    
    cout<<"visible size : "<<visibleSize.width<<"X"<<visibleSize.height<<endl;
    cout<<"window size : "<<winSize.width<<"X"<<winSize.height<<endl;
    cout<<"origin : x: "<<origin.x<<" y: "<<origin.y<<endl;
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    string btnBG_MainMenu_Path = "/Users/luoyi/workspace/Hasaki/HasakiCocos/Resources/buttonBG_MainMenu.png";
    auto startGameItem = MenuItemImage::create(
                                           btnBG_MainMenu_Path,
                                           btnBG_MainMenu_Path,
                                           CC_CALLBACK_1(MainMenu::startGameCallBack, this));
    
    //setPosition设置的是物体正中央的坐标
    startGameItem->setPosition(Vec2(origin.x + visibleSize.width/2  ,origin.y +visibleSize.height/2 ));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(startGameItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    //string btnPath = "buttonBG_MainMenu.png";
    //string fullPath = FileUtils::getInstance()->FileUtils::fullPathForFilename(btnPath);
    //string fullPath = FileUtils::getInstance()->FileUtils::getWritablePath();
    //cout<<"fullPath = "<<fullPath<<endl;
    
    return true;
}

void MainMenu::startGameCallBack(cocos2d::Ref *pSender)
{
    auto layer = new HelloWorld();
    auto scene = layer->createScene();
    Director::getInstance()->replaceScene(scene);
    layer->release();
    scene->release();
}


