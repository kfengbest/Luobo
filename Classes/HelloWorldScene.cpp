#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 3. add your codes below...

    
//    Sprite *pBackground = Sprite::create("FishRes/bj01.jpg");
//    Size sz = Director::getInstance()->getWinSize();
//    pBackground->setPosition(Point(sz.width/2, sz.height/2));
//    this->addChild(pBackground);

    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);

    // Load the Background
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Themes/Theme1/BG0/BG1-hd.plist", "Themes/Theme1/BG0/BG1-hd.pvr.ccz");
    // Create a sprite from the atlas
    Sprite *bg0 = Sprite::createWithSpriteFrameName("BG1.png");
    Size sz = Director::getInstance()->getWinSize();
    bg0->setPosition(Point(sz.width/2, sz.height/2));
    this->addChild(bg0);
    
    // Load the Background
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Themes/Theme1/BG1/BG-hd.plist", "Themes/Theme1/BG1/BG-hd.pvr.ccz");
    // Create a sprite from the atlas
    Sprite *bg1 = Sprite::createWithSpriteFrameName("Path.png");
    bg1->setPosition(Point(sz.width/2, sz.height/2));
    this->addChild(bg1);
    

    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("antiboss1-hd.plist");
    CCSprite *sp =CCSprite::createWithSpriteFrameName("boss_09_normal.png");
    sp->setScale(0.5);
    sp->setPosition(ccp(200,200));

    CCSprite *sp10 =CCSprite::createWithSpriteFrameName("boss_10_normal.png");
    sp10->setScale(0.5);
    sp10->setPosition(ccp(300,200));
    
    CCSprite *sp11 =CCSprite::createWithSpriteFrameName("boss_11_normal.png");
    sp11->setPosition(ccp(400,200));
    sp11->setScale(0.5);
    
    this->addChild(sp);
    this->addChild(sp10);
    this->addChild(sp11);
    
    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
