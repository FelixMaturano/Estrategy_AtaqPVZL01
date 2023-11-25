// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
class IPlantaObservador;
#ifdef ESTRATEGY_ATAQPVZL01_Zombie_generated_h
#error "Zombie.generated.h already included, missing '#pragma once' in Zombie.h"
#endif
#define ESTRATEGY_ATAQPVZL01_Zombie_generated_h

#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_SPARSE_DATA
#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execOnOverlapBeginFunction); \
	DECLARE_FUNCTION(execDesuscribirPlanta); \
	DECLARE_FUNCTION(execSuscribirPlanta); \
	DECLARE_FUNCTION(execMoverZombie);


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execOnOverlapBeginFunction); \
	DECLARE_FUNCTION(execDesuscribirPlanta); \
	DECLARE_FUNCTION(execSuscribirPlanta); \
	DECLARE_FUNCTION(execMoverZombie);


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombie(); \
	friend struct Z_Construct_UClass_AZombie_Statics; \
public: \
	DECLARE_CLASS(AZombie, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Estrategy_AtaqPVZL01"), NO_API) \
	DECLARE_SERIALIZER(AZombie)


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAZombie(); \
	friend struct Z_Construct_UClass_AZombie_Statics; \
public: \
	DECLARE_CLASS(AZombie, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Estrategy_AtaqPVZL01"), NO_API) \
	DECLARE_SERIALIZER(AZombie)


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZombie(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombie) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombie); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombie); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombie(AZombie&&); \
	NO_API AZombie(const AZombie&); \
public:


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombie(AZombie&&); \
	NO_API AZombie(const AZombie&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombie); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombie); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombie)


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Observadores() { return STRUCT_OFFSET(AZombie, Observadores); } \
	FORCEINLINE static uint32 __PPO__CoordenadaCruceZombie() { return STRUCT_OFFSET(AZombie, CoordenadaCruceZombie); }


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_10_PROLOG
#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_PRIVATE_PROPERTY_OFFSET \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_SPARSE_DATA \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_RPC_WRAPPERS \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_INCLASS \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_PRIVATE_PROPERTY_OFFSET \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_SPARSE_DATA \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_INCLASS_NO_PURE_DECLS \
	Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<class AZombie>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Estrategy_AtaqPVZL01_Source_Estrategy_AtaqPVZL01_Zombie_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
