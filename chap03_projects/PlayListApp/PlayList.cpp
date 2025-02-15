#include <fstream>
#include <sstream>

#include "Song.h"
#include "PlayList.h"
using namespace std;

PlayList::PlayList(string str): name(str) {}

string PlayList::get_name() {
    return name;
}

void PlayList::add_song(Song *song) {
    tracks.push_back(song);
    song->register_playlist(this);
}

void PlayList::print (ostream &out) {
    out << name << ":" << endl;
    for (auto song_ptr: tracks) {
        song_ptr->print(out);
        out << endl;
    }
}

void PlayList::print_outfile (ostream &out) {
    for (auto song_ptr: tracks) {
        song_ptr->print_outfile(out);
        out << endl;
    }
}

vector<Song *> PlayList::find_songs_by_keyword(string keyword) {
    vector<Song *> result;
    for (Song *item: tracks) {
        if (item->get_title().find(keyword) != string::npos || item->get_artist().find(keyword) != string::npos )
            result.push_back(item);
    }
    return result;
}

Song *PlayList::find_songs_by_id(int sid) {
    for (auto item: tracks)
        if (item->get_id() == sid)
            return item;
    return nullptr;
}

void PlayList::delete_song_by_id(int songId) {
    for (auto it=tracks.begin(); it != tracks.end(); it++) {
        if ((*it)->get_id() == songId) {
            tracks.erase(it);
            return;
        }
    }
}

void PlayList::clear_songs() {  // 플레이리스트에 포함된 모든 노래에서 해당 플레이리스트 삭제
    for (auto it=tracks.begin(); it != tracks.end(); it++)
        (*it)->unregister_playlist(name);
    tracks.clear();  // unnecessary, 벡터의 크기를 0으로 만듦
}

int PlayList::size() {
    return tracks.size();
}