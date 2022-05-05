// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleEnemy.h"

// Sets default values
ABattleEnemy::ABattleEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleEnemy::SetMaxHealth(float temp)
{
	MaxHealth = temp;
}

void ABattleEnemy::SetHealth(float temp)
{
	Health = temp;
}

float ABattleEnemy::InitialAllignment()
{
	float min = 0.25;
	float max = 0.75;
	float diff = max - min;

	return (((float)rand() / RAND_MAX) * diff) + min;
}
