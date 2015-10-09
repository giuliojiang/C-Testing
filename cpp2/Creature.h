#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

class Creature
{
public:
    virtual ~Creature() {};
    virtual void MakeNoise() {};
};

class Monkey : public Creature
{
public:
    void MakeNoise();
};

class Duck : public Creature
{
public:
    void MakeNoise();
};

class Pig : public Creature
{
public:
    void MakeNoise();
};

#endif