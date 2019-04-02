#include "pch.h"
#include "Cache.h"



Cache::Cache()
{
	head = NULL;
	tail = NULL;
}


Cache::~Cache()
{
	delete tail;
	delete head;
	delete &mp;
}
