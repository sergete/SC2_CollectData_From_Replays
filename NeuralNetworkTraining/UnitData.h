#ifndef _UNITDATA_HPP_
#define _UNITDATA_HPP_

#include "sc2api/sc2_interfaces.h"
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_map_info.h"
#include "sc2lib/sc2_lib.h"
#include <iostream>

using namespace sc2;

#pragma region Filter expressions (Lambdas)
struct IsArmy {
	IsArmy(const ObservationInterface* obs) : observation_(obs) {}

	bool operator()(const Unit& unit) {
		auto attributes = observation_->GetUnitTypeData().at(unit.unit_type).attributes;
		for (const auto& attribute : attributes) {
			if (attribute == Attribute::Structure) {
				return false;
			}
		}
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::ZERG_OVERLORD: return false;
		case UNIT_TYPEID::PROTOSS_PROBE: return false;
		case UNIT_TYPEID::ZERG_DRONE: return false;
		case UNIT_TYPEID::TERRAN_SCV: return false;
		case UNIT_TYPEID::ZERG_QUEEN: return false;
		case UNIT_TYPEID::ZERG_LARVA: return false;
		case UNIT_TYPEID::ZERG_EGG: return false;
		case UNIT_TYPEID::TERRAN_MULE: return false;
		case UNIT_TYPEID::TERRAN_NUKE: return false;
		default: return true;
		}
	}

	const ObservationInterface* observation_;
};

struct IsZealot {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_ZEALOT: return true;
		default: return false;
		}
	}
};

struct IsStalker {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_STALKER: return true;
		default: return false;
		}
	}
};

struct IsPhoenix {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_PHOENIX: return true;
		default: return false;
		}
	}
};

struct IsVoidRay {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_VOIDRAY: return true;
		default: return false;
		}
	}
};

struct IsDarkTemplar {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_DARKTEMPLAR: return true;
		default: return false;
		}
	}
};

struct IsAssimilator {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_ASSIMILATOR: return true;
		default: return false;
		}
	}
};

struct IsTownHall {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::ZERG_HATCHERY: return true;
		case UNIT_TYPEID::ZERG_LAIR: return true;
		case UNIT_TYPEID::ZERG_HIVE: return true;
		case UNIT_TYPEID::TERRAN_COMMANDCENTER: return true;
		case UNIT_TYPEID::TERRAN_ORBITALCOMMAND: return true;
		case UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING: return true;
		case UNIT_TYPEID::TERRAN_PLANETARYFORTRESS: return true;
		case UNIT_TYPEID::PROTOSS_NEXUS: return true;
		default: return false;
		}
	}
};

struct IsVespeneGeyser {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::NEUTRAL_VESPENEGEYSER: return true;
		case UNIT_TYPEID::NEUTRAL_SPACEPLATFORMGEYSER: return true;
		case UNIT_TYPEID::NEUTRAL_PROTOSSVESPENEGEYSER: return true;
		default: return false;
		}
	}
};

struct IsMineral {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::NEUTRAL_BATTLESTATIONMINERALFIELD: return true;
		case UNIT_TYPEID::NEUTRAL_BATTLESTATIONMINERALFIELD750: return true;
		case UNIT_TYPEID::NEUTRAL_LABMINERALFIELD: return true;
		case UNIT_TYPEID::NEUTRAL_LABMINERALFIELD750: return true;
		case UNIT_TYPEID::NEUTRAL_MINERALFIELD: return true;
		case UNIT_TYPEID::NEUTRAL_MINERALFIELD750: return true;
		case UNIT_TYPEID::NEUTRAL_PURIFIERMINERALFIELD: return true;
		case UNIT_TYPEID::NEUTRAL_PURIFIERMINERALFIELD750: return true;
		case UNIT_TYPEID::NEUTRAL_PURIFIERRICHMINERALFIELD: return true;
		case UNIT_TYPEID::NEUTRAL_PURIFIERRICHMINERALFIELD750: return true;
		case UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD: return true;
		case UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD750: return true;
		default: return false;
		}
	}
};

struct IsProductionStructure {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::TERRAN_BARRACKS: return true;
		case UNIT_TYPEID::TERRAN_FACTORY: return true;
		case UNIT_TYPEID::TERRAN_STARPORT: return true;
		case UNIT_TYPEID::PROTOSS_GATEWAY: return true;
		case UNIT_TYPEID::PROTOSS_STARGATE: return true;
		case UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY: return true;
		case UNIT_TYPEID::ZERG_HATCHERY: return true;
		case UNIT_TYPEID::ZERG_LAIR: return true;
		case UNIT_TYPEID::ZERG_HIVE: return true;
		default: return false;
		}
	}
};

struct IsNotTechnologyStructure {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::TERRAN_ENGINEERINGBAY: return false;
		case UNIT_TYPEID::TERRAN_GHOSTACADEMY: return false;
		case UNIT_TYPEID::TERRAN_FUSIONCORE: return false;
		case UNIT_TYPEID::TERRAN_ARMORY: return false;
		case UNIT_TYPEID::PROTOSS_FORGE: return false;
		case UNIT_TYPEID::PROTOSS_CYBERNETICSCORE: return false;
		case UNIT_TYPEID::PROTOSS_ROBOTICSBAY: return false;
		case UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL: return false;
		case UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE: return false;
		case UNIT_TYPEID::PROTOSS_DARKSHRINE: return false;
		case UNIT_TYPEID::PROTOSS_FLEETBEACON: return false;
		case UNIT_TYPEID::ZERG_SPAWNINGPOOL: return false;
		case UNIT_TYPEID::ZERG_BANELINGNEST: return false;
		case UNIT_TYPEID::ZERG_ROACHWARREN: return false;
		case UNIT_TYPEID::ZERG_HYDRALISKDEN: return false;
		case UNIT_TYPEID::ZERG_LURKERDENMP: return false;
		case UNIT_TYPEID::ZERG_SPIRE: return false;
		case UNIT_TYPEID::ZERG_GREATERSPIRE: return false;
		case UNIT_TYPEID::ZERG_ULTRALISKCAVERN: return false;
		default: return true;
		}
	}
};

struct IsTechnologyStructure {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::TERRAN_ENGINEERINGBAY: return true;
		case UNIT_TYPEID::TERRAN_GHOSTACADEMY: return true;
		case UNIT_TYPEID::TERRAN_FUSIONCORE: return true;
		case UNIT_TYPEID::TERRAN_ARMORY: return true;
		case UNIT_TYPEID::PROTOSS_FORGE: return true;
		case UNIT_TYPEID::PROTOSS_CYBERNETICSCORE: return true;
		case UNIT_TYPEID::PROTOSS_ROBOTICSBAY: return true;
		case UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL: return true;
		case UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE: return true;
		case UNIT_TYPEID::PROTOSS_DARKSHRINE: return true;
		case UNIT_TYPEID::PROTOSS_FLEETBEACON: return true;
		case UNIT_TYPEID::ZERG_SPAWNINGPOOL: return true;
		case UNIT_TYPEID::ZERG_BANELINGNEST: return true;
		case UNIT_TYPEID::ZERG_ROACHWARREN: return true;
		case UNIT_TYPEID::ZERG_HYDRALISKDEN: return true;
		case UNIT_TYPEID::ZERG_LURKERDENMP: return true;
		case UNIT_TYPEID::ZERG_SPIRE: return true;
		case UNIT_TYPEID::ZERG_GREATERSPIRE: return true;
		case UNIT_TYPEID::ZERG_ULTRALISKCAVERN: return true;
		default: return false;
		}
	}
};

struct IsStructure {
	IsStructure(const ObservationInterface* obs) : observation_(obs) {};

	bool operator()(const Unit& unit) {
		auto& attributes = observation_->GetUnitTypeData().at(unit.unit_type).attributes;
		bool is_structure = false;
		for (const auto& attribute : attributes) {
			if (attribute == Attribute::Structure) {
				is_structure = true;
			}
		}
		return is_structure;
	}

	const ObservationInterface* observation_;
};

#pragma endregion

class UnitData
{
public:
	UnitData();
	~UnitData();
	static bool isOurs(const Unit *unit);
	static bool isWorker(const Unit *unit);
	static bool isStructure(const Unit *unit);
	static bool isFightingUnit(const Unit *unit);
	static bool isTownHall(const Unit *unit);
	static bool isSupplyProvider(const Unit *unit);
	static bool isMinerals(const Unit *unit);
	static bool isVespeneGeyser(const Unit *unit);
	static bool isBuildAbility(AbilityID ability);
	static bool isResearch(AbilityID ability);
	static bool isTrainableUnitType(AbilityID ability);
	static bool isTrainedFromGateway(AbilityID ability);
	static bool isGasStructure(const Unit *unit);
	static bool isWarpGateUnit(const Unit *unit);
	static bool isWarpGateUnit(UnitTypeID unitType);
	static bool isChangeling(UnitTypeID unitType);
	static bool canCloak(const Unit *unit);
	static bool canWarpIn(AbilityID ability);
	static bool isComparableUpgrade(AbilityID abilityA, AbilityID abilityB);
	static bool isTechStructure(AbilityID ability);
	static bool isCaster(UnitTypeID unitType);
	static bool isTargetable(UnitTypeID unitType);
	static bool isVisible(const Unit *enemy);
	static bool isSamePoint2D(Point2D a, Point2D b);
	static bool canTarget(const Unit *attacker, const Unit *potentialTarget);
	static bool canAttackAir(UnitTypeID unitType);
	static bool canAttackGround(UnitTypeID unitType);
	static float getWarpGateCoolDown(UnitTypeID unitType);
	static bool isNeutralRock(const Unit *unit);
	static UnitTypeID getUnitTypeID(AbilityID ability);
	static UpgradeID getUpgradeID(AbilityID ability);
	static AbilityID getAbilityID(UpgradeID upgrade);
	static UnitTypeID requiredStructure(AbilityID ability);
	static AbilityID getTrainWarpAbilityID(UnitTypeID unitType);

	//own methods 
	static bool isUsefulUnit(const Unit *unit);
	static bool isUsefulStructure(const Unit *unit);
	static UNIT_TYPEID getClosestUnitInCost(const ObservationInterface* obs, Unit *unit);
	static bool isEnemyArmy(const Unit *unit, const ObservationInterface *obs);
	static bool isEnemyHarvester(const Unit *unit);
	static double getTimeToProduceUpgrade(sc2::UpgradeID upgrade_id);
	static double getTimeToProduceUnit(UNIT_TYPEID unit_typeId);


	//return time in minutes
	static double calculateTime(double time);

private:
	static bool compareUpgrades(AbilityID abilityA, AbilityID abilityB);
	

};

#endif // !_UNITDATA_HPP_

