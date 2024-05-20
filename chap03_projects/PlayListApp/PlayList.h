#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song;                    // secret dependency -> 2개의 헤더 파일이 각각의 class를 사용해야 하는 경우  해야 하는 경우, 먼저 오는 파일에서 사용되는 클래스가 정의되지 않아 생기는 문제
                               // 문제 해결을 위해 헤더 파일을 include하지 말고 Song을 forward declaration 해준다.

class PlayList {
private:
    string name;
    vector<Song *> tracks;
public:
    PlayList() = default;
    PlayList(string str);
    string get_name();

    void add_song(Song *song);
    void print(ostream &out);

    vector<Song *> find_songs_by_keyword(string keyword);
    Song *find_songs_by_id(int sid);

    void delete_song_by_id(int songId);                     // 플레이리스트에서 노래 삭제
    void clear_songs();
    int size();
};