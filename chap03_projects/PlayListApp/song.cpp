#include <algorithm>
#include <sstream>
#include <fstream>
#include "Song.h"
#include "PlayList.h"
using namespace std;

int Song::id_counter = 0;
const int MAX_SONG_ID = 1000;

Song::Song(): id(id_counter) {
    id_counter = (id_counter+1) % MAX_SONG_ID;      // 0~999
}

Song::Song(string ti, string ar, string al, string mv):
        id(id_counter), title(ti), artist(ar), album(al), mv_url(mv) {
    id_counter = (id_counter+1) % MAX_SONG_ID;
}

Song::~Song() {
    // 자기가 들어가 있는 플레이리스트에 찾아가서 자가를 지워달라고 요청
    for (auto pl: playlists)
        pl->delete_song_by_id(id);
}

int Song::get_id() {
    return id;
}

string Song::get_title() {
    return title;
}

string Song::get_artist() {
    return artist;
}

void Song::register_playlist(PlayList *ptr_plist) {
    playlists.push_back(ptr_plist);
    cout << title << " by " << artist << " added to playlist "
                << ptr_plist->get_name() << endl;
}

void Song::print(ostream &out) {
    out << " " << id << ":" << title << ":" << artist << ":"
            << album << ":" << mv_url << ":";
    for (auto plist: playlists)
        out << plist->get_name() << ", ";
}

void Song::print_outfile(ostream &out) {
    out << title << "," << artist << "," << album << "," << mv_url << ",";
    int pl_size = 0;
    if (playlists.size() != 0) {
        pl_size = playlists.size();
    }
    for(auto index = 0; index < pl_size; index++) {
        // 플레이리스트 중 All은 넘기기
        if (playlists[index]->get_name() == "All")
            continue;
        if (index == 0) {
            out << playlists[index]->get_name();
            continue;
        }
        out << ":" << playlists[index]->get_name();
    }
}

void Song::unregister_playlist(string plist_name) {
    for (auto it = playlists.begin(); it != playlists.end(); it++) {
        if((*it)->get_name() == plist_name) {
            playlists.erase(it);
            cout << title << " by " << artist << " deleted from playlist "
                    << plist_name << endl;
            return;
        }
    }
    cout << "Not found the playlist." << endl;
}

void Song::play() {
    string url = "open " + mv_url;
    system(url.c_str());    // SHELL_EXECUTE(...)
}