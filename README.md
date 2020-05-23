# c-cocos2dx-sprite-pool
a simple object pool used to store in sprites in cocos2dx (custom spirtes)

how to use it

auto coinPoolManager=new DinoPoolManager<Coin>(25,"store_coin.png");
	
    for(const auto &coin:coinPoolManager->getPoolItems())
    {
        coin->setPosition(Vec2(-100, -100));
        this->addChild(coin);
        CoinVector.pushBack(coin);
    }


