#include "CompileData.h"

#pragma region cpp Methods

/// <summary>
/// private method to filter the obtained units by type and return the total number of the 
/// found units
/// </summary>
/// <param name="units"> vector of all production units</param>
/// <param name="typeId">the type of building that we are searching</param>
/// <returns></returns>
int FilterUnitsByType(sc2::Units units, sc2::UNIT_TYPEID typeId) {

	int contador = 0;

	for each (const Unit *u in units)
	{
		if (u->unit_type == typeId) {
			contador++;
		}
	}

	return contador;
}

double getCountEnemiesOfType(std::unordered_map<sc2::UNIT_TYPEID, std::set<const sc2::Unit *>> *EnemiesMap, sc2::UNIT_TYPEID typeId) {

	if (EnemiesMap->find(typeId) == EnemiesMap->end()) {
		return 0;
	}
	else {
		return (double)EnemiesMap->at(typeId).size();
	}
}

void setValueFromTo(int from, int to, double value, std::vector<double> *vec) {

	for (int i = from; i <= to; i++) {
		vec->push_back(value);
	}
}

#pragma endregion


CompileData::CompileData(sc2::Race PlayerRace, sc2::Race enemyRace,const sc2::ObservationInterface *obs, int numTotalExpansions):observation(obs)
{
	this->PlayerRace = PlayerRace;
	this->EnemyRace = enemyRace;

	//Initialize races for this we have to initialize setPlayerRace first for default the value is Random
	races.push_back(RaceToBinary(sc2::Race::Terran));
	races.push_back(RaceToBinary(sc2::Race::Zerg));
	races.push_back(RaceToBinary(sc2::Race::Protoss));
	races.push_back(RaceToBinary(sc2::Race::Random));

	this->numTotalExpansions = numTotalExpansions;

	this->IntroduceData(0);
}


CompileData::~CompileData()
{
}

int CompileData::RaceToBinary(sc2::Race race)
{
	if (race == EnemyRace) {
		return 1;
	}
	else {
		return 0;
	}
}

void CompileData::IntroduceData(double time)
{
	//NN inputs
	std::vector<double> currentData;
	//NN outputs
	std::vector<double> expectedOutput(this->OUTPUT_ARRAY_SIZE, 0);

#pragma region 0-17 own Units
	//0
	currentData.push_back(time);
	//
	//1 to 4 is races already initialized
	currentData.push_back(races.at(0));
	currentData.push_back(races.at(1));
	currentData.push_back(races.at(2));
	currentData.push_back(races.at(3));
	//
	//5 num nexus
	currentData.push_back(this->observation->GetUnits(sc2::Unit::Alliance::Self, IsTownHall()).size());
	//6 num vespene
	currentData.push_back(this->observation->GetUnits(sc2::Unit::Alliance::Self, IsAssimilator()).size());
	//
	//7 total expansions is constant, already defined in constructor
	currentData.push_back(this->numTotalExpansions);
	//
	// 8 - 10 my production units 
	//get all structure units
	Units units = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsStructure(this->observation));

	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_GATEWAY));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_STARGATE));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY));
	
	//11-17 technology buildings
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_FORGE));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_CYBERNETICSCORE));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_ROBOTICSBAY));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_FLEETBEACON));
	currentData.push_back(FilterUnitsByType(units, sc2::UNIT_TYPEID::PROTOSS_DARKSHRINE));

	//this units always will be 0 because i wont use it in my bot (Templar archives)
	//17
	currentData.push_back(0);
#pragma endregion

#pragma region 18-27 if enemy is Zerg 
	if (!races.at(1) == 1) {
		setValueFromTo(18, 27, 0, &currentData);
	}
	else {
		//18 hatcheries
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_HATCHERY));
		//19-27 technology buildings
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_SPAWNINGPOOL));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_BANELINGNEST));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_ROACHWARREN));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_HYDRALISKDEN));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_LURKERDENMP));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_SPIRE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_GREATERSPIRE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::ZERG_ULTRALISKCAVERN));
	}
#pragma endregion

#pragma region 28-34 if enemy is Terran
	if (!races.at(0) == 1) {
		setValueFromTo(28, 34, 0, &currentData);
	}
	else {
		//28 - 30 Production units (Just Enemy production) Terran
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_BARRACKS));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_FACTORY));		
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_STARPORT));
		//31 - 34 Production units (Just production)
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_ENGINEERINGBAY));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_GHOSTACADEMY));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_FUSIONCORE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::TERRAN_ARMORY));
	}
#pragma endregion

#pragma region 35-44 if enemy is Protoss
	if (!races.at(2) == 1) {
		setValueFromTo(35, 44, 0, &currentData);
	}
	else {
		//35 - 37 Production units (Just Enemy production) Terran
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_GATEWAY));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_STARGATE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY));
		//38 - 44 Production units (Just production)
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_FORGE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_CYBERNETICSCORE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_ROBOTICSBAY));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_DARKSHRINE));
		currentData.push_back(getCountEnemiesOfType(&this->structureEnemies, sc2::UNIT_TYPEID::PROTOSS_FLEETBEACON));
	}
#pragma endregion

#pragma region 45-49 Filter Own Units
	Units zealotUnits = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsZealot());
	Units stalkerUnits = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsStalker());
	Units phoenixUnits = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsPhoenix());
	Units voidRayUnits = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsVoidRay());
	Units darkTemplarUnits = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsDarkTemplar());

	double numZealots = zealotUnits.size();
	double numStalkers = stalkerUnits.size();
	double numPhoenix = phoenixUnits.size();
	double numVoidRay = voidRayUnits.size();
	double numDarkTemplar = darkTemplarUnits.size();

	Units notUsefulUnits = FilterMyArmyUnits(&zealotUnits, &stalkerUnits, &phoenixUnits, &voidRayUnits, &darkTemplarUnits);
	CompleteMyOwnUnitsCount(&notUsefulUnits, &numZealots, &numStalkers, &numPhoenix, &numVoidRay);

	currentData.push_back(numZealots);
	currentData.push_back(numStalkers);
	currentData.push_back(numPhoenix);
	currentData.push_back(numVoidRay);
	currentData.push_back(numDarkTemplar);
#pragma endregion

#pragma region 50-51-52 depending of race number of enemies detected

	//enemy units
	double numTerranEnemies = 0;
	double numZergEnemies = 0;
	double numProtossEnemies = 0;

	if (races.at(0) == 1) {
		numTerranEnemies = this->enemies.size();
	}
	if (races.at(1) == 1) {
		numZergEnemies = this->enemies.size();
	}
	if (races.at(2) == 1) {
		numProtossEnemies = this->enemies.size();
	}

	currentData.push_back(numTerranEnemies);
	currentData.push_back(numZergEnemies);
	currentData.push_back(numProtossEnemies);

#pragma endregion

#pragma region 53 - 56 
	//minerals
	currentData.push_back(this->observation->GetUnits(sc2::Unit::Alliance::Neutral, IsMineral()).size());
	//gas
	currentData.push_back(this->observation->GetUnits(sc2::Unit::Alliance::Neutral, IsVespeneGeyser()).size());
	
	double numEnemyBaseExtensions = 0;
	//enemy base extensions
	if (races.at(0) == 1) {	//Terrans
		if (this->structureEnemies.count(sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER) != 0) {
			numEnemyBaseExtensions = this->structureEnemies.at(sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER).size();
		}
	}
	if (races.at(1) == 1) {	//Zergs
		if (this->structureEnemies.count(sc2::UNIT_TYPEID::ZERG_HATCHERY) != 0) {
			numEnemyBaseExtensions = this->structureEnemies.at(sc2::UNIT_TYPEID::ZERG_HATCHERY).size();
		}
	}
	if (races.at(2) == 1) {	//Protoss
		if (this->structureEnemies.count(sc2::UNIT_TYPEID::PROTOSS_NEXUS) != 0) {
			numEnemyBaseExtensions = this->structureEnemies.at(sc2::UNIT_TYPEID::PROTOSS_NEXUS).size();
		}
	}

	currentData.push_back(numEnemyBaseExtensions);

	//Enemy harvesters
	double numEnemyHarvesters = this->enemies_harvesters.size();
	currentData.push_back(numEnemyHarvesters);

#pragma endregion

	this->inputData.insert({ time, currentData });
	this->outputData.insert({ time, expectedOutput });
}


#pragma region add and remove enemy Units

/// <summary>
/// Pulic Method
/// add to list of enemy units de destroyed unit
/// </summary>
/// <param name="unit"></param>
/// <param name="obs"></param>
void CompileData::addEnemyUnit(const sc2::Unit * unit, const ObservationInterface * obs)
{
		printf("Añadida unidad del enemigo: %s \n", unit->unit_type.to_string().c_str());
		UNIT_TYPEID str = unit->unit_type.ToType();
		if (UnitData::isStructure(unit)) {
			printf("Es estructura \n");
			this->addEnemyStructure(unit);
		}
		else {
			if (UnitData::isEnemyArmy(unit, obs)) {
				printf("Es enemy army \n");
				this->addEnemy(unit);
			}
			else if (UnitData::isEnemyHarvester(unit)) {
				printf("Es harvester \n");
				this->addEnemyHarvester(unit);
			}
		}	
}

/// <summary>
/// Public Method
/// Remove from list of enemy units de destroyed unit
/// </summary>
/// <param name="unit"></param>
/// <param name="obs"></param>
void CompileData::removeEnemyUnit(const sc2::Unit * unit, const ObservationInterface * obs)
{
	printf("Borrada Unidad del enemigo: %s \n", unit->unit_type.to_string().c_str());
	if (UnitData::isStructure(unit)) {
		this->removeEnemyStructure(unit);
		printf("Es estructura \n");
	}
	else {
		if (UnitData::isEnemyArmy(unit, obs)) {
			this->removeEnemy(unit);
			printf("Es army unit \n");
		}
		else if (UnitData::isEnemyHarvester(unit)) {
			this->removeEnemyHarvester(unit);
			printf("Es harvester \n");
		}
	}
}

	#pragma region Private Methods

void CompileData::addEnemyStructure(const sc2::Unit* unit)
{
	if (this->structureEnemies.count(unit->unit_type) != 0) {
		this->structureEnemies.at(unit->unit_type).insert(unit);
	}
	else {
		std::set<const sc2::Unit *> tempStructureSet;
		tempStructureSet.insert(unit);

		this->structureEnemies.insert({ unit->unit_type, tempStructureSet });
	}
}

void CompileData::removeEnemyStructure(const sc2::Unit * unit)
{
	this->structureEnemies.at(unit->unit_type).erase(unit);
}

void CompileData::addEnemy(const sc2::Unit* unit)
{
	this->enemies.insert(unit);
}

void CompileData::removeEnemy(const sc2::Unit * unit)
{
	this->enemies.erase(unit);
}

void CompileData::addEnemyHarvester(const sc2::Unit* unit)
{
	this->enemies_harvesters.insert(unit);
}

void CompileData::removeEnemyHarvester(const sc2::Unit * unit)
{
	this->enemies_harvesters.erase(unit);
}

#pragma endregion

#pragma endregion

#pragma region classify output data

//PUBLIC METHODS

/// <summary>
/// Receive the upgrade created by the player and transform the time of investigation to
/// minutes to add to the output map 
/// </summary>
/// <param name="upgrade_id"></param>
void CompileData::addUpgradeOutput(sc2::UpgradeID upgrade_id, double currentLoopTime)
{
	//double time = UnitData::getTimeToProduceUpgrade(upgrade_id);

	//printf("UPGRADE: Time to produce: %f", time);

	if (time != 0) {
		//iterator with the closest time to the time
		std::map<double, std::vector<double>>::iterator low;

		low = this->outputData.lower_bound(currentLoopTime);

		//if not result found, do nothing
		if (low == this->outputData.end()) {
			--low;
		}

		int upgradeIndex = getUpgradeOutputIndex(upgrade_id);
		if (upgradeIndex != -1) {
			low->second.at(upgradeIndex) = 1;
		}
	}
}

/// <summary>
/// defines what kind of unit is and add it in his index output depending of his production time
/// </summary>
/// <param name="unit">unit type</param>
/// <param name="build_time">time to produce</param>
void CompileData::addUnitOuptut(const sc2::Unit * unit, double currentLoopTime)
{
	if (unit->build_progress > 0.8) return;

	UNIT_TYPEID unitType;
	
	int index = getUnitOutputIndex(unit);
	unitType = unit->unit_type;

	if (UnitData::isStructure(unit)) {
		if (UnitData::isUsefulStructure(unit)) {

			printf("addUnitOuptut Structure: produced: %f", currentLoopTime);
			setClosestOutputTime(index, currentLoopTime, 1);
		}
	}
	else {
		Units units = observation->GetUnits(IsArmy(observation));
		if (std::find(units.begin(), units.end(), unit) != units.end() && unit->unit_type != UNIT_TYPEID::PROTOSS_OBSERVER) {
			if (!UnitData::isUsefulUnit(unit)) {				
				index = getUsefulUnitIndex(unit);

				if (index == OUTPUT_FINAL_INDEX_STALKER) {
					unitType = UNIT_TYPEID::PROTOSS_STALKER;
				}
				else {
					unitType = UNIT_TYPEID::PROTOSS_VOIDRAY;
				}
			}

			printf("addUnitOuptut: Time to produce: %f", currentLoopTime);
			setClosestOutputTime(index, currentLoopTime, 1);
		}
		
	}
}

void CompileData::addStructureOutput(const sc2::Unit * unit)
{
}

void CompileData::saveData(const char * PATH_TO_CREATE_FILE, int fileIndex)
{
	std::string fname = std::to_string(PlayerRace) + "-" + std::to_string(EnemyRace) + std::to_string(fileIndex);

	std::fstream appendFileToWorkWith;

	appendFileToWorkWith.open(fname.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

	// If file does not exist, Create new file
	if (!appendFileToWorkWith)
	{
		std::cout << "Cannot open file, file does not exist. Creating new file..";

		appendFileToWorkWith.open(fname.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
		//appendFileToWorkWith.close();
	}

	appendFileToWorkWith << std::to_string(INPUT_ARRAY_SIZE) << " " << std::to_string(OUTPUT_ARRAY_SIZE) << "\n";
	appendFileToWorkWith << "INPUT_LAYER\n";

	std::map<double, std::vector<double>>::iterator it;

	//Data for input layer
	for (it = inputData.begin(); it != inputData.end(); it++) {
		//in a line save the time
		appendFileToWorkWith << std::to_string(it->first) << "\n";
		for (int j = 0; j < it->second.size(); j++) {
			appendFileToWorkWith << std::to_string(it->second.at(j)) << " ";
		}
		appendFileToWorkWith << "\n";
	}

	appendFileToWorkWith << "OUTPUT_LAYER\n";
	//Data for output layer
	for (it = outputData.begin(); it != outputData.end(); it++) {
		//in a line save the time
		appendFileToWorkWith << std::to_string(it->first) << "\n";
		for (int j = 0; j < it->second.size(); j++) {
			appendFileToWorkWith << std::to_string(it->second.at(j)) << " ";
		}
		appendFileToWorkWith << "\n";
	}

	appendFileToWorkWith.close();
}

//PRIVATE METHODS 

/// <summary>
/// From the input param time, calculate in a map the closest key to this value and add to the output array in the output map
/// </summary>
/// <param name="index"></param>
/// <param name="time"></param>
/// <param name="value"></param>
void CompileData::setClosestOutputTime(int index, double time, double value)
{
	if (time != 0) {
		//iterator with the closest time to the time
		std::map<double, std::vector<double>>::iterator low, prev;

		low = this->outputData.lower_bound(time);

		//if not result found, do nothing
		if (low == this->outputData.end()) {
			//nothing found then try to get the last value of map
			--low;
		}

		if (index != -1) {
			low->second.at(index) = value;
		}
	}
}

/// <summary>
/// get Upgrade index
/// </summary>
/// <param name="upgrade_id"></param>
/// <returns></returns>
int CompileData::getUpgradeOutputIndex(sc2::UpgradeID upgrade_id)
{
	int index = 0.0;

	switch (UPGRADE_ID(upgrade_id))
	{
		//ForgeUpgrades
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL1:
		index = 18;
		break;
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL1:
		index = 19;
		break;
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL1:
		index = 20;
		break;
		//Cybernetics Core
	case UPGRADE_ID::WARPGATERESEARCH:
		index = 21;
		break;
	case UPGRADE_ID::PROTOSSAIRWEAPONSLEVEL1:
		index = 22;
		break;
	case UPGRADE_ID::PROTOSSAIRARMORSLEVEL1:
		index = 23;
		break;
		//Twilight Council
	case UPGRADE_ID::BLINKTECH:
		index = 24;
		break;
	case UPGRADE_ID::CHARGE:
		index = 25;
		break;
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL2:
		index = 26;
		break;
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL3:
		index = 27;
		break;
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL2:
		index = 28;
		break;
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL3:
		index = 29;
		break;
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL2:
		index = 30;
		break;
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL3:
		index = 31;
		break;
		//RoboticsBay
	case UPGRADE_ID::OBSERVERGRAVITICBOOSTER:
		index = 32;
		break;
	case UPGRADE_ID::GRAVITICDRIVE:
		index = 33;
		break;
	case UPGRADE_ID::EXTENDEDTHERMALLANCE:
		index = 34;
		break;
		//Fleet Beacon
	case UPGRADE_ID::PHOENIXRANGEUPGRADE:
		index = 35;
		break;
	case UPGRADE_ID::CARRIERLAUNCHSPEEDUPGRADE:
		index = 36;
		break;
	case UPGRADE_ID::PROTOSSAIRWEAPONSLEVEL2:
		index = 37;
		break;
	case UPGRADE_ID::PROTOSSAIRWEAPONSLEVEL3:
		index = 38;
		break;
	case UPGRADE_ID::PROTOSSAIRARMORSLEVEL2:
		index = 39;
		break;
	case UPGRADE_ID::PROTOSSAIRARMORSLEVEL3:
		index = 40;
		break;
	default:
		index = -1;
		break;
	}

	return index;
}

int CompileData::getUnitOutputIndex(const sc2::Unit * unit)
{
	int index = 0.0;

	switch (UNIT_TYPEID(unit->unit_type))
	{
	case UNIT_TYPEID::PROTOSS_NEXUS:
		index = 0;
		break;
	case UNIT_TYPEID::PROTOSS_PYLON:
		index = 1;
		break;
	case UNIT_TYPEID::PROTOSS_ASSIMILATOR:
		index = 2;
		break;
	case UNIT_TYPEID::PROTOSS_GATEWAY:
		index = 3;
		break;
	case UNIT_TYPEID::PROTOSS_FORGE:
		index = 4;
		break;
	case UNIT_TYPEID::PROTOSS_PHOTONCANNON:
		index = 5;
		break;
	case UNIT_TYPEID::PROTOSS_CYBERNETICSCORE:
		index = 6;
		break;
	case UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY:
		index = 7;
		break;
	case UNIT_TYPEID::PROTOSS_STARGATE:
		index = 8;
		break;
	case UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL:
		index = 9;
		break;
	case UNIT_TYPEID::PROTOSS_ROBOTICSBAY:
		index = 10;
		break;
	case UNIT_TYPEID::PROTOSS_FLEETBEACON:
		index = 11;
		break;
	case UNIT_TYPEID::PROTOSS_DARKSHRINE:
		index = 12;
		break;
		//Units
	case UNIT_TYPEID::PROTOSS_ZEALOT:
		index = 13;
		break;
		//RoboticsBay
	case UNIT_TYPEID::PROTOSS_STALKER:
		index = 14;
		break;
	case UNIT_TYPEID::PROTOSS_DARKTEMPLAR:
		index = 15;
		break;
	case UNIT_TYPEID::PROTOSS_PHOENIX:
		index = 16;
		break;
		//Fleet Beacon
	case UNIT_TYPEID::PROTOSS_VOIDRAY:
		index = 17;
		break;
	default:
		index = -1;
		break;
	}

	return index;
}

#pragma endregion


/// <summary>
/// Return an array of army units that we dont need in out Neural network
/// we have to process this units in other method to transform in useful units
/// </summary>
/// <returns></returns>
sc2::Units CompileData::FilterMyArmyUnits(Units *zealotUnits, Units *stalkerUnits, Units *phoenixUnits, Units *voidRayUnits, Units *darkTemplarUnits)
{
	Units notUsefulUnits;

	//get all army units
	Units units = this->observation->GetUnits(sc2::Unit::Alliance::Self, IsArmy(this->observation));
	
	for each (const Unit *u in units)
	{
		if (std::find(zealotUnits->begin(), zealotUnits->end(), u) == zealotUnits->end()) {
			if (std::find(stalkerUnits->begin(), stalkerUnits->end(), u) == stalkerUnits->end()) {
				if (std::find(phoenixUnits->begin(), phoenixUnits->end(), u) == phoenixUnits->end()) {
					if (std::find(voidRayUnits->begin(), voidRayUnits->end(), u) == voidRayUnits->end()) {
						if (std::find(darkTemplarUnits->begin(), darkTemplarUnits->end(), u) == darkTemplarUnits->end()) {
							//if unit is not contained in any vector then add to array to process later
							notUsefulUnits.push_back(u);
						}
					}
				}
			}
		}
	}

	return notUsefulUnits;
}

void CompileData::CompleteMyOwnUnitsCount(Units *notUsefulUnits, double * numZealots, double * numStalkers, double * numPhoenix, double * numVoidRay)
{
	for each (const Unit *u in *notUsefulUnits)
	{
		if (u->is_flying) {
			(*numVoidRay)++;
		}
		else {
			(*numStalkers)++;
		}
	}
}

int CompileData::getUsefulUnitIndex(const Unit * notUsefulUnit)
{
	if (notUsefulUnit->is_flying) {
		return OUTPUT_FINAL_INDEX_VOIDRAY;
	}
	else {
		return OUTPUT_FINAL_INDEX_STALKER;
	}
}


