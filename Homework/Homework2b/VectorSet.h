#pragma once
#include <vector>

template<class T>
class VectorSet {
public:
    std::vector<T> items;

    bool contains(T item) const {
        // implement contains here
        for(auto itr = items.begin(); itr != items.end(); itr++){
            if(*itr==item){
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        if (!contains(item)){
            items.insert(items.begin(), item);
            return true;
        } else {
            return false;
        }
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        for(auto itr = items.begin(); itr != items.end(); itr++){
            if(*itr == item) {
                items.erase(itr);
                return true;
            }
        }
        return false;
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return items.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (items.empty()){
            return true;
        } else {
            return false;
        }
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        items.clear();
        // remove all items from the set
    }
};
