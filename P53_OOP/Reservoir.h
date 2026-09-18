#pragma once


enum class ReservoirType
{
	Ocean, Sea, Lake, River, Pond, Luzha
};

class Reservoir
{
	ReservoirType type;


public:
	Reservoir(ReservoirType t) : type{ t } {}
	ReservoirType getType() const { return type; }
	void setType(ReservoirType t) { type = t; }
};