/*************************************************
 * MusicDriver.cpp
 * A sample driver for the MP3 Player.
 *************************************************/

#include <iostream>
#include "MP3Player.h"
using namespace std;

int main() {
  cout << "Testing Song..." << endl << endl;

  // WARNING:
  // Note that this sample driver does not test arguments representing
  // negative song sizes, any of the getter functions, playSong, or any of
  // the overloaded ==, >, or < operators.

  Song t0;
  cout << "blank song: " << t0.toString() << endl;

  t0.setTitle("Hey Jude");
  t0.setArtist("The Beatles");
  t0.setLyrics("take a sad song and make it better");
  t0.setSize(2.5);

  cout << t0.toString() << endl << endl;

  cout << "Testing MP3Player..." << endl << endl;

  // WARNING:
  // Note that this sample driver does not test playing a song, songs that
  // share the same name but different artists, attempting to play or remove
  // non-existant songs, the resize() function, etc.

  MP3Player mp3(5, 10.0);

  Song s1("A First Song", "First Artist", "some lyrics 1", 1.5);
  Song s2("B Second Song", "Second Artist", "some lyrics 2", 2.6);
  Song s3("C Third Song", "Third Artist", "some lyrics 3", 1.9);
  Song s4("D Fourth Song", "Fourth Artist", "some lyrics 4", 2.7);
  Song s5("E Fifth Song", "Fifth Artist", "some lyrics 5", 1.4);

  bool result = mp3.addSong(s2);
  cout << "addSong(s2) result: " << result << endl;

  result = mp3.addSong(s4);
  cout << "addSong(s4) result: " << result << endl;

  result = mp3.addSong(s3);
  cout << "addSong(s3) result: " << result << endl;

  result = mp3.addSong(s1);
  cout << "addSong(s1) result: " << result << endl;

  cout << endl;
  mp3.displayPlaylist();
  cout << endl;

  cout << "remaining MBs = " << mp3.getRemainingMB() << endl;
  result = mp3.addSong(s5); // no space!
  cout << "addSong(s5) result: " << result << " (should fail)" << endl;
  cout << endl;

  cout << "Removing third song..." << endl;
  result = mp3.removeSong("C Third Song", "Third Artist");
  cout << "removeSong(s3) result: " << result << endl;

  cout << endl;
  cout << "song count: " << mp3.getSongCount() << endl;
  mp3.displayPlaylist();
  cout << endl;

  cout << "Removing last and first songs..." << endl;
  result = mp3.removeSong("D Fourth Song", "Fourth Artist");
  cout << "removeSong(s4) result: " << result << endl;
  result = mp3.removeSong("A First Song", "First Artist");
  cout << "removeSong(s1) result: " << result << endl;

  cout << endl;
  mp3.displayPlaylist();
  cout << endl;

  cout << "Removing remaining song..." << endl;
  result = mp3.removeSong("B Second Song", "Second Artist");
  cout << "removeSong(s2) result: " << result << endl;

  cout << endl;
  mp3.displayPlaylist();

  return 0;
}
