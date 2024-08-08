// CptS 223 HW10 
//
// DisjointSet template class
//
// Implementation of disjoint sets with insert and print.
// This implementation uses pointer-based trees rather than array-based.

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <unordered_map>
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class DisjointSet
{
public:
	
	DisjointSet( ) {};

	~DisjointSet( )
	{
		makeEmpty( );
	}

	void insert (const T & x)
	{
		DisjointSetNode * djnode = new DisjointSetNode(x);
		map[x] = djnode;
	}

	const T & find( const T & x )
	{
		if (map.count(x) == 0)
			throw underflow_error("not found");
		else {
			DisjointSetNode * djnode = map[x];
			djnode = findWithPathCompression(djnode);
			return djnode->element;
		}
	}
	
	void unionSets( const T & x, const T & y)
	{
		if ((map.count(x) == 0) || (map.count(y) == 0))
			throw underflow_error("not found");
		else {
			DisjointSetNode * djnode1 = map[x];
			DisjointSetNode * djnode2 = map[y];
			djnode1 = findWithPathCompression(djnode1);
			djnode2 = findWithPathCompression(djnode2);
			if (djnode1 != djnode2) {
				if ((djnode2->rank) > (djnode1->rank)) {
					djnode1->parent = djnode2;
				} else {
					if (djnode1->rank == djnode2->rank)
						djnode1->rank++;
					djnode2->parent = djnode1;
				}
			}
		}
	}

	void print( ostream & out = cout ) const
	{
		for( const pair<const T, DisjointSetNode*>& p : map ) {
			DisjointSetNode * djnode = p.second;
			if (djnode->parent == nullptr) {
				out << djnode->element << " (" << djnode->rank << ") -> NULL" << endl;
			} else {
				out << djnode->element << " (" << djnode->rank << ") -> " << djnode->parent->element << endl;
			}
		}
	}

private:
	
	struct DisjointSetNode
	{
		T element;
		DisjointSetNode * parent;
		int rank;
		
		DisjointSetNode(const T & theElement): element (theElement), parent (nullptr), rank (0) {};
	};

	unordered_map<T,DisjointSetNode*> map;
	
	// Returns representative DisjointSetNode for the set containing the given DisjointSetNode
	DisjointSetNode * findWithPathCompression( DisjointSetNode * djnode )
	{
		if (djnode->parent == nullptr) {
			return djnode;
		} else {
			djnode->parent = findWithPathCompression(djnode->parent);
			return djnode->parent;
		}
	}
	
	void makeEmpty()
	{
		for( const pair<const T, DisjointSetNode*>& p : map ) {
			DisjointSetNode * djnode = p.second;
			delete djnode;
		}
		map.clear();
	}

};

#endif
