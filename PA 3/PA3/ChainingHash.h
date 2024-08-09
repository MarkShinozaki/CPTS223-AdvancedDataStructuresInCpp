

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H


#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm> // std::find


#include "Hash.h"


using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;


template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    int totalBuckets, elements = 0;
    vector<list<pair<K,V>>> table;

public:
    ChainingHash(int n = 11) {
        totalBuckets = findNextPrime(n);
        table.clear();
        table.resize(totalBuckets);
    }

    ~ChainingHash() {
        this->clear();
    }

    
    int size() {
        return elements;
    }

    V operator[](const K& key) {
        
        int keyHash = hash(key);
       
        list<pair<K,V>> bucket = table.at(keyHash);
        
        for (pair<K,V> p : bucket) {
            if (p.first == key) {
                
                return p.second;
            }
        }

        
        throw std::range_error("Key not found in hash table");
    }

   
    bool insert(const std::pair<K, V>& pair) {
        
        int keyHash = hash(pair.first);
        table.at(keyHash).push_back(pair);
        elements++;

        
        if (load_factor() > LOAD_TOLERANCE) {
            rehash();
        }

        return true;
    }

    
    bool empty() {
        return elements == 0;
    }

    
    void clear() {
        
        for (int i = 0 ; i < totalBuckets; i++) {
            table[i].clear();
        }

        elements = 0;
    }

    
    void erase(const K& key) {
        
        int keyHash = hash(key);
        
        bool removed = false;
        for (pair<K,V> p : table[keyHash]) {
            
            if (p.first == key) {
                table[keyHash].remove(p);
                elements--;
                removed = true;
                break;
            }
        }
    }

    int bucket_count() {
        return totalBuckets;
    }

    float load_factor() {
        return (float)elements / totalBuckets;
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return key % totalBuckets;       
    }

    void rehash() {
       
        ChainingHash<K,V> newTable(totalBuckets * 2);

        
        for (auto l : table) {
            
            for (auto p : l) {
                
                newTable.insert(p);
            }
        }

        
        table = newTable.table;
        totalBuckets = newTable.bucket_count();
    }
};

#endif //__CHAINING_HASH_H