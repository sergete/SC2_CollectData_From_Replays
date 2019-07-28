#ifndef _COMPILEDATA_HPP_
#define _COMPILEDATA_HPP_

#include <iostream>
#include <stdbool.h>
#include "sc2api/sc2_api.h"
#include "sc2lib/sc2_lib.h"
#include <vector>
#include "UnitData.h"
//Input Output file
#include <fstream>
#include <iostream>

class CompileData
{
public:
	CompileData(sc2::Race PlayerRace, sc2::Race enemyRace,const sc2::ObservationInterface *obs, int numTotalExpansions);
	~CompileData();

	void IntroduceData(double time);

	void addEnemyUnit(const sc2::Unit* unit, const ObservationInterface *obs);
	void removeEnemyUnit(const sc2::Unit* unit, const ObservationInterface *obs);

	void addUpgradeOutput(sc2::UpgradeID upgrade_id, double currentLoopTime);
	void addUnitOuptut(const sc2::Unit* unit, double currentLoopTime);
	void addStructureOutput(const sc2::Unit *unit);

	void saveData(const char* PATH_TO_CREATE_FILE, int fileIndex);

private:
	sc2::Race PlayerRace;
	sc2::Race EnemyRace;
	const sc2::ObservationInterface *observation;
	std::map<double, std::vector<double>> inputData;
	std::map<double, std::vector<double>> outputData;

	//constant index
	const int OUTPUT_FINAL_INDEX_STALKER = 14;
	const int OUTPUT_FINAL_INDEX_VOIDRAY = 17;

	//constant size
	const int INPUT_ARRAY_SIZE = 57;
	const int OUTPUT_ARRAY_SIZE = 41;
	
	//ALL VALUES OF INPUT LAYER
	//0 time
	//1 to 4 index of races 1-Terran 2-Zerg 3-Protoss 4-Random in input layer 
	std::vector<int> races;

	//5 num Nexus that has the player builded
	//numNexus;

	//6 vespene geysers builded
	//numGasBuildings;

	//7 number of expansions available
	int numTotalExpansions;

	//OWN UNITS
	//8 - 10 Production units (Just production) Protoss
	// numOwnGateway;
	// numOwnStargate;
	// numOwnRoboticsFacility;
	//11-17 technology buildings
	// numOwnForge;
	// numOwnCyberneticsCore;
	// numOwnRoboticsBay;
	// numOwnTwilightCouncil;
	// numOwnFleetBacon;
	// numOwnDarkShrine;
	//always 0 because is a build that we have to avoid, the bot will not use the units that the upgrades are aimed for
	// numOwnTemplayerArchives;

	//ENEMY UNITS
	std::set<const sc2::Unit *> enemies;
	std::unordered_map<sc2::UNIT_TYPEID, std::set<const sc2::Unit *>> structureEnemies;
	std::set<const sc2::Unit *> enemies_harvesters;

	//18 production units in Zerg are Hatchery (Enemy) Zerg
	// numHatcheries;
	//19-27 technology buildings
	// numSpawningPool;
	// numBanelingNest;
	// numRoachWarren;
	// numHydraliskDen;
	// numLurkerDen;
	// numSpire;
	// numGreaterSpire;
	// numUltraliskCavern;

	//28 - 30 Production units (Just Enemy production) Terran
	// numBarracks;
	// numFactory;
	// numStarport;
	//31 - 34 Production units (Just production)
	// numEngineeringBay;
	// numGhostAcademy;
	// numFusionCore;
	// numArmory;

	//35 - 37 Production units (Just production) Protoss
	// numGateway;
	// numStargate;
	// numRoboticsFacility;
	//38 - 44 technology buildings
	// numForge;
	// numCyberneticsCore;
	// numRoboticsBay;
	// numTwilightCouncil;
	// numTemplayerArchives;
	// numDarkShrine;
	// numFleetBacon;

	//My combat units
	//45 - 49
	// numZealots;
	// numStalkers;
	// numPhoenix;
	// numVoidRay;
	// numDarkTemplar

	//50 - Number of enemy´s combat units ZERG
	// numZergEnemies;

	//51 - Number of enemy´s combat units TERRAN
	// numTerranEnemies;

	//52 - Number of enemy´s combat units PROTOSS
	// numProtossEnemies;

	//53 - 56 minerals and gas resources, number units
	// totalMineralResources;
	// totalGasResources;
	// numEnemyBaseExtensions;
	// numEnemyWorkers;


	//ALL VALUES OF OUTPUT LAYER
	//
	//Buildings
	//0 Nexus
	//1 Pylon
	//2 Assimilator
	//3 Gateway
	//4 Forge
	//5 PhotonCannon
	//6 CyberneticsCore
	//7 RoboticsFacility
	//8 Stargate
	//9 Twilight Council
	//10 RoboticsBay
	//11 Fleet Beacon
	//12 Dark Shrine
	//Units
	//13 Zealot
	//14 Stalker
	//15 Dark Templar
	//16 Phoenix
	//17 Void Ray
	//Upgrades
	//Forge Upgrades
	//18 SCUpgrade/Ground Weapons Level 1
	//19 SCUpgrade/Ground Armor Level 1
	//20 SCUpgrade/Shields Level 1
	//Cybernetics Core
	//21 SCUpgrade/Warp Gate
	//22 SCUpgrade/Air Weapons Level 1
	//23 SCUpgrade/Air Armor Level 1
	//Twilight Council
	//24 SCUpgrade/Blink
	//25 SCUpgrade/Charge
	//26 SCUpgrade/Ground Weapons Level 2
	//27 SCUpgrade/Ground Weapons Level 3
	//28 SCUpgrade/Ground Armor Level 2
	//29 SCUpgrade/Ground Armor Level 3
	//30 SCUpgrade/Shields Level 2
	//31 SCUpgrade/Shields Level 3
	//Robotics Bay
	//32 SCUpgrade/Gravity Booster
	//33 SCUpgrade/Gravitic Drive
	//34 SCUpgrade/Extended termal lance
	//Fleet Beacon
	//35 SCUpgrade/Anyon Pulse-Crystals
	//36 SCUpgrade/Graviton Catapult
	//37 SCUpgrade/Air Weapons Level 2
	//38 SCUpgrade/Air Weapons Level 3
	//39 SCUpgrade/Air Armor Level 2
	//40 SCUpgrade/Air Armor Level 3
	//

	//Functions
	int RaceToBinary(sc2::Race race);
	sc2::Units FilterMyArmyUnits(Units *zealotUnits, Units *stalkerUnits, Units *phoenixUnits, Units *voidRayUnits, Units *darkTemplarUnits);
	void CompleteMyOwnUnitsCount(Units *notUsefulUnits, double *numZealots, double *numStalkers, double *numPhoenix, double *numVoidRay);
	int getUsefulUnitIndex(const Unit *notUsefulUnit);


	//add remove enemies from list 
	void addEnemyStructure(const sc2::Unit* unit);
	void addEnemy(const sc2::Unit* unit);
	void addEnemyHarvester(const sc2::Unit* unit);
	void removeEnemyStructure(const sc2::Unit* unit);
	void removeEnemy(const sc2::Unit* unit);
	void removeEnemyHarvester(const sc2::Unit* unit);

	//add own units, buildings and upgrades
	int getUpgradeOutputIndex(sc2::UpgradeID upgrade_id);
	int getUnitOutputIndex(const sc2::Unit *unit);

	void setClosestOutputTime(int index, double time, double value);

};

#endif // !_COMPILEDATA_HPP_

