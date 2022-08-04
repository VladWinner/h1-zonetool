#pragma once
#include "../zonetool.hpp"

namespace zonetool
{
	class IPhysConstraint : public IAsset
	{
	private:
		std::string name_;
		PhysConstraint* asset_ = nullptr;

	public:
		void init(const std::string& name, ZoneMemory* mem) override;
		void prepare(ZoneBuffer* buf, ZoneMemory* mem) override;
		void load_depending(IZone* zone) override;

		void* pointer() override { return asset_; }
		bool referenced() override { return name_.starts_with(","); }
		std::string name() override;
		std::int32_t type() override;
		void write(IZone* zone, ZoneBuffer* buffer) override;

		static void dump(PhysConstraint* asset);
	};
}