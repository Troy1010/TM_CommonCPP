##region Settings
bPause = True
sProjDll = "TM_CommonCPP/TM_CommonCPP.vcxproj"
sLogTestsProj = "TM_CommonCPP_LogTests/TM_CommonCPP_LogTests.vcxproj"
sProjStaticLib = "TM_CommonCPP/TM_CommonCPP_Lib.vcxproj"
##endregion
##region Imports
import os, sys
import TM_CommonPy as TM
import VisualStudioAutomation as VS
##endregion

def QueActions(vCommandSet):
    #---TMDefaultSettings
    for sProj_ in (sProjDll,sLogTestsProj,sProjStaticLib):
        vCommandSet.Que((VS.SetTMDefaultVSSettings.Do,VS.SetTMDefaultVSSettings.Undo),sProj_)
    #---Integrate Conan-installed packages
    for sProj_ in (sProjDll,sLogTestsProj,sProjStaticLib):
        for sRoot in TM.GetDependencyRoots("conanbuildinfo.txt"):
            sPossibleRecommendedIntegrationPath = os.path.join(sRoot,"RecommendedIntegration.py")
            if os.path.isfile(sPossibleRecommendedIntegrationPath):
                vCommandSet.QueScript(sPossibleRecommendedIntegrationPath,[sRoot,sProj_,sSln])
        vCommandSet.Que([VS.IntegrateProps,VS.IntegrateProps_Undo],[sProj_,"conanbuildinfo.props"])

try:
    TM.Run("conan install . -pr conanprofile_OBSEPlugin")
    vCommandSet = TM.CommandSet.TryLoad()
    QueActions(vCommandSet)
    print("Executing CommandSet..")
    vCommandSet.Execute(bRedo=True)
    vCommandSet.Save()
except Exception as e:
    TM.DisplayException(e)
    sys.exit(1)
if bPause:
    TM.DisplayDone()
