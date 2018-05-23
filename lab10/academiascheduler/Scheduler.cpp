//
// Created by damian on 23.05.18.
//

#include "Scheduler.h"
#include <algorithm>


namespace academia
{

    SchedulingItem::SchedulingItem(int course_ID, int teacher_ID, int room_ID, int timeslot, int year) : course_ID(
            course_ID), teacher_ID(teacher_ID), room_ID(room_ID), timeslot(timeslot), year(year) {}

    int SchedulingItem::CourseId() const {
        return course_ID;
    }


    int SchedulingItem::TeacherId() const {
        return teacher_ID;
    }


    int SchedulingItem::RoomId() const {
        return room_ID;
    }


    int SchedulingItem::TimeSlot() const {
        return timeslot;
    }


    int SchedulingItem::Year() const {
        return year;
    }


    void Schedule::InsertScheduleItem(SchedulingItem to_insert) {
        schedule.push_back(to_insert);

    }

    size_t Schedule::Size() const{
        return schedule.size();
    }

    Schedule Schedule::OfTeacher(int id) const {
        Schedule to_return;

        std::copy_if(schedule.begin(),schedule.end(),std::back_inserter(to_return.schedule),[id](SchedulingItem item) -> bool { return item.TeacherId() == id; });

        return to_return;
    }

    Schedule Schedule::OfRoom(int id) const {
        Schedule to_return;

        std::copy_if(schedule.begin(),schedule.end(),std::back_inserter(to_return.schedule),[id](SchedulingItem item) -> bool { return item.RoomId() == id; });

        return to_return;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule to_return;

        std::copy_if(schedule.begin(),schedule.end(),std::back_inserter(to_return.schedule),[id](SchedulingItem item) -> bool { return item.Year() == id; });

        return to_return;
    }

    SchedulingItem Schedule::operator[](int index) const{
        return schedule[index];
    }
}