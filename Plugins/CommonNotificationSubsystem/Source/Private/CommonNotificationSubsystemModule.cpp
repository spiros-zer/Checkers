// Copyright 2024 Spyridon Zervos

#include "Modules/ModuleManager.h"

/**
 * Implements the FCommonNotificationSubsystemModule module.
 */
class FCommonNotificationSubsystemModule : public IModuleInterface
{

public:

	FCommonNotificationSubsystemModule();
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

};


FCommonNotificationSubsystemModule::FCommonNotificationSubsystemModule()
{
}

void FCommonNotificationSubsystemModule::StartupModule()
{
}

void FCommonNotificationSubsystemModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FCommonNotificationSubsystemModule, CommonNotificationSubsystem);
