#include "EventScheduler.h"

void process_command(EventScheduler scheduler) {
    string command, event_type, input, content, keyword, file_name;
    while(1) {
        cout << "$ ";
        cin >> command;
        if (command == "add") {
            cin >> event_type;
            cin >> input;
            getline(cin, content);
            scheduler.add_event(event_type, input, content);
        }
        else if (command == "find") {
            try {
                cin >> input;
                if (input.find('-') == string::npos) {
                    Date d(input);
                    scheduler.show_relevant_events_Day(d);
                }
                else {
                    Date begin_compared, end_compared;
                    scheduler.parse_period_string(input, begin_compared, end_compared);
                    scheduler.show_relevant_events_Period(begin_compared, end_compared);
                }
            }
            catch (std::invalid_argument const& ex)
            {
                cout << "Invalid Date String!!" << ex.what() << '\n';
            }
        }
        else if (command == "search") {
            getline(cin, keyword);
            scheduler.search_events(keyword);
        }
        else if (command == "list") {
            scheduler.show_all_events();
        }
        else if (command == "delete") {
            int id;
            cin >> id;
            scheduler.delete_event(id);
        }
        else if (command == "save") {       // 스케줄 저장
            cin >> file_name;
            scheduler.save(file_name);
        }
        else if (command == "exit") {
            break;
        }
    }
}

int main() {
    EventScheduler scheduler;
    scheduler.load_data_file("events.txt");
    process_command(scheduler);

    return 0;
}