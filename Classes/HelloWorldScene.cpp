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
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    MenuItemImage *closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    Menu* menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add "HelloWorld" splash screen"
    //Sprite* sprite = Sprite::create("HelloWorld.png");
    // position the sprite on the center of the screen
    //sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
    
    Sprite* bgSprite = Sprite::create("Bg.png");
    this->addChild(bgSprite);
    CCSize wins = CCDirector::sharedDirector()->getWinSize();
    bgSprite->setPosition(ccp(wins.width / 2, wins.height / 2));
    
    
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("antiboss1-hd.plist");
    CCSprite *sp =CCSprite::createWithSpriteFrameName("boss_09_normal.png");
    sp->setScale(0.5);
    sp->setPosition(ccp(200,200));
    this->addChild(sp);
    
    
    // load the tile map
    CCTMXTiledMap *pDesertTileMap = CCTMXTiledMap::create("BG1.tmx");
    this->addChild(pDesertTileMap);
    
    this->loadTowerPositions();
    return true;
}

void HelloWorld::loadTowerPositions()
{
    Array* plistDic = Array::createWithContentsOfFile("TowerPosition.plist");
    towerBases = Array::createWithCapacity(plistDic->count());
    
    Object* pObject = NULL;
    CCARRAY_FOREACH(plistDic, pObject)
    {
        Dictionary* towerPos = (Dictionary*)pObject;
        Sprite* pTower = Sprite::create("open_spot.png");
        this->addChild(pTower);
        Point pos(((String*)towerPos->objectForKey("x"))->floatValue(),
                  ((String*)towerPos->objectForKey("y"))->floatValue());
        pTower->setPosition(pos);
        towerBases->addObject(pTower);
    }
}

// changes in branch 1.



void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
