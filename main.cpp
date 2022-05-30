#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "scheduler/scheduler.hpp"

#include "scheduler/first_come_first_service.hpp"
#include "scheduler/shortest_processing_time_first.hpp"
#include "scheduler/round_robin.hpp"
#include "scheduler/priority.hpp"

void create_scheduler(Scheduler *&scheduler);

int main()
{
    Scheduler *scheduler = nullptr;
    create_scheduler(scheduler);
    if (scheduler == nullptr)
    {
        std::cout << "unimplemented scheduler" << std::endl;
        return 1;
    }

    scheduler->setup();
    scheduler->run();
    return 0;
}

void create_scheduler(Scheduler *&scheduler)
{
    std::cout << "input scheduler type" << std::endl
              << "0: first come first service" << std::endl
              << "1: shortest processing time first" << std::endl
              << "2: round robin" << std::endl
              << "3: priority" << std::endl;
    int type;
    std::cin >> type;
    switch (type)
    {
    case 0:
        scheduler = (Scheduler *)new FirstComeFirstService();
        break;
    case 1:
        scheduler = (Scheduler *)new ShortestProcessingTimeFirst();
        break;
    case 2:
        scheduler = (Scheduler *)new RoundRobin();
        break;
    case 3:
        scheduler = (Scheduler *)new Priority();
        break;
    default:
        break;
    }
    return;
}
