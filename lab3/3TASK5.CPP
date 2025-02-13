#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
    private:
        string playlist[10];  
        string currentlyPlayingSong;
        int songCount = 0; 
    public:
    void addSong(string s) {
        if (songCount<10) {
            playlist[songCount] = s;
            songCount++;
            cout<<"Added: "<<s<<" to the playlist"<<endl;
        } else {
            cout<<"Playlist is full! Cannot add more songs"<<endl;
        }
    }
    void removeSong(string s) {
        int found =0;
        for (int i=0;i<songCount;i++) {
            if (playlist[i]==s) {
                found=1;
                for (int j=i;j<songCount-1;j++) {
                    playlist[j]=playlist[j+1];
                }
                songCount--;
                cout<<"Removed: "<<s<<" from the playlist"<<endl;
                break;
            }
        }
        if (!found) {
            cout << "Song not found in playlist"<<endl;
        }
    }
    void playSong(string s) {
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == s) {
                currentlyPlayingSong=s;
                cout<<"Now playing: "<<s<<endl;
                return;
            }
        }
        cout << "Song not found in playlist"<<endl;
    }
    void displayPlaylist() {
        cout << "Playlist:"<<endl;
        for (int i = 0; i < songCount; i++) {
            cout << "- " << playlist[i] << endl;
        }
        if (!currentlyPlayingSong.empty()) {
            cout<<"Currently Playing: "<<currentlyPlayingSong<<endl;
        }
    }
};
int main() {
    MusicPlayer imran; 

    imran.addSong("APT");
    imran.addSong("Fein");
    imran.addSong("God's Plan");
    imran.displayPlaylist();
    imran.playSong("Fein");
    imran.removeSong("APT");
    imran.displayPlaylist();

    return 0;
}
