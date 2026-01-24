// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectiles/CFR_Projectile.h"

ACFR_Projectile::ACFR_Projectile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACFR_Projectile::SetGenericTeamId(const FGenericTeamId& TeamID)
{
	ProjectileTeam = TeamID;
}

FGenericTeamId ACFR_Projectile::GetGenericTeamId() const
{
	return ProjectileTeam;
}
