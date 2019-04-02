#include "pch.h"
#include "LRUCache.h"
#include <iostream>
#include <map>


//https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem

LRUCache::LRUCache(int capacity)
{
	Cache::cp = capacity;
	Cache::mp = map<int, Node*>();
}




LRUCache::~LRUCache()
{
}

void LRUCache::set(int key, int value)
{	
	
	map<int, Node*>::iterator it = Cache::mp.find(key);
	if (it != Cache::mp.end()) {
		Node* node = Cache::mp[key];
		node->value = value;
		if (Cache::mp.size() != 1) {
			Node* prevNode = node->prev;
			Node* nextNode = node->next;
			if (prevNode != NULL && nextNode != NULL) {
				prevNode->next = nextNode;
				nextNode->prev = prevNode;
			}
			else if (prevNode != NULL) {
				prevNode->next = NULL;
				Cache::tail = prevNode;
			}
			if (node != Cache::head) {
				node->next = Cache::head;
			}
			node->prev = NULL;
			Cache::head->prev = node;
			Cache::head = node;
		}
	}
	else {
		if (Cache::head == NULL) {
			Node* newNode = new Node(key, value);
			Cache::head = newNode;
			Cache::tail = newNode;
			Cache::mp[key] = newNode;

		}
		else if (Cache::mp.size() >= Cache::cp) {
			if (Cache::tail->prev != NULL) {
				Node* prevTail = Cache::tail;
				Node* prevHead = Cache::head;
				Node* newNode = new Node(NULL, prevHead, key, value);
				Cache::tail = Cache::tail->prev;
				Cache::mp.erase(prevTail->key);
				Cache::head = newNode;
				Cache::tail->next = NULL;
				prevHead->prev = newNode;
				Cache::mp[key] = newNode;
				delete prevTail;
			}
			else {
				Node* prevHead = Cache::head;
				Node* newNode = new Node(key, value);
				Cache::mp.erase(prevHead->key);
				Cache::head = newNode;
				Cache::mp[key] = newNode;
			}
		}
		else {
			Node* prevHead = Cache::head;
			Node* newNode = new Node(NULL, prevHead, key, value);
			Cache::head = newNode;
			prevHead->prev = newNode;
			Cache::mp[key] = newNode;
		}
	}

	Node* currentNode = Cache::head;
	while (currentNode != NULL) {
		cout << "(" << currentNode->key << ":" << currentNode->value << ")";
		currentNode = currentNode->next;
		if (currentNode != NULL) {
			cout << ", ";
		}
	}
	cout << "\n";
	
}

int LRUCache::get(int key)
{
	map<int, Node*>::iterator it = Cache::mp.find(key);
	if (it != Cache::mp.end()) {
		Node* node = Cache::mp[key];
		LRUCache::set(node->key, node->value);
		return node->value;
	}
	else {
		LRUCache::set(key, -1);
		return -1;
	}
}
