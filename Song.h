 /********************************************
 * Song.h
 * File Description:  The following file holds the
 * class declaration for the class Song.
 *
 ********************************************/
#ifndef SONG_H
#define SONG_H
#include <sstream>
#include <string>

using namespace std;

class Song {
  private:
    string title;
    string artist;
    double songSize;
    int playCount;
    string lyrics;

  public:
    string toString() const;

    bool operator==(const Song &);
    bool operator<(const Song &);
    bool operator>(const Song &);

    //constructors
    Song();
    Song(string, string, string, double);

    // accessors
    string getTitle() const;
    string getArtist() const;
    string getLyrics() const;
    double getSize() const;
    int getPlayCount() const;
    void playSong();

    // mutators
    void setTitle(string);
    void setArtist(string);
    void setLyrics(string);
    void setSize(double);

 };
#endif
