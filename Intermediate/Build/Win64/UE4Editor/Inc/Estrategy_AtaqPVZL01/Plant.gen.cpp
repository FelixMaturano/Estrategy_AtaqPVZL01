// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/Plant.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlant() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_APlant_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_APlant();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void APlant::StaticRegisterNativesAPlant()
	{
	}
	UClass* Z_Construct_UClass_APlant_NoRegister()
	{
		return APlant::StaticClass();
	}
	struct Z_Construct_UClass_APlant_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshPlanta_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshPlanta;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlant_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Plant.h" },
		{ "ModuleRelativePath", "Plant.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlant_Statics::NewProp_MeshPlanta_MetaData[] = {
		{ "Category", "Plant" },
		{ "Comment", "// Sets default values for this actor's properties\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Plant.h" },
		{ "ToolTip", "Sets default values for this actor's properties" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlant_Statics::NewProp_MeshPlanta = { "MeshPlanta", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlant, MeshPlanta), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APlant_Statics::NewProp_MeshPlanta_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlant_Statics::NewProp_MeshPlanta_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlant_Statics::NewProp_MeshPlanta,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlant>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlant_Statics::ClassParams = {
		&APlant::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APlant_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APlant_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlant()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlant_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlant, 3295436298);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<APlant>()
	{
		return APlant::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlant(Z_Construct_UClass_APlant, &APlant::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("APlant"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlant);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
