// Copyright Grange Louis. All Rights Reserved.

#include "BPFL_FileManagement.h"

bool UBPFL_FileManagement::FindFileRecursivly(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
{
	if (RootFolderFullPath.Len() < 1) return false;

	FPaths::NormalizeDirectoryName(RootFolderFullPath);

	IFileManager& FileManager = IFileManager::Get();

	if (!Ext.Contains(TEXT("*")))
	{
		if (Ext == "")
		{
			Ext = "*.*";
		}
		else
		{
			Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
		}
	}

	FileManager.FindFilesRecursive(Files, *RootFolderFullPath, *Ext, true, false);
	return true;
}

bool UBPFL_FileManagement::ReadFileFromPath(FString FilePath, FString& OutFileData)
{
	// We will use this FileManager to deal with the file.
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	//FString FileContent;
	// Always first check if the file that you want to manipulate exist.
	if (FileManager.FileExists(*FilePath))
	{
		// We use the LoadFileToString to load the file into
		if (FFileHelper::LoadFileToString(OutFileData, *FilePath, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Successfuly Reading"));
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
			return false;
		}
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *FilePath);
		return false;
	}
}

bool UBPFL_FileManagement::ReadByteFileFromPath(FString FilePath, TArray<uint8>& OutFileData)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	if (FileManager.FileExists(*FilePath))
	{
		FFileHelper::LoadFileToArray(OutFileData, *FilePath);
		return true;
	}
	return false;
}

bool UBPFL_FileManagement::WriteByteFileFromPath(FString FilePath, TArray<uint8> Data)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	//if (FileManager.FileExists(*FilePath))
	//{
	if (Data.Num() <= 0) return false;
	if (FFileHelper::SaveArrayToFile(Data, *FilePath))
	{
		return true;
	}
	return false;
	//}
	//return false;
}


bool UBPFL_FileManagement::WriteInFile(FString FilePath, FString FileData, bool OverrideFile)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	// Always first check if the file that you want to manipulate exist.

	if (OverrideFile)
	{
		// We use the LoadFileToString to load the file into
		if (FFileHelper::SaveStringToFile(FileData, *FilePath))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Successfuly Written"));
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."));
		}
	}
	else
	{
		if (FileManager.FileExists(*FilePath))
		{
			FString data;
			UBPFL_FileManagement::ReadFileFromPath(FilePath, data);
			data.Append(FileData);

			// We use the LoadFileToString to load the file into
			if (FFileHelper::SaveStringToFile(data, *FilePath))
			{
				UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Successfuly Written"));
				return true;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to read file. (No Exist)"));
		}
	}
	return false;
}


bool UBPFL_FileManagement::GetFileSize(FString FilePath, int& OutFileSize)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	// Getting the file size and storring it
	int FileSize = FileManager.FileSize(*FilePath);
	//The file size is -1 if it is not found
	if (FileSize > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("FilePaths: File Size: %d"), FileSize);
		OutFileSize = FileSize;
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FilePaths: File not found!"));
		return false;
	}
}
bool UBPFL_FileManagement::GetAudioDuration(FString FilePath, FString Extension, int& OutTime)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	if (FileManager.FileExists(*FilePath))
	{
		//opening the mp3 file
		std::wstring stemp = *FString("open \"").Append(FilePath).Append("\" type mpegvideo alias ").Append(Extension);
		LPCWSTR sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);

		//start time
		time_t start = time(0);
		//play the mp3 file
		stemp = *FString("play ").Append(Extension);// .Append(" wait");
		sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);
		//end time
		time_t end = time(0);

		//total duration
		OutTime = end - start;
		//close the mp3 file
		stemp = *FString("close ").Append(Extension);
		sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);
		return true;
	}
	return false;
}

bool UBPFL_FileManagement::PlayAudioFile(FString FilePath, FString Extension)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	if (FileManager.FileExists(*FilePath))
	{
		//opening the mp3 file
		std::wstring stemp = *FString("open \"").Append(FilePath).Append("\" type mpegvideo alias ").Append(Extension);
		LPCWSTR sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);

		//start time
		time_t start = time(0);
		//play the mp3 file
		stemp = *FString("play ").Append(Extension).Append(" wait");
		sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);

		//close the mp3 file
		stemp = *FString("close ").Append(Extension);
		sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);
		return true;
	}
	return false;
}

bool UBPFL_FileManagement::PauseAudioFile(FString FilePath, FString Extension)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	if (FileManager.FileExists(*FilePath))
	{
		//opening the mp3 file
		std::wstring stemp = *FString("open \"").Append(FilePath).Append("\" type mpegvideo alias ").Append(Extension);
		LPCWSTR sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);

		//start time
		time_t start = time(0);
		//pause the mp3 file
		stemp = *FString("pause ").Append(Extension);

		return true;
	}
	return false;
}

bool UBPFL_FileManagement::StopAudioFile(FString FilePath, FString Extension)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	if (FileManager.FileExists(*FilePath))
	{
		//opening the mp3 file
		std::wstring stemp = *FString("open \"").Append(FilePath).Append("\" type mpegvideo alias ").Append(Extension);
		LPCWSTR sw = stemp.c_str();
		mciSendString(sw, NULL, 0, NULL);

		//start time
		time_t start = time(0);
		//pause the mp3 file
		stemp = *FString("close ").Append(Extension);

		return true;
	}
	return false;
}

LPWSTR ConvertString(const std::string& instr)
{
	// Assumes std::string is encoded in the current Windows ANSI codepage
	int bufferlen = ::MultiByteToWideChar(CP_ACP, 0, instr.c_str(), instr.size(), NULL, 0);

	if (bufferlen == 0)
	{
		// Something went wrong. Perhaps, check GetLastError() and log.
		return 0;
	}

	// Allocate new LPWSTR - must deallocate it later
	LPWSTR widestr = new WCHAR[bufferlen + 1];

	::MultiByteToWideChar(CP_ACP, 0, instr.c_str(), instr.size(), widestr, bufferlen);

	// Ensure wide string is null terminated
	widestr[bufferlen] = 0;

	// Do something with widestr
	return widestr;
	//delete[] widestr;
}