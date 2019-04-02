#pragma once
#include "Cache.h"
class LRUCache :
	public Cache
{
public:
	LRUCache(int capacity);
	~LRUCache();

	virtual void set(int, int);
	virtual int get(int);
};

