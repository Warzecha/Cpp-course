//
// Created by damian on 23.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>

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

        std::vector<int> AvailableTimeSlots(int max) const ;


    private:
        std::vector<academia::SchedulingItem> schedule;

    };



    class Scheduler {

    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;


    };



    class GreedyScheduler : public Scheduler
    {
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;




    };



    class NoViableSolutionFound : public std::exception
    {



    };

}



#endif //JIMP_EXERCISES_SCHEDULER_H
