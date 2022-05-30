#include "priority.hpp"
#include <iostream>
#include <boost/hof.hpp>

Priority::Priority() : queue(boost::hof::proj(&Process::priority, std::less{}))
{
    return;
}

void Priority::setup()
{
    Scheduler::setup();
    std::cout << "additional parameter" << std::endl;
    for (Process &i : wait)
    {
        std::cout << i.name << "'s priority" << std::endl;
        std::cin >> i.priority;
    }
    return;
}

void Priority::create_process(Process process)
{
    queue.push(process);
    std::cout << "arrived: " << process.name << std::endl;
    return;
}

void Priority::switch_process()
{
    if (running.status == Status::finished)
    {
        running.finish_time = time;
        finished.push_back(running);
        running.status = Status::none;
    }
    if (queue.size() != 0 && running.status != Status::none && running.priority < queue.top().priority)
    {
        queue.push(running);
        running.status = Status::none;
    }
    if (running.status == Status::none && queue.size() != 0)
    {
        running = queue.top();
        queue.pop();
    }
    return;
}
