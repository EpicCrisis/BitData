
#include <iostream>
#include <cmath>
#include "BitData_Project.h"

BitData::BitData()
{
    reset();
}

void BitData::reset()
{
    m_data = 0;
}

void BitData::set(int _location, bool _flag) // Location is started at 0
{
    // If bool is same, skip checking.
    if (_flag == get(_location))
    {
        return;
    }

    m_data += (1 << _location) * (_flag ? 1 : -1);
}

bool BitData::get(int _location)
{
    // Start from the largest bit, at 32 then go down to 0.
    return (m_data >> _location) & 1;
}

void BitData::ListData(BitData _data)
{
    
}

int BitData::getData()
{
    return m_data;
}

void BitData::setData(int value)
{
    m_data = value;
}
