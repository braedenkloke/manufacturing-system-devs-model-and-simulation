#ifndef EVENT_HPP 
#define EVENT_HPP

#include <iostream>

struct Event {
    int orderID;
    int eventID;
    std::string resource;
    std::string activity;

    explicit Event(int orderID, std::string resource = "tmp", std::string activity = "tmp"): 
                   orderID(orderID), resource(resource), activity(activity) {
        static int eventIDCounter = 1;
        eventID = eventIDCounter++;
    };
};

#ifndef NO_LOGGING
// Formats the event log.
std::ostream& operator<<(std::ostream &out, const Event& event) {
    out << "Event Log: ";
    out << "orderID: " << event.orderID << " ";
    out << "eventID: " << event.eventID << " ";
    out << "resource: " << event.resource << " ";
    out << "activity: " << event.activity << " ";
    return out;
}
#endif

#endif // EVENT_HPP
