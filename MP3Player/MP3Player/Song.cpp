 /********************************************
 * Song.cpp
 * File Description:  The following implementation file holds the
 * functions for the class Song.
 *
 ********************************************/
#include <iostream>
#include "Song.h"
using namespace std;


string Song::toString() const {
  ostringstream strstr;
  strstr << title << " by " << artist << " [" << songSize << "] " << "(played " << playCount << " times)";
  return strstr.str();
}

void Song::playSong() {
  cout << "NOW PLAYING: " << title << " by " << artist;
  cout << "~~~ " <<  lyrics << " ~~~";
  playCount = (playCount+1);

}

bool Song::operator==(const Song &rhs) {
  if(title == rhs.title && artist == rhs.artist)
    return true;
  return false;
}

bool Song::operator<(const Song &rhs) {
  if(title == rhs.title){
    return (artist < rhs.artist);
  }
  return (title < rhs.title);
}

bool Song::operator>(const Song &rhs) {
  if(title == rhs.title){
    return (artist > rhs.artist);
  }
  return (title > rhs.title);
}

Song::Song() {
  title = "";
  artist = "";
  lyrics = "";
  songSize = 0;
  playCount = 0;
}

Song::Song(string x, string y, string z, double a) {
  title = x;
  artist = y;
  lyrics = z;
  if (a < 0){
    songSize = 0;
  }
  else
    songSize = a;
  playCount = 0;
}

string Song::getTitle() const {
  return title;
}

string Song::getArtist() const {
 return artist;
}

string Song::getLyrics() const {
  return lyrics;
}

double Song::getSize() const {
  return songSize;
}

int Song::getPlayCount() const {
  return playCount;
}

void Song::setTitle(string x) {
  title = x;
}

void Song::setArtist(string x) {
  artist = x;
}

void Song::setLyrics(string x) {
  lyrics = x;
}

void Song::setSize(double x) {
  if (x < 0){
    songSize = 0;
  }
  else
    songSize = x;
}
