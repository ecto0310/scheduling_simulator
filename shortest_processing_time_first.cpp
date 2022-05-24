#include "shortest_processing_time_first.hpp"
#include <iostream>
#include <boost/hof.hpp>

ShortestProcessingTimeFirst::ShortestProcessingTimeFirst() : queue(boost::hof::proj(&Process::cost, std::greater{}))
{
    return;
}

void ShortestProcessingTimeFirst::create_process(Process process)
{
    queue.push(process);
    std::cout << "arrived: " << process.name << std::endl;
    return;
}

void ShortestProcessingTimeFirst::switch_process()
{
    if (running.status == Status::finished)
    {
        running.finish_time = time;
        finished.push_back(running);
        running.status = Status::none;
    }
    if (running.status == Status::none && queue.size() != 0)
    {
        running = queue.top();
        queue.pop();
    }
    return;
}

void ShortestProcessingTimeFirst::do_process()
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
