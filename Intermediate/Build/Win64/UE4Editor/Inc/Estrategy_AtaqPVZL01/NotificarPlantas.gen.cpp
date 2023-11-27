// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Estrategy_AtaqPVZL01/NotificarPlantas.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNotificarPlantas() {}
// Cross Module References
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_ANotificarPlantas_NoRegister();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_ANotificarPlantas();
	ESTRATEGY_ATAQPVZL01_API UClass* Z_Construct_UClass_APublicador();
	UPackage* Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01();
// End Cross Module References
	void ANotificarPlantas::StaticRegisterNativesANotificarPlantas()
	{
	}
	UClass* Z_Construct_UClass_ANotificarPlantas_NoRegister()
	{
		return ANotificarPlantas::StaticClass();
	}
	struct Z_Construct_UClass_ANotificarPlantas_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANotificarPlantas_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APublicador,
		(UObject* (*)())Z_Construct_UPackage__Script_Estrategy_AtaqPVZL01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANotificarPlantas_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NotificarPlantas.h" },
		{ "ModuleRelativePath", "NotificarPlantas.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANotificarPlantas_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANotificarPlantas>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANotificarPlantas_Statics::ClassParams = {
		&ANotificarPlantas::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANotificarPlantas_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANotificarPlantas_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANotificarPlantas()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANotificarPlantas_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANotificarPlantas, 3104098224);
	template<> ESTRATEGY_ATAQPVZL01_API UClass* StaticClass<ANotificarPlantas>()
	{
		return ANotificarPlantas::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANotificarPlantas(Z_Construct_UClass_ANotificarPlantas, &ANotificarPlantas::StaticClass, TEXT("/Script/Estrategy_AtaqPVZL01"), TEXT("ANotificarPlantas"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANotificarPlantas);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
