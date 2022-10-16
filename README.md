# Files Converter & Text To Speech Plugin

This plugin is use to Convert lot of types of file with free API : **[API2Convert](https://www.api2convert.com/)** (like MP3 to WAV) & also use to Speech to Text with free API : **[Voice RSS](https://www.voicerss.org/)** directly in your project in the WidgetEditor of Unreal Engine.


To add the plugin in your project, you have to: 
 1. [Download the plugin through the Marketplace](https://www.unrealengine.com/marketplace/product/files-converter-text-to-speech).
 2. Manual installation. Select and download [the release](https://github.com/Louis-GRANGE/PluginUE-Files-Converter-Text-To-Speech/releases) for the required engine version, extract the archive into your plugins project folder to get the following path:  **"[ProjectName]/Plugins/"**.

## How to launch
Go to your content browser in you project and click on **"AudioManagerEditor"**
![](https://i.gyazo.com/42171487b0d5d81879aa3805c37c9610.png)

Right click on **"EWBP_MainPanel"** and Click on **"Run Editor Utility Widget"**

![](https://i.gyazo.com/0c9bee52ea0a975620e370b199011ec9.png)

Now you get this window and you can switch to **"Convert"** and **"Text To Speech"** panels :
![](https://i.gyazo.com/0bfa16df1086d3efad6663637f1a6d75.png)

## Setup panels <img src="https://i.gyazo.com/53480d0992d95e5cc688f6d36314e4b3.png" width="30" height="30">
You have to setup settings of panels before start on click on this icon <img src="https://i.gyazo.com/53480d0992d95e5cc688f6d36314e4b3.png" width="25" height="25">

To get an API key you have to :
 - To use **"Convert"** panel :
	 - Go on this [website](https://account.api2convert.com/user/apikeys) and create your account
	 - After that *Copy/Past* [your API Key](https://account.api2convert.com/user/apikeys) in the placeholder
	 - You can choose the extension of the file to convert, the extension to convert into and where you download it
 - To use **"Text To Speech"** panel :
	 - Go on this [website](https://www.voicerss.org/personel) and create your account
	 - After that *Copy/Past* [your API Key](https://www.voicerss.org/personel) in the placeholder
	 - You can choose the extensionof the file to download and where you download it
	 - The language use to say your text and the voice
	 

## How to use
### Convert panel
You can **"Refresh"** the list of found recursivly files, **"Select"** the multiple files and click to **"Convert x files"** to convert all selected files. Or just **double click** on the file in the list to **convert direclty** with settings setup.
![](https://i.gyazo.com/663aaf261f7887dccc7c78f6f0c77aca.png)

### Text to Speech panel
You can write what you want in the placeholder front of **"Text to speech"** (Max size : 1955)
And after that click to **"Send"** to download your text to speech file with settings setup.

![](https://i.gyazo.com/fbb3e7a7cc19aff8d91c6d15662fbfbb.png)

## Legal info
Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
