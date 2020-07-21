#include "Nodes/Operators/FlowNodeLogicalAND.h"

UFlowNodeLogicalAND::UFlowNodeLogicalAND(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Operators");
	NodeStyle = EFlowNodeStyle::Logic;
#endif

	SetNumericalInputs(0, 1);
}

void UFlowNodeLogicalAND::ExecuteInput(const FName& PinName)
{
	ExecutedInputNames.Add(PinName);

	if (ExecutedInputNames.Num() == InputNames.Num())
	{
		TriggerFirstOutput(true);
	}
}

void UFlowNodeLogicalAND::Cleanup()
{
	ExecutedInputNames.Empty();
}
