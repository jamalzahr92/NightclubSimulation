// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VisualComputingv2C/AudioAnalyzerCPP.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAudioAnalyzerCPP() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_VisualComputingv2C();
VISUALCOMPUTINGV2C_API UClass* Z_Construct_UClass_AAudioAnalyzerCPP();
VISUALCOMPUTINGV2C_API UClass* Z_Construct_UClass_AAudioAnalyzerCPP_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AAudioAnalyzerCPP ********************************************************
void AAudioAnalyzerCPP::StaticRegisterNativesAAudioAnalyzerCPP()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AAudioAnalyzerCPP;
UClass* AAudioAnalyzerCPP::GetPrivateStaticClass()
{
	using TClass = AAudioAnalyzerCPP;
	if (!Z_Registration_Info_UClass_AAudioAnalyzerCPP.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AudioAnalyzerCPP"),
			Z_Registration_Info_UClass_AAudioAnalyzerCPP.InnerSingleton,
			StaticRegisterNativesAAudioAnalyzerCPP,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AAudioAnalyzerCPP.InnerSingleton;
}
UClass* Z_Construct_UClass_AAudioAnalyzerCPP_NoRegister()
{
	return AAudioAnalyzerCPP::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AAudioAnalyzerCPP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AudioAnalyzerCPP.h" },
		{ "ModuleRelativePath", "AudioAnalyzerCPP.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BassValue_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "AudioAnalyzerCPP.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BassValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAudioAnalyzerCPP>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioAnalyzerCPP_Statics::NewProp_BassValue = { "BassValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAudioAnalyzerCPP, BassValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BassValue_MetaData), NewProp_BassValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAudioAnalyzerCPP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioAnalyzerCPP_Statics::NewProp_BassValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAudioAnalyzerCPP_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AAudioAnalyzerCPP_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VisualComputingv2C,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAudioAnalyzerCPP_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAudioAnalyzerCPP_Statics::ClassParams = {
	&AAudioAnalyzerCPP::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AAudioAnalyzerCPP_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AAudioAnalyzerCPP_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAudioAnalyzerCPP_Statics::Class_MetaDataParams), Z_Construct_UClass_AAudioAnalyzerCPP_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAudioAnalyzerCPP()
{
	if (!Z_Registration_Info_UClass_AAudioAnalyzerCPP.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAudioAnalyzerCPP.OuterSingleton, Z_Construct_UClass_AAudioAnalyzerCPP_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAudioAnalyzerCPP.OuterSingleton;
}
AAudioAnalyzerCPP::AAudioAnalyzerCPP(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAudioAnalyzerCPP);
AAudioAnalyzerCPP::~AAudioAnalyzerCPP() {}
// ********** End Class AAudioAnalyzerCPP **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UEProjects_VisualComputingv2C_Source_VisualComputingv2C_AudioAnalyzerCPP_h__Script_VisualComputingv2C_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAudioAnalyzerCPP, AAudioAnalyzerCPP::StaticClass, TEXT("AAudioAnalyzerCPP"), &Z_Registration_Info_UClass_AAudioAnalyzerCPP, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAudioAnalyzerCPP), 1151795883U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProjects_VisualComputingv2C_Source_VisualComputingv2C_AudioAnalyzerCPP_h__Script_VisualComputingv2C_1255869593(TEXT("/Script/VisualComputingv2C"),
	Z_CompiledInDeferFile_FID_UEProjects_VisualComputingv2C_Source_VisualComputingv2C_AudioAnalyzerCPP_h__Script_VisualComputingv2C_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProjects_VisualComputingv2C_Source_VisualComputingv2C_AudioAnalyzerCPP_h__Script_VisualComputingv2C_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
