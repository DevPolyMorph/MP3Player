 /********************************************
 * MP3Player.h
 * File Description:  The following file holds the
 * class declaration for the class MP3Player.
 *
 ********************************************/

#include "Song.h"
using namespace std;

class MP3Player{
  private:
    Song *songs;
    int maxSongs;
    double maxMB;
    int totalSongs = 0;
    double currentMB=0;

    void resize();
    void sort();
    int search(Song);

  public:

    //constructors
    MP3Player(int,double);
    ~MP3Player();

    // accessors
    bool playSong(string,string);
    void displayPlaylist() const;
    double getRemainingMB() const;
    int getSongCount() const;

    // mutators
    bool addSong(Song);
    bool removeSong(string,string);


 };

