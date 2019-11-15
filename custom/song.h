#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line
//  you *MIGHT* have to change the declaration of pq1 and pq2
class comp1 {
public:
    bool operator()(const Song& me, const Song& other) const{
        return me.artist > other.artist ||
        me.artist == other.artist && me.title > other.title;
    }
};

class comp2 {
public:
    bool operator()(const Song& me, const Song& other) const {
        return me.count < other.count ||
        (me.count == other.count && me.artist > other.artist) ||
        (me.count == other.count && me.artist == other.artist && me.title > other.title);
    }
};

CP::priority_queue<Song, vector<Song>, comp1> pq1;
CP::priority_queue<Song, vector<Song>, comp2> pq2;

#endif
