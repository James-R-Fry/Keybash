// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleEnemy.generated.h"

UCLASS()
class BATTLEPROTO_1_API ABattleEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Battle")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Battle")
	float Health;

	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SetMaxHealth(float temp);

	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SetHealth(float temp);
};
