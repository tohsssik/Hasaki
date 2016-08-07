#include "Headers.h"

USING_NS_CC;

Scene* HelloWorld::createScene()//scene包含了layer，此方法相当于创建一个有特定儿子的爸爸
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", GET_FILE("Marker Felt.ttf"), 24);
    if(label==nullptr) cout<<"null label"<<endl;
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    
    auto sprite = Sprite::create(GET_FILE("HelloWorld.png"));
    if(sprite==nullptr) cout<<"null sprite"<<endl;
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    //------------------
    Size winSize = Director::getInstance()->getWinSize();
    cout<<"window Size: "<<winSize.width<<"X"<<winSize.height<<endl;
    this->mySprite = Sprite::create(GET_FILE("CloseNormal.png"));
    this->mySprite->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(this->mySprite,1);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    //-------------------
    
    _drawNode = DrawNode::create();
    this->addChild(_drawNode,2);
    
    //--------------------
    
    _aniNode = CSLoader::getInstance()->createNode(GET_FILE("res/PlayerAnim.csb"));
    _aniNode->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(_aniNode);
    if(_aniNode) cout<<"null aniNode"<<endl;
    
    _actionTimeline = CSLoader::createTimeline(GET_FILE("res/PlayerAnim.csb"));
    _aniNode->runAction(_actionTimeline);
    if(_actionTimeline) cout<<"null actionTimeline"<<endl;
    
    
    
    //init the gesRec
    //this->gesRec = GestureRecognizer();
    ptrGeoRec = new DollarRecognizer::GeometricRecognizer();
    ptrGeoRec->loadTemplates();
    
    return true;
}

bool HelloWorld::onTouchBegan(Touch* _touch, Event* _event)
{
    auto loc1 = _touch->getLocation();//正常的坐标左下角为（0，0）
    auto loc2 = _touch->getLocationInView();//坐标左上角为（0，0）
    //cout<<"Began : loc1.x= "<<loc1.x<<"  loc1.y= "<<loc1.y<<endl;
    //cout<<"Began : loc2.x= "<<loc2.x<<"  loc2.y= "<<loc2.y<<endl;
    //this->mySprite->setPosition(loc1);
    
    // 播放动画
    _actionTimeline->gotoFrameAndPlay(0, false);
    
    //_drawNode->drawPoint(loc1, 10.0, Color4F(10,10,10,10));
    
    
    //this->gesRec.init();
    mPoints.clear();
    
    return true;
}

void HelloWorld::onTouchMoved(Touch* _touch, Event* _event)
{
    auto loc = _touch->getLocation();
    //cout<<"Moved : loc.x= "<<loc.x<<"  loc.y= "<<loc.y<<endl;
    //this->mySprite->setPosition(loc);
    
    _drawNode->drawPoint(loc, 10.0, Color4F(10,10,10,10));
    
    //this->gesRec.pushBackPoints(loc);
    //as in cocos ,y-axis is bottom up
    DollarRecognizer::Point2D point(loc.x,768-loc.y);
    mPoints.push_back(point);
    
    return;
}

void HelloWorld::onTouchEnded(Touch* _touch, Event* _event)
{
    auto loc = _touch->getLocation();
    //cout<<"Ended : loc.x= "<<loc.x<<"  loc.y= "<<loc.y<<endl;
    
    //this->gesRec.calculate();
    //cout<<"result name and score: "<<gesRec.getResultName()<<"  "<<gesRec.getResultScore()<<endl;
    DollarRecognizer::RecognitionResult r = ptrGeoRec->recognize(mPoints);
    cout<<"result name and score: "<<r.name<<"  "<<r.score<<endl;
    
    return;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
