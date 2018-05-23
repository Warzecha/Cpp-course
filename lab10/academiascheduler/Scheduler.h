//
// Created by damian on 23.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>

namespace academia
{

    class SchedulingItem
    {
    public:
        SchedulingItem(int course_ID, int teacher_ID, int room_ID, int timeslot, int year);

        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

    private:

        int course_ID;
        int teacher_ID;
        int room_ID;
        int timeslot;
        int year;

    };


    class Schedule
    {
    public:
        void InsertScheduleItem(SchedulingItem to_insert);
        size_t Size() const;

        Schedule OfTeacher(int id) const;
        Schedule OfRoom(int id) const;
        Schedule OfYear(int year) const;

        SchedulingItem operator[](int index) const;


    private:
        std::vector<academia::SchedulingItem> schedule;

    };



    class Scheduler {







    };

}



#endif //JIMP_EXERCISES_SCHEDULER_H
