// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/Publicador.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePublicador() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_APublicador_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_APublicador();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void APublicador::StaticRegisterNativesAPublicador()
	{
	}
	UClass* Z_Construct_UClass_APublicador_NoRegister()
	{
		return APublicador::StaticClass();
	}
	struct Z_Construct_UClass_APublicador_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Suscriptores_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Suscriptores_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Suscriptores;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APublicador_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APublicador_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Publicador.h" },
		{ "ModuleRelativePath", "Publicador.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores_Inner = { "Suscriptores", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores_MetaData[] = {
		{ "Comment", "//The Subscribers of this Publisher\n" },
		{ "ModuleRelativePath", "Publicador.h" },
		{ "ToolTip", "The Subscribers of this Publisher" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores = { "Suscriptores", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APublicador, Suscriptores), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APublicador_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APublicador_Statics::NewProp_Suscriptores,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APublicador_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APublicador>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APublicador_Statics::ClassParams = {
		&APublicador::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APublicador_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APublicador_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APublicador_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APublicador_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APublicador()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APublicador_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APublicador, 940598060);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<APublicador>()
	{
		return APublicador::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APublicador(Z_Construct_UClass_APublicador, &APublicador::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("APublicador"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APublicador);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
