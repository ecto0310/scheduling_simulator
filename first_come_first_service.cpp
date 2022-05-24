#include "first_come_first_service.hpp"
#include <iostream>

void FirstComeFirstService::create_process(Process process)
{
    queue.push(process);
    std::cout << "arrived: " << process.name << std::endl;
    return;
}

void FirstComeFirstService::switch_process()
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
    }
    return;
}

void FirstComeFirstService::do_process()
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
