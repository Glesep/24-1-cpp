#include "Event.h"

// ========================= Event class start ==================================
int Event::event_counter = 0;

Event::Event() {
    id = event_counter++;           // id에 넣고 event_counter+1
}

Event::Event(string cont): content(cont) {
    id = event_counter++;
}

Event::~Event() {}

int Event::get_id() {
    return id;
}

bool Event::contains(string keyword) {
    if(content.find(keyword) != string::npos)       // 찾는 단어가 존재하면
        return true;
    return false;
}

void Event::print(ostream &out) {
    out << id << ". ";
}
// ========================= Event class end, OneDayEvent class start==================================

OneDayEvent::OneDayEvent() = default;
OneDayEvent::OneDayEvent(Date d, string str): Event(str), date(d) {}

bool OneDayEvent::relevant_to_Day(Date &theDay) {       // 하루일 때
    return theDay == date;
}

bool OneDayEvent::relevant_to_Period(Date &begin_compared, Date &end_compared){   // period -> date 판단
    return begin_compared <= date && date <= end_compared;
}

// override
void OneDayEvent::print(ostream &out) {
    Event::print(out);                  // index
    date.print(out);
    out << ":" << content;
}

// ========================= OneDayEvent class end, PeriodEvent class start==================================

PeriodEvent::PeriodEvent() = default;
PeriodEvent::PeriodEvent(Date d1, Date d2, string str): Event(str), begin(d1), end(d2) {}

bool PeriodEvent::relevant_to_Day(Date &theDay) {       // day -> period 판단
    return begin <= theDay && theDay <= end;
}

bool PeriodEvent::relevant_to_Period(Date &begin_compared, Date &end_compared) {        // 여사건
    return !(end < begin_compared || begin > end_compared);     
}



void PeriodEvent::print(ostream &out) {
    Event::print(out);                  // index
    begin.print(out);
    out << "-";
    end.print(out);
    out << ":" << content;
}

// ========================= PeriodEvent class end, DeadlineEvent class start==================================

DeadlineEvent::DeadlineEvent() = default;
DeadlineEvent::DeadlineEvent(Date d, string str): Event(str), deadline(d) {}

bool DeadlineEvent::relevant_to_Day(Date &theDay) {
    return theDay <= deadline;
}

bool DeadlineEvent::relevant_to_Period(Date &begin_compared, Date &end_compared) {      // 여사건
    return !(begin_compared > deadline);
}

void DeadlineEvent::print(ostream &out) {
    Event::print(out);                  // index
    out << "~";
    deadline.print(out);
    out << ":" << content;
}