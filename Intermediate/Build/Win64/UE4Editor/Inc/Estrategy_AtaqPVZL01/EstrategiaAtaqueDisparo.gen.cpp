// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/EstrategiaAtaqueDisparo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaAtaqueDisparo() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_AEstrategiaAtaqueDisparo_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_AEstrategiaAtaqueDisparo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_UEstrategiaAtaqueAZombies_NoRegister();
// End Cross Module References
	void AEstrategiaAtaqueDisparo::StaticRegisterNativesAEstrategiaAtaqueDisparo()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaAtaqueDisparo_NoRegister()
	{
		return AEstrategiaAtaqueDisparo::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GunOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GunOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FireRate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaAtaqueDisparo.h" },
		{ "ModuleRelativePath", "EstrategiaAtaqueDisparo.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_GunOffset_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** Offset from the ships location to spawn projectiles */// Desplazamiento desde la ubicaci?n de la nave para generar proyectiles \n" },
		{ "ModuleRelativePath", "EstrategiaAtaqueDisparo.h" },
		{ "ToolTip", "Offset from the ships location to spawn projectiles // Desplazamiento desde la ubicaci?n de la nave para generar proyectiles" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_GunOffset = { "GunOffset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEstrategiaAtaqueDisparo, GunOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_GunOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_GunOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_FireRate_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/* How fast the weapon will fire */// La velocidad a la que el arma disparar? \n" },
		{ "ModuleRelativePath", "EstrategiaAtaqueDisparo.h" },
		{ "ToolTip", "How fast the weapon will fire // La velocidad a la que el arma disparar?" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEstrategiaAtaqueDisparo, FireRate), METADATA_PARAMS(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_FireRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_FireRate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_GunOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::NewProp_FireRate,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UEstrategiaAtaqueAZombies_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaAtaqueDisparo, IEstrategiaAtaqueAZombies), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaAtaqueDisparo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::ClassParams = {
		&AEstrategiaAtaqueDisparo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaAtaqueDisparo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaAtaqueDisparo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaAtaqueDisparo, 3773438801);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<AEstrategiaAtaqueDisparo>()
	{
		return AEstrategiaAtaqueDisparo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaAtaqueDisparo(Z_Construct_UClass_AEstrategiaAtaqueDisparo, &AEstrategiaAtaqueDisparo::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("AEstrategiaAtaqueDisparo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaAtaqueDisparo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif