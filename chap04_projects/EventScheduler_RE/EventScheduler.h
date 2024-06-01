#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "Event.h"

class EventScheduler {
private:
    vector<Event *> events;             // 다형성 이용
    void add_oneday_event(string date_string, string content);
    void add_period_event(string date_string, string content);
    void add_deadline_event(string date_string, string content);
    void parse_deadline_string(string deadline_str, Date &d);
public:
    void parse_period_string(string period_str, Date &s, Date &t);
    void add_event(string type, string date_string, string content);
    void show_relevant_events_Day(Date theDay);
    void show_relevant_events_Period(Date begin_compared, Date end_compared);
    void search_events(string keyword);
    void show_all_events();
    void load_data_file(string file_name);
    void delete_event(int id);
};