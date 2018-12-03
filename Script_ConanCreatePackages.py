import TM_CommonPy as TM
import sys
# Settings
bPause = True

try:
    TM.Run("conan config install https://github.com/Troy1010/TM_ConanConfig.git")
    TM.Run("conan create conanfile.py Troy1010/beta -pr conanprofile_OBSEPlugin")
    TM.Run("conan create conanfile_Source.py Troy1010/beta_source -pr conanprofile_OBSEPlugin")
except Exception as e:
    TM.DisplayException(e)
    sys.exit(1)
if bPause:
    TM.DisplayDone()
