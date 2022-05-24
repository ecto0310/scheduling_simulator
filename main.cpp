#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "scheduler.hpp"

#include "first_come_first_service.hpp"
#include "shortest_processing_time_first.hpp"

void create_scheduler(Scheduler *&scheduler);

int main()
{
    Scheduler *scheduler;
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
              << "1: shortest processing time first" << std::endl;
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
    default:
        break;
    }
    return;
}
