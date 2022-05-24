#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "scheduler.hpp"

void create_scheduler(Scheduler **scheduler);
void create_processes(Scheduler *scheduler);

int main()
{
    Scheduler *scheduler;
    create_scheduler(&scheduler);
    if (scheduler == NULL)
    {
        std::cout << "unimplemented scheduler" << std::endl;
        return 1;
    }

    create_processes(scheduler);

    scheduler->run();
    return 0;
}

void create_scheduler(Scheduler **scheduler)
{
    std::cout << "input scheduler type" << std::endl;
    int type;
    std::cin >> type;
    switch (type)
    {
    default:
        break;
    }
    return;
}

void create_processes(Scheduler *scheduler)
{
    std::cout << "input process quantity" << std::endl;
    int N;
    std::cin >> N;

    std::cout << "input process detail" << std::endl
              << "name arrival-time cost" << std::endl;
    for (int i = 0; i < N; i++)
    {
        Process t = {};
        std::cin >> t.name >> t.arrival_time >> t.cost;
        scheduler->wait.push(t);
    }

    std::cout << "input time limit" << std::endl;
    std::cin >> scheduler->limit_time;
    return;
}
