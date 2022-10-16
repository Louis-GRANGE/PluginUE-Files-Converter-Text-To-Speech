// Copyright Grange Louis. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

//File picker includes
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"

//FileManager
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "HAL/FileManagerGeneric.h"
#include "GenericPlatform/GenericPlatformFile.h"

#include<iostream>
#include<ctime>
#include<windows.h>

// Must be the last
#include "BPFL_FileManagement.generated.h"

/**
 * 
 */
UCLASS()
class AUDIOMANAGEREDITOR_API UBPFL_FileManagement : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "FileManager")
		static bool FindFileRecursivly(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);

	UFUNCTION(BlueprintCallable, Category = "FileManager")
		static bool ReadFileFromPath(FString FilePath, FString& OutFileData);

	UFUNCTION(BlueprintCallable, Category = "FileManager")
		static bool ReadByteFileFromPath(FString FilePath, TArray<uint8>& OutFileData);

	UFUNCTION(BlueprintCallable, Category = "FileManager")
		static bool WriteByteFileFromPath(FString FilePath, TArray<uint8> Data);

	UFUNCTION(BlueprintCallable, Category = "FileManager")
		static bool WriteInFile(FString FilePath, FString FileData, bool OverrideFile = true);

	UFUNCTION(BlueprintCallable, Category = "FileManager")
		static bool GetFileSize(FString FilePath, int& OutFileSize);

	UFUNCTION(BlueprintCallable)
		static bool GetAudioDuration(FString FilePath, FString Extension, int& OutTime);

	UFUNCTION(BlueprintCallable)
		static bool PlayAudioFile(FString FilePath, FString Extension);

	UFUNCTION(BlueprintCallable)
		static bool PauseAudioFile(FString FilePath, FString Extension);

	UFUNCTION(BlueprintCallable)
		static bool StopAudioFile(FString FilePath, FString Extension);
};
