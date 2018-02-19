##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=spoj
ConfigurationName      :=Debug
WorkspacePath          :=/home/ravishankar/Documents/C++
ProjectPath            :=/home/ravishankar/c++/spoj/spoj
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ravishankar
Date                   :=30/12/17
CodeLitePath           :=/home/ravishankar/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="spoj.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_HORRIBLE.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_PRIME1.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_SPCO.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ravishankar/c++/spoj/spoj/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/up_HORRIBLE.cpp$(ObjectSuffix): ../HORRIBLE.cpp $(IntermediateDirectory)/up_HORRIBLE.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ravishankar/c++/spoj/HORRIBLE.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_HORRIBLE.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_HORRIBLE.cpp$(DependSuffix): ../HORRIBLE.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_HORRIBLE.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_HORRIBLE.cpp$(DependSuffix) -MM ../HORRIBLE.cpp

$(IntermediateDirectory)/up_HORRIBLE.cpp$(PreprocessSuffix): ../HORRIBLE.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_HORRIBLE.cpp$(PreprocessSuffix) ../HORRIBLE.cpp

$(IntermediateDirectory)/up_PRIME1.cpp$(ObjectSuffix): ../PRIME1.cpp $(IntermediateDirectory)/up_PRIME1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ravishankar/c++/spoj/PRIME1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_PRIME1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_PRIME1.cpp$(DependSuffix): ../PRIME1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_PRIME1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_PRIME1.cpp$(DependSuffix) -MM ../PRIME1.cpp

$(IntermediateDirectory)/up_PRIME1.cpp$(PreprocessSuffix): ../PRIME1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_PRIME1.cpp$(PreprocessSuffix) ../PRIME1.cpp

$(IntermediateDirectory)/up_SPCO.cpp$(ObjectSuffix): ../SPCO.cpp $(IntermediateDirectory)/up_SPCO.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ravishankar/c++/spoj/SPCO.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_SPCO.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_SPCO.cpp$(DependSuffix): ../SPCO.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_SPCO.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_SPCO.cpp$(DependSuffix) -MM ../SPCO.cpp

$(IntermediateDirectory)/up_SPCO.cpp$(PreprocessSuffix): ../SPCO.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_SPCO.cpp$(PreprocessSuffix) ../SPCO.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


