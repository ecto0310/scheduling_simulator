#include "scheduler.hpp"
#include <iostream>

Scheduler::Scheduler() : wait([](Process l, Process r)
                              { return r.arrival_time < l.arrival_time; }),
                         time(0),
                         running({.status = none})
{
    return;
}

void Scheduler::run()
{
    for (; time <= limit_time; time++)
    {
        std::cout << "time: " << time << std::endl;
        while (wait.size() != 0 && wait.top().arrival_time <= time)
        {
            create_process(wait.top());
            wait.pop();
        }
        switch_process();
        do_process();
    }
    result();
}

void Scheduler::result()
{
    std::cout << "name,arrival_time,finishe_time,response_time" << std::endl;
    int response_time_sum = 0;
    for (Process i : finished)
    {
        std::cout << i.name << "," << i.arrival_time << "," << i.finish_time << "," << i.finish_time - i.arrival_time << std::endl;
        response_time_sum += i.finish_time - i.arrival_time;
    }
    std::cout << "average response time: " << (double)response_time_sum / finished.size() << std::endl;
    return;
}
