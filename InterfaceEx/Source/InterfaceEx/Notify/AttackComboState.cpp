// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify/AttackComboState.h"
#include "InterfaceEx/Attacker.h"

void UAttackComboState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	IAttacker* attacker = Cast<IAttacker>(MeshComp->GetOwner());
	if (attacker != nullptr)
		attacker->ComboStart();
}

void UAttackComboState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);
}

void UAttackComboState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	IAttacker* attacker = Cast<IAttacker>(MeshComp->GetOwner());
	if (attacker != nullptr)
		attacker->ComboEnd();
}
