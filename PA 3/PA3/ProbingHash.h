#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;


enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};


template<typename K, typename V>
struct HashNode {
    EntryState state;
    pair<K,V> data;
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { 
private:
    
    vector<HashNode<K,V>> table;
    int buckets;
    int elements;

public:
    ProbingHash(int n = 11) {
        buckets = findNextPrime(n);
        elements = 0;
        table.resize(buckets);
    }

    ~ProbingHash() {
        this->clear();
    }

    
    int size() {
        return elements;
    }

    V operator[](const K& key) {
        
        int keyHash = hash(key);
  
        while (table[keyHash].state != EMPTY 
            && table[keyHash].data.first != key) {
            keyHash++;
            keyHash %= buckets;
        }

        if (table[keyHash].state == VALID 
            && table[keyHash].data.first == key) {
            return table[keyHash].data.second;
        }

        throw std::range_error("Key not found in hash table");
    }

    
    bool insert(const std::pair<K, V>& pair) {
        // get hash for key
        int keyHash = hash(pair.first);
  
        while (table[keyHash].state == VALID 
            && table[keyHash].data.first != pair.first) {
            keyHash++;
            keyHash %= buckets;
        }
  
        if (table[keyHash].state != VALID) {
            elements++;
        }
            
        table[keyHash].data = pair;
        table[keyHash].state = VALID;

        if (load_factor() > LOAD_TOLERANCE) {
            rehash();
        }

        return true;
    }

   
    void erase(const K& key) {
        // get hash for key
        int keyHash = hash(key);

        while (table[keyHash].state != EMPTY 
            && table[keyHash].data.first != key) {
            keyHash++;
            keyHash %= buckets;
        }

       
        if (table[keyHash].state == VALID 
            && table[keyHash].data.first == key) {
            table[keyHash].state = DELETED;
            elements--;
            return;
        }

        throw std::range_error("Key not found in hash table");
    }

    void clear() {
        elements = 0;
        buckets = 1;
        table.clear();
    }

    int bucket_count() {
        return buckets;
    }

    float load_factor() {
        return (float)elements / buckets;
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
        return key % buckets;       
    }
    
    void rehash() {
       
        ProbingHash<K,V> *expand = new ProbingHash<K,V>(buckets * 2);
        
        for (int i = 0; i < buckets; i++) {
            
            HashNode<K,V> node = table[i];
            if (node.state == VALID) {
                expand->insert(node.data);
            }
        }


        table = expand->table;
        buckets = expand->buckets;
        elements = expand->elements;
    }
};

#endif //__PROBING_HASH_H