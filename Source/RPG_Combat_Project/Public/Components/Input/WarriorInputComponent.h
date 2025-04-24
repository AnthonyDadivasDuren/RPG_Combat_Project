// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPG_COMBAT_PROJECT_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename Callbackfunc>
    void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
    	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, Callbackfunc Func);
	
};

template <class UserObject, typename Callbackfunc>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, Callbackfunc Func)
{
	
	checkf(InInputConfig, TEXT("Input config data asset is null,can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionbyTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
