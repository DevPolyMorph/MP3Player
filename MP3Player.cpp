 /********************************************
 * MP3Player.cpp
 * File Description:  The following implementation file holds the
 * class functions for the class Song.
 *
 ********************************************/
#include "MP3Player.h"
#include <iostream>

void MP3Player::resize() {
  maxSongs = (2*maxSongs);
  Song *temp = songs;
  songs = new Song[maxSongs];
  for(int i = 0; i < totalSongs; i++) {
    songs[i] = temp[i];
  }
  delete temp;
}

void MP3Player::sort() {
  bool swapped;
  Song temp = *songs;
  do {
    swapped = false;
    for(int i = 0; i < (totalSongs - 1); i++) {
      if(songs[i] > songs[i + 1]) {
      temp = songs[i];
      songs[i] = songs[i+1];
      songs[i + 1] = temp;
      swapped = true;
      }
    }
  } while(swapped);
}
int MP3Player::search(Song x) {
  int index = -1;
  for(int i = 0; i < totalSongs; i++) {
    if(songs[i] == x) {
    index = i;
    }
  }
  return index;
}

MP3Player::MP3Player(int numSongs, double numMB) {
  songs = new Song[numSongs];
  maxSongs = numSongs;
  maxMB = numMB;
}

MP3Player::~MP3Player() {
   delete [] songs;
}

bool MP3Player::playSong(string x, string y) {
  Song temp;
  temp.setTitle(x);
  temp.setArtist(y);
  int index = search(temp);
  if(index >= 0) {
    songs[index].playSong();
    return true;
  }
  else
    return false;
}
void MP3Player::displayPlaylist() const {
 for(int i = 0; i < totalSongs; i++) {
    cout << songs[i].toString() << endl;
 }
}

double MP3Player::getRemainingMB() const {
  return (maxMB - currentMB);
}

int MP3Player::getSongCount() const {
  return totalSongs;
}

bool MP3Player::addSong(Song x) {
  if((totalSongs+1) > maxSongs){
    resize();
  }
  if(x.getSize() > maxMB-currentMB) {
    return false;
  }
  for (int i = 0; i < totalSongs; i++) {
    if( songs[i] == x ){
    return false;
    }
  }
  if(x.getSize() <= 0){
     return false;
  }

  songs[totalSongs]= x;
  currentMB = (currentMB+x.getSize());
  totalSongs = totalSongs + 1;
  sort();
  return true;
}

bool MP3Player::removeSong(string x, string y) {
  Song temp;
  temp.setTitle(x);
  temp.setArtist(y);
  if(search(temp) != -1) {
    int index = search(temp);
    for (int i = index; i < totalSongs; i++) {
      songs[i] = songs[i+1];
    }
    totalSongs = (totalSongs-1);
    return true;
  }
  else
    return false;
}
