// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/Estrategy_AtaqPVZL01GameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategy_AtaqPVZL01GameModeBase() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
// End Cross Module References
	void AEstrategy_AtaqPVZL01GameModeBase::StaticRegisterNativesAEstrategy_AtaqPVZL01GameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_NoRegister()
	{
		return AEstrategy_AtaqPVZL01GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Estrategy_AtaqPVZL01GameModeBase.h" },
		{ "ModuleRelativePath", "Estrategy_AtaqPVZL01GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategy_AtaqPVZL01GameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::ClassParams = {
		&AEstrategy_AtaqPVZL01GameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategy_AtaqPVZL01GameModeBase, 1864784701);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<AEstrategy_AtaqPVZL01GameModeBase>()
	{
		return AEstrategy_AtaqPVZL01GameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategy_AtaqPVZL01GameModeBase(Z_Construct_UClass_AEstrategy_AtaqPVZL01GameModeBase, &AEstrategy_AtaqPVZL01GameModeBase::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("AEstrategy_AtaqPVZL01GameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategy_AtaqPVZL01GameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
