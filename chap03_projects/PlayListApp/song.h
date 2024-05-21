//#ifndef SONG_H
//#define SONG_H

#pragma once                    // 헤더파일 include 중복 방지

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PlayList;                 // forward delcation -> 헤더파일 내에서 다른 클래스가 필요할 때 선언만 해주고 다른 파일에서 구현,
                                // 직접 구현하는 파일에서 include 해주기

class Song {
private:
    // object member
    int id;                     // 각 노래는 유일한 id를 가짐
    string title;
    string artist;
    string album;
    string mv_url;
    vector <PlayList *> playlists;
    static int id_counter;      // class member

public:
    // 헤더 파일 안에서 클래스 정의 시 멤버 메소드들은 프로토타입만 구현
    Song();
    Song(string t1, string ar, string al, string mv);
    ~Song();

    int get_id();
    string get_title();
    string get_artist();

    void print(ostream &out);
    void print_outfile(ostream &out);
    
    void register_playlist(PlayList *ptr_plist);
    void unregister_playlist(string plist_name);
    void play();
};

//#endif SONG.H