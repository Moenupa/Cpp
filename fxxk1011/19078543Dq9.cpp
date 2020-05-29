#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MusicAlbumType
{
    string band_name;
    string album_title;
    int num_tracks;
    string track_name[12];
    int release_year;
};

MusicAlbumType init()
{
    MusicAlbumType new_album;
    cout << "Please input Album Title: ";
    cin >> new_album.album_title;
    cout << "Please input Band Name: ";
    cin >> new_album.band_name;
    cout << "Please input Release Year: ";
    cin >> new_album.release_year;
    cout << "Please input Number of Tracks: ";
    cin >> new_album.num_tracks;
    for (int i = 0; i < new_album.num_tracks; i++)
    {
        cout << "Please input Name for Track " << i + 1 << ": ";
        cin >> new_album.track_name[i];
        // get the tracks within no-of-track-range
    }
    return new_album;
}


void print(MusicAlbumType new_album)
{
    cout << "Title:   " << new_album.album_title << endl;
    cout << "Band:    " << new_album.band_name << endl;
    cout << "Release: " << new_album.release_year << endl;
    cout << "Tracks:  " << new_album.num_tracks << endl;
    for (int i = 0; i < new_album.num_tracks; i++)
    {
        cout << "    Track" << setw(2) << i + 1 << ": " << new_album.track_name[i] << endl;
        // print names of the tracks
    }
}

int main()
{
    // function testing
    MusicAlbumType new_album;
    new_album = init();
    print(new_album);

}