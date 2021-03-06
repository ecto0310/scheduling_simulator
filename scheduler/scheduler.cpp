#include "scheduler.hpp"
#include <iostream>
#include <boost/hof.hpp>

Scheduler::Scheduler() : time(0),
                         running({.status = none})
{
    return;
}

void Scheduler::setup()
{
    std::cout << "input process quantity" << std::endl;
    std::cin >> process_count;

    std::cout << "input process detail" << std::endl
              << "name arrival-time cost" << std::endl;
    for (int i = 0; i < process_count; i++)
    {
        Process t = {};
        std::cin >> t.name >> t.arrival_time >> t.cost;
        wait.push_back(t);
    }
    sort(wait.begin(), wait.end(), [](const Process &l, const Process &r)
         { return l.arrival_time < r.arrival_time; });
    return;
}

void Scheduler::run()
{
    for (;; time++)
    {
        std::cout << "time: " << time << std::endl;
        while (wait.size() != 0 && wait.front().arrival_time <= time)
        {
            create_process(wait.front());
            wait.pop_front();
        }
        switch_process();
        if (finish())
        {
            std::cout << "finish all process" << std::endl;
            break;
        }
        do_process();
    }
    result();
}

bool Scheduler::finish() const
{
    if ((int)finished.size() == process_count)
    {
        return true;
    }
    return false;
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

void Scheduler::do_process()
{
    if (running.status == Status::running)
    {
        running.progress++;
        std::cout << "running: " << running.name << " (" << running.progress << "/" << running.cost << ")" << std::endl;
        if (running.progress == running.cost)
        {
            std::cout << "finished: " << running.name << std::endl;
            running.status = Status::finished;
        }
    }
    else
    {
        std::cout << "no process" << std::endl;
    }
    return;
}
