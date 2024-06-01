#pragma once
#include "Date.h"

class Event {
private:
    static int event_counter;
    int id;
protected:
    string content;
public:
    Event();
    Event(string cont);

    virtual ~Event();                               // virtual destructor

    int get_id();
    bool contains(string keyword);                  // content가 keyword를 포함하는지 검사

    virtual bool relevant_to_Day(Date &day) = 0;        //pure virtual function: 해야할 일이 각각 다를 때
    virtual bool relevant_to_Period(Date &start, Date &end) = 0;
    virtual void print(ostream &out);
};

class OneDayEvent: public Event {
private:
    Date date;
public:
    OneDayEvent();
    OneDayEvent(Date d, string str);
    
    bool relevant_to_Day(Date &theDay);
    bool relevant_to_Period(Date &begin_compared, Date &end_compared);
    void print(ostream &out);
};

class PeriodEvent: public Event {
private:
    Date begin, end;
public:
    PeriodEvent();
    PeriodEvent(Date d1, Date d2, string str);
    bool relevant_to_Day(Date &theDay);
    bool relevant_to_Period(Date &begin_compared, Date &end_compared);
    void print(ostream &out);
};

class DeadlineEvent: public Event {
private:
    Date deadline;
public:
    DeadlineEvent();
    DeadlineEvent(Date d, string str);
    
    bool relevant_to_Day(Date &theDay);
    bool relevant_to_Period(Date &begin_compared, Date &end_compared);
    void print(ostream &out);
};