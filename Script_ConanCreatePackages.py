##region Settings
bPause = True
##endregion
import os, sys
import TM_CommonPy as TM

try:
    TM.Run("conan create . Troy1010/beta -pr conanprofile_OBSEPlugin_Lib")
    TM.Run("conan create . Troy1010/beta_source -pr conanprofile_OBSEPlugin_Source")
except Exception as e:
    TM.DisplayException(e)
    sys.exit(1)
if bPause:
    TM.DisplayDone()
