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
