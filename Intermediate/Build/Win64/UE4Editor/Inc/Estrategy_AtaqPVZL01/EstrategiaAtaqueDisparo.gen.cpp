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
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
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
	IMPLEMENT_CLASS(AEstrategiaAtaqueDisparo, 2370021966);
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
