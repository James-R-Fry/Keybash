// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFixedOverworldEnemy.h"
#include "Components/CapsuleComponent.h"
#include "BattleProto_1Character.h"

// Sets default values
AMyFixedOverworldEnemy::AMyFixedOverworldEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionVolume"));

	RootComponent = CollisionVolume;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AMyFixedOverworldEnemy::BeginPlay()
{
	Super::BeginPlay();


	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AMyFixedOverworldEnemy::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AMyFixedOverworldEnemy::OnOverlapEnd);
	
}

// Called every frame
void AMyFixedOverworldEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFixedOverworldEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyFixedOverworldEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	AActor* tempPlayer = OtherActor;
	if (tempPlayer) {
		ABattleProto_1Character* MyPlayer = Cast<ABattleProto_1Character>(tempPlayer);

		if (MyPlayer) {
			MyPlayer->ToggleBattle();
			MyPlayer->bStartTemp = false;
			UE_LOG(LogTemp, Warning, TEXT("Collided"));

			this->Destroy();
		}

	}
}

void AMyFixedOverworldEnemy::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

