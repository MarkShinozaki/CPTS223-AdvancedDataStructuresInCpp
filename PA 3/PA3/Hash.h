#ifndef __Hash_H
#define __Hash_H

#include <math.h>
#define LOAD_TOLERANCE 0.75
//#include <utility>

template <typename K, typename V>
class Hash
{
private:
public:
    virtual ~Hash() = 0;
    virtual int size() = 0;
    virtual V operator[](const K& key) = 0;
    virtual bool insert(const std::pair<K, V>& pair) = 0;
    virtual void erase(const K& key) = 0;
    virtual void clear() = 0;
    virtual int bucket_count() = 0;
    virtual float load_factor() = 0;

private:
    virtual int hash(const K& key) = 0;
};

template <typename K, typename V>
Hash<K, V>::~Hash() {}

#endif