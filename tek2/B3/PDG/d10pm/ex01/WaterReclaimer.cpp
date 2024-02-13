#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer() :
    _water(0),
    _started(false)
{
}

void    WaterReclaimer::start()
{
    if (_water <= 10)
        throw MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer");
    _started = true;
}

void    WaterReclaimer::useWater(int water)
{
    if (_water == 0)
        throw UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
    else if (water < 0)
        throw UserError("Water use should be positif.", "WaterReclaimer");
    else if (_water <= 10)
        throw LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    _water -= water;
}

void    WaterReclaimer::generateWater()
{
    if (_water + 10 <= 100)
        _water += 10;
    else
        throw NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer");
}
