// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/EstrategiaAtaqueAZombies.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaAtaqueAZombies() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_UEstrategiaAtaqueAZombies_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_UEstrategiaAtaqueAZombies();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
// End Cross Module References
	void UEstrategiaAtaqueAZombies::StaticRegisterNativesUEstrategiaAtaqueAZombies()
	{
	}
	UClass* Z_Construct_UClass_UEstrategiaAtaqueAZombies_NoRegister()
	{
		return UEstrategiaAtaqueAZombies::StaticClass();
	}
	struct Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "EstrategiaAtaqueAZombies.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IEstrategiaAtaqueAZombies>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::ClassParams = {
		&UEstrategiaAtaqueAZombies::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEstrategiaAtaqueAZombies()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEstrategiaAtaqueAZombies_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEstrategiaAtaqueAZombies, 3136207995);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<UEstrategiaAtaqueAZombies>()
	{
		return UEstrategiaAtaqueAZombies::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEstrategiaAtaqueAZombies(Z_Construct_UClass_UEstrategiaAtaqueAZombies, &UEstrategiaAtaqueAZombies::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("UEstrategiaAtaqueAZombies"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEstrategiaAtaqueAZombies);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
