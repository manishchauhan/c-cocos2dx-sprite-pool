# c-cocos2dx-sprite-pool
a simple sprite pool used to store sprites and used them later for stable fps.(only used for custom sprite but you can change it based on your need.)

how to use it

#create a PoolManager instance.

	auto coinPoolManager=new DinoPoolManager<Coin>(25,"store_coin.png");

#add sprites in most cases out of your view port

	    for(const auto &coin:coinPoolManager->getPoolItems())
	    {
		coin->setPosition(Vec2(-100, -100));
		this->addChild(coin);
		CoinVector.pushBack(coin);
	    }





