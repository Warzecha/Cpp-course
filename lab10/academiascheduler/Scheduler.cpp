//
// Created by damian on 23.05.18.
//

#include "Scheduler.h"
#include <algorithm>
#include <map>
#include <set>








namespace academia
{

    std::vector<int> commonElements(std::vector<int> v1, std::vector<int> v2)
    {
        std::vector<int> to_return;

        for(auto x1 : v1)
        {

            if((std::find(v2.begin(), v2.end(), x1) != v2.end()))
            {
                to_return.push_back(x1);
            }

        }


        return to_return;

    }

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

        std::copy_if(schedule.begin(),schedule.end(),std::back_inserter(to_return.schedule),[year](SchedulingItem item) -> bool { return item.Year() == year; });

        return to_return;
    }

    SchedulingItem Schedule::operator[](int index) const{
        return schedule[index];
    }

    std::vector<int> Schedule::AvailableTimeSlots(int max) const {

        std::vector<int> to_return(max);

        for (int i = 0; i < max ; ++i) {
            to_return[i] = i + 1;
        }


        for(auto item : schedule)
        {

            int item_time_slot = item.TimeSlot();
            to_return.erase(std::remove_if(to_return.begin(),to_return.end(),[item_time_slot](int time_slot) -> bool { return item_time_slot == time_slot;}),to_return.end());

        }



        return to_return;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        Schedule new_schedule;

        for(const auto &year : courses_of_year)
        {

            for(const auto & course : year.second)
            {

                auto teacher = std::find_if(teacher_courses_assignment.begin(), teacher_courses_assignment.end(), [course](std::pair<int,std::vector<int>> teacher) -> bool { return std::find(teacher.second.begin(), teacher.second.end(), course) != teacher.second.end();});
                auto availible_teacher_schedule = new_schedule.OfTeacher(teacher->first).AvailableTimeSlots(n_time_slots);
                auto availible_year_schedule = new_schedule.OfYear(year.first).AvailableTimeSlots(n_time_slots);


                std::vector<int> time_slots = commonElements(availible_year_schedule, availible_teacher_schedule);

                if(time_slots.empty())
                {
                    throw NoViableSolutionFound();
                }


                bool assigned_flag = false;

                for (int i = 0; i < rooms.size() && not assigned_flag; ++i)
                {
                    auto availible_room_schedule = new_schedule.OfRoom(rooms[i]).AvailableTimeSlots(n_time_slots);

                    auto final_availibility = commonElements(availible_room_schedule,time_slots);


                    if(!final_availibility.empty())
                    {

                        SchedulingItem new_item(course, teacher->first, rooms[i], final_availibility[0],year.first);
                        new_schedule.InsertScheduleItem(new_item);
                        assigned_flag = true;


                    }



                }

                if( not assigned_flag)
                {
                    throw NoViableSolutionFound();
                }



            }





        }




        return new_schedule;
    }

}



