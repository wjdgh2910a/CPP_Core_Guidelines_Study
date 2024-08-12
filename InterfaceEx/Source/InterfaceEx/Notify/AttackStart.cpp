// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackStart.h"
#include "InterfaceEx/Attacker.h"

void UAttackStart::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	IAttacker* attacker = Cast<IAttacker>(MeshComp->GetOwner());
	if(attacker != nullptr)
		attacker->AttackStart();
}
