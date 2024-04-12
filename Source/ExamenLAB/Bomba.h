// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomba.generated.h"

class UStaticMeshComponent;

UCLASS()
class EXAMENLAB_API ABomba : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaBomba;// Malla de la bomba que se visualizar� en el juego
private:
	FVector posicionBomba;
	FString nombreb;
	float radioBomba;
public:
	//getter
	FORCEINLINE FVector GetPosicionBomba() const { return posicionBomba; }
	FORCEINLINE FString GetNombreBomba() const { return nombreb; }
	FORCEINLINE float GetRadioBomba() const { return radioBomba; }

	//setter
	FORCEINLINE void SetPosicionBomba(FVector posicion) { posicionBomba = posicion; }
	FORCEINLINE void SetNombreBomba(FString nombre) { nombreb = nombre; }
	FORCEINLINE void SetRadioBomba(float radio) { radioBomba = radio; }

public:	
	// Sets default values for this actor's properties
	ABomba();// constructor por defecto

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void MoverBomba(float DeltaTime); // funci�n para mover la bomba
	UPROPERTY(EditAnywhere, Category = "Movimiento") // para que se pueda modificar desde el editor
	float velocidadBombaX; // velocidad de la bomba en el eje X
};
