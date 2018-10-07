import VisualStudioAutomation as VS
import os

def Do(sRoot,sProj,sSln):
    with VS.DTEWrapper() as vDTEWrapper:
        with vDTEWrapper.OpenSln(sSln):
            with vDTEWrapper.OpenProj(sProj) as vProjWrapper:
                with vDTEWrapper.OpenProj(os.path.join(sRoot,"TM_CommonCPP/TM_CommonCPP.vcxproj")) as vProjectWrapperToReference:
                    vProjWrapper.AddProjRef(vProjectWrapperToReference.vProj)

def Undo(sRoot,sProj,sSln):
    with VS.DTEWrapper() as vDTEWrapper:
        with vDTEWrapper.OpenSln(sSln) as vSlnWrapper:
            with vDTEWrapper.OpenProj(sProj) as vProjWrapper:
                with vDTEWrapper.OpenProj(os.path.join(sRoot,"TM_CommonCPP/TM_CommonCPP.vcxproj")) as vProjectWrapperToUnreference:
                    vProjWrapper.RemoveProjRef(vProjectWrapperToUnreference.vProj)
            vSlnWrapper.RemoveProj(os.path.join(sRoot,"TM_CommonCPP/TM_CommonCPP.vcxproj"))
