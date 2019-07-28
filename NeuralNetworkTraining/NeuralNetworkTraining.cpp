#include <iostream>

#include "NeuralNetworkTraining.h"
#include "sc2api/sc2_api.h"


NeuralNetworkTraining::NeuralNetworkTraining()
{

}


void NeuralNetworkTraining::OnGameStart()
{

}

void NeuralNetworkTraining::OnStep() {
	Observation();
	// What your bot does every game step
}

void NeuralNetworkTraining::OnUnitDestroyed(const sc2::Unit *unit)
{

}
void NeuralNetworkTraining::OnUnitEnterVision(const sc2::Unit *unit)
{

}

void NeuralNetworkTraining::OnBuildingConstructionComplete(const sc2::Unit* unit)
{

}

void NeuralNetworkTraining::OnUnitCreated(const sc2::Unit *unit)
{

}

void NeuralNetworkTraining::OnUnitIdle(const sc2::Unit *unit)
{
	
}

