#include "SolidDemoDependencyPluginComponent.h"
#include <iostream>

using namespace sdr;

namespace
{
	void TestInit()
	{
		std::cout << "calling init..." << std::endl;
	}

	void TestInitialisationFinished()
	{
		std::cout << "calling init finish..." << std::endl;
	}

	void TestFinalize()
	{
		std::cout << "calling finalize..." << std::endl;
	}
}

ALICE_IMPL_CONCRETE_OBJECT_TYPE(DemoDependencyPluginComponent, "DemoDependencyPlugin")
sdr::DemoDependencyPluginComponent::~DemoDependencyPluginComponent()
{

}

bool DemoDependencyPluginComponent::InitialiseEvent()
{
	TestInit();
	return true;
}

void DemoDependencyPluginComponent::InitialisationFinishedEvent()
{
	TestInitialisationFinished();
}

void DemoDependencyPluginComponent::FinaliseEvent()
{
	TestFinalize();
}