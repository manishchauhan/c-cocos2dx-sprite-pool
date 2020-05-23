//
//  PoolManager.hpp
//  BirdsAndEggs-mobile
//
//  Created by Manish on 24/11/19.
//

#ifndef DinoPoolManager_hpp
#define DinoPoolManager_hpp
#include "cocos2d.h"
#include "momJombie.hpp"
#include "JsonReader.hpp"
using namespace std;
using namespace cocos2d;

template<class T>
class DinoPoolManager
{
private:
    deque<T*> poolQueue;
public:
    //create a pool
    DinoPoolManager(int size,string name)
    {
        for(int i=0;i!=size;i++)
        {
            T *t=T::create(name);
            t->setName(name+to_string(i));
            poolQueue.push_back(t);
        
        }
    }
    DinoPoolManager(int size,string name,gameHurdle &hurdle)
    {
        for(int i=0;i!=size;i++)
        {
            T *t=T::create(name);
            t->setName(name+to_string(i));
            poolQueue.push_back(t);
            
        }
    }
    ~DinoPoolManager(){
        CCLOG("POOL DESTROYED");
    };
    deque<T*> getPoolItems()
    {
        return poolQueue;
    }
    //get items from the front of the pool
    vector<T*> getItemsFromFront(int size)
    {
        if( size>poolQueue.size() ) {
            throw "think again";
        }
        vector<T*> newItems;
        for(int i=0;i<=size;i++)
        {
            
            newItems.push_back(poolQueue.front());
            poolQueue.pop_front();
        }
        return  newItems;
    }
    //get items from the back
    vector<T*> getItemsFromBack(int size)
    {
        if( size>poolQueue.size() ) {
            throw "think again";
        }
        vector<T*> newItems;
        for(int i=0;i<=size;i++)
        {
            
            newItems.push_back(poolQueue.back());
            poolQueue.pop_back();
        }
        return  newItems;
    }
    //get pool size
    int poolSize()
    {
        return  poolQueue.size();
    }
    //get back to pool form backwards
    void backToPool(T *item)
    {
        poolQueue.push_back(item);
    }
    //get back to pool from front
    void frontToPool(T *item)
    {
        poolQueue.push_front(item);
    }
    //clear pool items
    void destroy()
    {
        for( auto item:poolQueue)
        {
            delete item;
        }
        poolQueue.clear();
    }
};


#endif /* PoolManager_hpp */
