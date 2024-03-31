// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/ProyectilEnemiga.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProyectilEnemiga() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AProyectilEnemiga_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AProyectilEnemiga();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void AProyectilEnemiga::StaticRegisterNativesAProyectilEnemiga()
	{
	}
	UClass* Z_Construct_UClass_AProyectilEnemiga_NoRegister()
	{
		return AProyectilEnemiga::StaticClass();
	}
	struct Z_Construct_UClass_AProyectilEnemiga_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProyectilEnemiga_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProyectilEnemiga_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProyectilEnemiga.h" },
		{ "ModuleRelativePath", "ProyectilEnemiga.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProyectilEnemiga_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProyectilEnemiga>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProyectilEnemiga_Statics::ClassParams = {
		&AProyectilEnemiga::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AProyectilEnemiga_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProyectilEnemiga_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProyectilEnemiga()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProyectilEnemiga_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProyectilEnemiga, 4134864195);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<AProyectilEnemiga>()
	{
		return AProyectilEnemiga::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProyectilEnemiga(Z_Construct_UClass_AProyectilEnemiga, &AProyectilEnemiga::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("AProyectilEnemiga"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProyectilEnemiga);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
