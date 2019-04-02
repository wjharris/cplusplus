//https://www.hackerrank.com/challenges/messages-order/problem

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Message 
{
private:
	string text;
	int id;
public:
	Message(int id) 
	{ 
		Message::id = id; 
	}
	Message(int id, string text) 
	{ 
		Message::id = id;
		Message::text = text;
	}
	const string& get_text() 
	{
		return text;
	}

	bool operator < (const Message& compareMessage) 
	{
		if (Message::id < compareMessage.Message::id)
			return true;
		else
			return false;
	}
};

class MessageFactory 
{
private:
	int currentId;
public:
	MessageFactory() 
	{
		currentId = 0;
	}
	Message create_message(const string& text) 
	{
		return Message(++currentId, text);
	}
};

class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			cout << msg.get_text() << endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		sort(messages_.begin(), messages_.end());
	}
	vector<Message> messages_;
};

class Network {
public:
	static void send_messages(vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};



int main() {
	MessageFactory message_factory;
	Recipient recipient;
	vector<Message> messages;
	string text;
	while (getline(cin, text)) {
		if (text != "quit") {
			messages.push_back(message_factory.create_message(text));
		}
		else {
			break;
		}
		
	}
	cout << endl << "Output:" << endl;
	Network::send_messages(messages, recipient);
	recipient.print_messages();
}