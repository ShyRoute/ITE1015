#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "message.h"

MessageBook::MessageBook() {

}

MessageBook::~MessageBook() {

}

void MessageBook::AddMessage(int number, const std::string &message) {
    
    messages_.insert(make_pair(number, message));
}

void MessageBook::DeleteMessage(int number) {
    messages_.erase(number);
}

std::vector<int> MessageBook::GetNumbers() {
    std::vector<int> numList;
    std::map<int, std::string>::iterator it;
    for(it = messages_.begin(); it != messages_.end(); it++) {
        numList.push_back(it->first);
    }
    return numList;
}

const std::string &MessageBook::GetMessage(int number) {
    static const std::string nullStr = "";

    if(messages_.find(number) != messages_.end()) {
        return messages_[number];
    }
    else return nullStr;
}