// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/EstrategiaAplastamientoAZ.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaAplastamientoAZ() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_AEstrategiaAplastamientoAZ_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_AEstrategiaAplastamientoAZ();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_UEstrategiaAtaqueAZombies_NoRegister();
// End Cross Module References
	void AEstrategiaAplastamientoAZ::StaticRegisterNativesAEstrategiaAplastamientoAZ()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaAplastamientoAZ_NoRegister()
	{
		return AEstrategiaAplastamientoAZ::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaAplastamientoAZ.h" },
		{ "ModuleRelativePath", "EstrategiaAplastamientoAZ.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UEstrategiaAtaqueAZombies_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaAplastamientoAZ, IEstrategiaAtaqueAZombies), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaAplastamientoAZ>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::ClassParams = {
		&AEstrategiaAplastamientoAZ::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaAplastamientoAZ()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaAplastamientoAZ_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaAplastamientoAZ, 2328532923);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<AEstrategiaAplastamientoAZ>()
	{
		return AEstrategiaAplastamientoAZ::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaAplastamientoAZ(Z_Construct_UClass_AEstrategiaAplastamientoAZ, &AEstrategiaAplastamientoAZ::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("AEstrategiaAplastamientoAZ"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaAplastamientoAZ);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
