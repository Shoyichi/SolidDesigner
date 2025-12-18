#pragma once

#include "AliceObjectMacros.h"
#include "AliceIPluginComponent.h"
#include "AlicePluginExports.h"

namespace sdr
{
	class DemoDependencyPluginComponent final : public alice::IPluginComponent
	{
		ALICE_DECLARE_OBJECT_TYPE(DemoDependencyPluginComponent, IPluginComponent)
	public:
		~DemoDependencyPluginComponent() override;

		bool InitialiseEvent() override;
		void InitialisationFinishedEvent() override;
		void FinaliseEvent() override;
	};
}

ALICE_PLUGIN_EXPORT_INTERFACES(sdr::DemoDependencyPluginComponent, /*AbiMajorValue*/ 1, "Alice", "DemoDependencyPlugin", "Demo Dependency Plugin", "1.0.0");