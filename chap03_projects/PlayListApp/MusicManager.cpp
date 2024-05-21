#include <fstream>
#include "Song.h"
#include "PlayList.h"
#include "MusicManager.h"
#include "Tools.h"

MusicManager::MusicManager() {
    playlists.clear();
}

PlayList * MusicManager::create_playlist(string pl_name) {
    PlayList *p = new PlayList(pl_name);
    playlists.push_back(p);
    return p;
}

void MusicManager::add_song(Song *song_ptr, vector<string> &playlist_names) {
    for (auto pname: playlist_names) {
        auto it = find_playlist(pname);
        // 플레이리스트가 이미 존재한다면
        if (it != playlists.end()) {
            (*it)->add_song(song_ptr);
        }
        // 플레이리스트가 없다면
        else {
            auto ptr = create_playlist(pname);
            cout << "creating playlist " << ptr->get_name()  << endl;
            ptr->add_song(song_ptr);
        }
    }
}

vector<PlayList *>::iterator MusicManager::find_playlist(string pname) {
    for (auto it=playlists.begin(); it!=playlists.end(); it++)
        if ((*it)->get_name() == pname)
            return it;
    return playlists.end();
}

void MusicManager::status(ostream &out) {
    for (auto plist: playlists) {
        plist->print(out);
        out << endl;
    }
}

void MusicManager::load(string filename) {

    ifstream infile;
    infile.open(filename);
    string row;
    // 한 번에 한 라인 읽어서 ,로 tokenizing
    while(getline(infile, row)) {
        vector<string> tokens = split_line(row, ',');                       // tokens의 길이는 4 or 5 (플레이리스트가 없으면 4, 있으면 5 (getline 특성)
        Song *song = new Song(tokens[0], tokens[1], tokens[2], tokens[3]);
        vector<string> plist_names;
        if (tokens.size() == 5) {                                           // Playlist가 정의되어 있을 때
            plist_names = split_line(tokens[4], ':');                       // Playlist를 split
        }
        plist_names.push_back(string("All"));
        add_song(song, plist_names);                                        // playlist_names에 속해있는 플레이리스트에 노래 다 넣기
    }
    infile.close();
}

void MusicManager::list_playlist() {
    for (auto pl: playlists)
        cout << pl->get_name() << ": " << pl->size() << " songs" << endl;
}

void MusicManager::show_plist(string pname) {
    auto it = find_playlist(pname);
    if (it != playlists.end()) {
        (*it)->print(cout);
        cout << endl;
    }
}

void MusicManager::find_song(string keyword) {
    auto it = find_playlist(string("All"));
    vector<Song *> ptr_songs = (*it)->find_songs_by_keyword(keyword);
    for (auto p: ptr_songs) {
        p->print(cout);
        cout << endl;
    }
}

void MusicManager::get_and_add_song() {
    string title, artist, album, url, plist_names, newline;
    getline(cin, newline);
    cout << "Title: " << flush;
    getline(cin, title);
    cout << "Artist: " << flush;
    getline(cin, artist);
    cout << "Album: " << flush;
    getline(cin, album);
    cout << "MV url: " << flush;
    getline(cin, url);
    cout << "Playlist: " << flush;
    getline(cin, plist_names);

    Song *s_ptr = new Song(title, artist, album, url);
    vector<string> plists = split_line(plist_names, ':');
    // All 플레이리스트에도 추가
    plists.push_back("All");
    add_song(s_ptr, plists);
}

void MusicManager::delete_song(int songId) {
    // All 플레이리스트 안에서 노래를 찾아야 함
    auto it = find_playlist(string("All"));
    auto song = (*it)->find_songs_by_id(songId);
    if (song != nullptr) {
        string title = song->get_title();
        delete song;
        cout << title << " deleted." << endl;
    }
}

void MusicManager::add_to_list(int sid, string pname) {
    auto it = find_playlist(pname);
    auto it_all = find_playlist(string("All"));
    auto song_ptr = (*it_all)->find_songs_by_id(sid);

    if (it != playlists.end()) {
        (*it)->add_song(song_ptr);
    }
    else {
        auto ptr = create_playlist(pname);
        cout << "creating playlist " << ptr->get_name()  << endl;
        ptr->add_song(song_ptr);
    }
}

void MusicManager::delete_from_list(int sid, string pname) {
    if (pname == "All") {
        cout << "Not allowed to delete song from 'all' playlist." << endl;
        return;
    }
    auto it = find_playlist(pname);
    (*it)->delete_song_by_id(sid);
}

void MusicManager::delete_list(string pname) {
    if (pname=="All") {
        cout << "Deleting 'All' not allowed." << endl;
        return;
    }
    auto it = find_playlist(pname);
    if (it==playlists.end()) {
        cout << "No playlist named " << pname << " exists." << endl;
        return;
    }
    (*it)->clear_songs();
    delete *it;
    // playlists에서도 자기자신의 데이터 삭제
    playlists.erase(it);
}

void MusicManager::play(int sid) {
    auto it = find_playlist(string("All"));
    auto song_ptr = (*it)->find_songs_by_id(sid);
    song_ptr->play();
}

void MusicManager::save(string filename) {
    ofstream outfile;
    outfile.open(filename);
    // All 플레이리스트를 가리키는 이터레이터 획득
    auto it_all = find_playlist(string("All"));
    // All 플레이리스트 접근 
    (*it_all)->print_outfile(outfile);
    outfile.close();
}