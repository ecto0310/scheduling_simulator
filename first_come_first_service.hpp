#pragma once

#include <queue>
#include <vector>

#include "scheduler.hpp"

class FirstComeFirstService : public Scheduler
{
private:
    std::queue<Process> queue;

    void create_process(Process) override;
    void switch_process() override;
    void do_process() override;
};
