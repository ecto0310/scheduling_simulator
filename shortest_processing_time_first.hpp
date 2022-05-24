#pragma once

#include <queue>
#include <vector>

#include "scheduler.hpp"

class ShortestProcessingTimeFirst : public Scheduler
{
public:
    ShortestProcessingTimeFirst();
    void create_process(Process) override;
    void switch_process() override;
    void do_process() override;

private:
    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> queue;
};
