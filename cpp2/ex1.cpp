#include <iostream>

#include "Creature.h"

int main(void)
{
    Creature* pCreature;
    
    pCreature = new Monkey();
    pCreature->MakeNoise();
    delete pCreature;
    
    pCreature = new Duck();
    pCreature->MakeNoise();
    delete pCreature;
    
    pCreature = new Pig();
    pCreature->MakeNoise();
    delete pCreature;
    
    return 0;
}
