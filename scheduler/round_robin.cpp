#include "round_robin.hpp"
#include <iostream>

void RoundRobin::setup()
{
    Scheduler::setup();
    std::cout << "input time slice" << std::endl;
    std::cin >> time_slice;
    return;
}

void RoundRobin::create_process(Process process)
{
    queue.push(process);
    std::cout << "arrived: " << process.name << std::endl;
    return;
}

void RoundRobin::switch_process()
{
    if (running.status == Status::finished)
    {
        running.finish_time = time;
        finished.push_back(running);
        running.status = Status::none;
    }
    if (running.status == Status::none && queue.size() != 0)
    {
        running = queue.front();
        queue.pop();
        duration = 0;
    }
    return;
}

void RoundRobin::do_process()
{
    Scheduler::do_process();
    if (running.status == Status::running)
    {
        duration++;
        if (time_slice <= duration)
        {
            queue.push(running);
            running.status = Status::none;
        }
    }
}
